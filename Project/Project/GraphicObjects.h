#pragma once
#include <iostream>
#include "ObjectProperties.h"

class GraphicObjects
{
private:
	
	std::string g_type;
	std::string g_name;
	ObjectProperties g_properties;

public:

	std::string GetType() const;
    std::string GetName() const;
	ObjectProperties GetProperties();

	GraphicObjects(std::string type, std::string name, ObjectProperties properties);
	GraphicObjects();

	friend std::ostream& operator << (std::ostream& out, const GraphicObjects& graphic_obj);

};

