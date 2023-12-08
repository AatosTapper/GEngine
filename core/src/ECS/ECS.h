#pragma once

#include "../Util/Util.h"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <any>
#include <typeindex>

using Entity = uint32_t;

namespace geng
{
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

        Entity add_entity()
        {
            return m_last_entity_index++;
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

            m_entity_indices[entity][component_type_hash] = component_array.size() - 1;
        }

        template <typename T>
        T& get_component(Entity entity) 
        {
            const size_t component_type_hash = typeid(T).hash_code();

            if (m_entity_indices.find(entity) == m_entity_indices.end() 
                || m_entity_indices[entity].find(component_type_hash) == m_entity_indices[entity].end()) 
            {
                ERR("Component not found for the specified entity: " << entity << "and type: " << typeid(T).name());
            }

            size_t index = m_entity_indices[entity][component_type_hash];
            return dynamic_cast<ComponentArray<T>&>(*m_components[component_type_hash]).data[index];
        }

        template <typename T>
        std::vector<T> *get_all_components() const 
        {
            const size_t component_type_hash = typeid(T).hash_code();

            if (m_components.find(component_type_hash) == m_components.end()) 
            {
                ERR("Component type not found: " << typeid(T).name());
            }

            return &dynamic_cast<ComponentArray<T>&>(*m_components.at(component_type_hash)).data;
        }

        template <typename T>
        void remove_component(Entity entity) 
        {
            const size_t component_type_hash = typeid(T).hash_code();

            if (m_entity_indices.find(entity) != m_entity_indices.end() &&
                m_entity_indices[entity].find(component_type_hash) != m_entity_indices[entity].end()) 
            {
                const size_t index = m_entity_indices[entity][component_type_hash];

                auto& component_array = dynamic_cast<ComponentArray<T>&>(*m_components[component_type_hash]).data;
                component_array.erase(component_array.begin() + index);

                m_entity_indices[entity].erase(component_type_hash);

                if (component_array.empty()) 
                {
                    m_components.erase(component_type_hash);
                }
            }
        }

        void remove_entity(Entity entity) 
        {
            if (m_entity_indices.find(entity) != m_entity_indices.end()) 
            {
                for (const auto& entry : m_entity_indices[entity]) 
                {
                    const size_t component_type_hash = entry.first;
                    const size_t index = entry.second;

                    auto& component_array = dynamic_cast<ComponentArray<BaseComponent>&>(*m_components[component_type_hash]).data;
                    component_array.erase(component_array.begin() + index);
                }

                m_entity_indices.erase(entity);
            }
        }

    private:
        std::unordered_map<size_t, std::unique_ptr<BaseComponent>> m_components;
        std::unordered_map<uint32_t, std::unordered_map<size_t, size_t>> m_entity_indices;

        Entity m_last_entity_index;
    };
}