#pragma once
#include <iostream>

class ObjectProperties
{
private:

	std::string o_property;
	std::string o_value;
public: 

	std::string GetProperty() const;
	std::string GetValue() const;
	ObjectProperties(std::string property, std::string value);
	ObjectProperties();

};

