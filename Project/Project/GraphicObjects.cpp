#include "GraphicObjects.h"

std::string GraphicObjects::GetType() const
{
    return g_type;
}

std::string GraphicObjects::GetName() const
{
    return g_name;
}

ObjectProperties GraphicObjects::GetProperties()
{
    return g_properties;
}

GraphicObjects::GraphicObjects(std::string type, std::string name, ObjectProperties properties):
    g_type(type),g_name(name),g_properties(properties)
{
}

GraphicObjects::GraphicObjects()
{
}

std::ostream& operator<<(std::ostream& out, const GraphicObjects& graphic_obj)
{
    return out <<
        static_cast<std::string>(graphic_obj.g_type) <<
        static_cast<std::string>(graphic_obj.g_name) <<
        static_cast<std::string>(graphic_obj.g_properties.GetProperty()) <<
        static_cast<std::string>(graphic_obj.g_properties.GetValue());
}

