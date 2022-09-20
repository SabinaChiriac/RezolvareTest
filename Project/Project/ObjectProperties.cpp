#include "ObjectProperties.h"

std::string ObjectProperties::GetProperty() const
{
	return o_property;
}

std::string ObjectProperties::GetValue() const
{
	return o_value;
}

ObjectProperties::ObjectProperties(std::string property, std::string value): 
	o_property(property),o_value(value)
{
}

ObjectProperties::ObjectProperties()
{
}
