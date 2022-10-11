#include "ObjectProperties.h"

std::string ObjectProperties::GetProperty() const
{
	return property;
}

std::string ObjectProperties::GetValue() const
{
	return value;
}

ObjectProperties::ObjectProperties(const std::string& property,const std::string& value): 
	property(property),value(value)
{
}

ObjectProperties::ObjectProperties()
{
}

