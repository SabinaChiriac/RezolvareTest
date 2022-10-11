#pragma once
#include <iostream>

class ObjectProperties
{
private:

	std::string property;
	std::string value;
public: 

	std::string GetProperty() const;
	std::string GetValue() const;
	ObjectProperties(const std::string& property,const std::string& value);
	ObjectProperties();

};

