#include "Node.h"


Node::Node()
{
}

Node::Node(GraphicObjects data):
    graphic_obj(data),next(nullptr),previous(nullptr)
{
}
