#include "GraphicObjects.h"

std::string GraphicObjects::GetType() const
{
    return type;
}

std::string GraphicObjects::GetName() const
{
    return name;
}

ObjectProperties GraphicObjects::GetProperties()
{
    return properties;
}

GraphicObjects::GraphicObjects(const std::string& type,const std::string& name,const ObjectProperties& properties):
    type(type),name(name),properties(properties)
{
}

GraphicObjects::GraphicObjects()
{
}


std::ostream& operator<<(std::ostream& out, const GraphicObjects& graphic_obj)
{
    return out <<
        static_cast<std::string>(graphic_obj.type) <<
        static_cast<std::string>(graphic_obj.name) <<
        static_cast<std::string>(graphic_obj.properties.GetProperty()) <<
        static_cast<std::string>(graphic_obj.properties.GetValue());
}

