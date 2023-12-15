#pragma once

#include "../Util/Util.h"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <any>
#include <typeindex>

namespace geng
{
    // Type can be some user defined enum for example.
    // It can't be changed afterwards.
    struct Entity
    {
        uint32_t id;
        uint32_t type; 
    };

    class BaseComponent 
    {
    public:
        virtual ~BaseComponent() = default;
    };
    
    template <typename T>
    class ComponentArray : public BaseComponent 
    {
    public:
        std::vector<T> data;
    };

    class ECManager 
    {
    public:
        ECManager() : m_last_entity_index(0) {}

        Entity add_entity(uint32_t type = 0)
        {
            const Entity new_entity = Entity{ m_last_entity_index++, type };
            m_entities.push_back(new_entity);
            return new_entity;
        }

        template <typename T>
        void add_component(Entity entity, T component) 
        {
            const size_t component_type_hash = typeid(T).hash_code();
            if (m_components.find(component_type_hash) == m_components.end()) 
            {
                m_components[component_type_hash] = std::make_unique<ComponentArray<T>>();
            }
            auto& component_array = dynamic_cast<ComponentArray<T>&>(*m_components[component_type_hash]).data;
            component_array.push_back(component);
            m_entity_indices[entity.id][component_type_hash] = component_array.size() - 1;
        }

        template <typename T>
        T *get_component(Entity entity) 
        {
            const size_t component_type_hash = typeid(T).hash_code();
            if (m_entity_indices.find(entity.id) == m_entity_indices.end() 
                || m_entity_indices[entity.id].find(component_type_hash) == m_entity_indices[entity.id].end()) 
            {
                ERR("Component of type [ " << typeid(T).name() << " ] was not found for the specified entity [ " << entity.id << " ]");
                return nullptr;
            }
            size_t index = m_entity_indices[entity.id][component_type_hash];
            return &dynamic_cast<ComponentArray<T>&>(*m_components[component_type_hash]).data[index];
        }

        // Returns nullptr if no components of the type are found
        template <typename T>
        std::vector<T> *get_all_components(bool silence_warning = false) const 
        {
            const size_t component_type_hash = typeid(T).hash_code();
            if (m_components.find(component_type_hash) == m_components.end()) 
            {
                if (!silence_warning)
                    INFO("Returned a nullptr, remember to handle it.");
                return nullptr;
            }
            return &dynamic_cast<ComponentArray<T>&>(*m_components.at(component_type_hash)).data;
        }

        void remove_entity(Entity entity) 
        {
            bool has_components = false;
            if (m_entity_indices.find(entity.id) != m_entity_indices.end()) 
            {
                for (const auto& entry : m_entity_indices[entity.id]) 
                {
                    has_components = true;
                    static_cast<void>(entry);
                    break;
                }

                m_entity_indices.erase(entity.id);
            }

            int64_t deleted_entity_index = -1;
            for (int64_t i = 0; i < m_entities.size(); i++)
            {
                if (m_entities[i].id == entity.id)
                {
                    deleted_entity_index = i;
                    break;
                }
            }
            if (deleted_entity_index == -1)
            {
                WARN("Tried to delete an entity that doesn't exist.");
                return;
            }
            m_entities.erase(m_entities.begin() + deleted_entity_index);

            if (has_components)
                ERR("Removing entity doesn't automatically remove it's components. \n  Existing components detected for entity.id[" << entity.id << "]");
        }

        template <typename T>
        void remove_component(Entity entity) 
        {
            const size_t component_type_hash = typeid(T).hash_code();

            if (m_entity_indices.find(entity.id) != m_entity_indices.end() &&
                m_entity_indices[entity.id].find(component_type_hash) != m_entity_indices[entity.id].end()) 
            {
                const size_t index = m_entity_indices[entity.id][component_type_hash];

                auto& component_array = dynamic_cast<ComponentArray<T>&>(*m_components[component_type_hash]).data;
                component_array.erase(component_array.begin() + index);

                m_entity_indices[entity.id].erase(component_type_hash);

                if (component_array.empty()) 
                {
                    m_components.erase(component_type_hash);
                }
            }
            else
            {
                WARN("Tried to delete a component that doesn't exist.");
            }
        }

    private:
        std::unordered_map<size_t, std::unique_ptr<BaseComponent>> m_components;
        std::unordered_map<uint32_t, std::unordered_map<size_t, size_t>> m_entity_indices;
        std::vector<Entity> m_entities;
        uint32_t m_last_entity_index;
    };
}