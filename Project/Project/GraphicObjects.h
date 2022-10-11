#pragma once
#include <iostream>
#include "ObjectProperties.h"

class GraphicObjects
{
private:
	
	std::string type;
	std::string name;
	ObjectProperties properties;

public:

	std::string GetType() const;
    std::string GetName() const;
	ObjectProperties GetProperties();

	GraphicObjects(const std::string& type, const std::string& name, const ObjectProperties& properties);
	GraphicObjects();
	friend std::ostream& operator << (std::ostream& out, const GraphicObjects& graphic_obj);

};

