#pragma once
#include "GraphicObjects.h"

class Node
{
public:
    
    GraphicObjects graphic_obj;
    Node* next;
    Node* previous;
    
    Node();
    Node(GraphicObjects data);

};

