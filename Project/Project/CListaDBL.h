#pragma once
#include <iostream>
#include "GraphicObjects.h"
#include "Node.h"
#include <fstream>
#include <iostream>

class CListaDBL
{
private:
	Node *head;

public:
	CListaDBL();
	CListaDBL(Node* node);

	void insertObject(GraphicObjects graphicObj);
	void deleteObject(std::string objectName);

	void insertNodeAtHead(Node*& head_ref, GraphicObjects graphicObj);
	void insertAfterGivenNode(Node*& node_ref, GraphicObjects graphicObj);
	
	Node* searchNode(GraphicObjects obj);
	Node* searchNodeToDelete(std::string objectName);

	void print();
};

