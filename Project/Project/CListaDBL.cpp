#include "CListaDBL.h"
#include <fstream>
#include <iostream>
#include <string>

CListaDBL::CListaDBL():
	head(nullptr),tail(nullptr)
{
}

CListaDBL::CListaDBL(Node* node):
	head(node)
{
}


CListaDBL::~CListaDBL()
{
	Node* tmp = nullptr;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
	head = nullptr;
}

void CListaDBL::insertObject(GraphicObjects graphicObj)
{
	if (head->graphic_obj.GetType()[0] > graphicObj.GetType()[0])
		insertNodeAtHead(graphicObj);

	if (head->graphic_obj.GetType()[0] == graphicObj.GetType()[0])
	{
		
		if (verifyName(head->graphic_obj.GetName(), graphicObj.GetName())!=0)
			insertNodeAtHead(graphicObj);
		else
		{
			Node* node = new Node();
			node = head->next;
			while (node != nullptr && node->graphic_obj.GetType() == graphicObj.GetType())
			{  
				if (verifyName(node->graphic_obj.GetName(), graphicObj.GetName()) != 0)
					break;
				node = node->next;
			}
			node = node->previous;
			insertAfterGivenNode(node, graphicObj);
		}

		if (head->graphic_obj.GetType() != graphicObj.GetType())
		{
			Node* node = new Node();
			node = searchNode(graphicObj);
			insertAfterGivenNode(node,graphicObj);
		}
	}
}

void CListaDBL::deleteObject(std::string objectName)
{
	Node* nodeToDelete = new Node();
	nodeToDelete = searchNodeToDelete(objectName);
	Node* tmp = head;

	if (head == nullptr || nodeToDelete == nullptr)
		return;

	if (head == nodeToDelete)
		head = tmp->next;
	else {
		while (nodeToDelete != nullptr)
		{
			if (tmp->next == nodeToDelete)
			{
				tmp->next = nodeToDelete->next;
				nodeToDelete->next->previous = tmp;
				delete nodeToDelete;
				return;
			}
			tmp = tmp->next;

		}
	}

	

	
}

void CListaDBL::insertNodeAtHead(GraphicObjects graphicObj)
{
	Node* node = new Node(graphicObj);

	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head = node;
		node->next->previous = node;
	}

	/*node->graphic_obj = graphicObj;
	node->next = head;
	node->previous = nullptr;

	if (head != nullptr) 
		head->previous = node;
	
	head = node;*/
}

void CListaDBL::insertAfterGivenNode(Node*& node_ref, GraphicObjects graphicObj)
{
	if (node_ref == nullptr)
		return;

	Node* node = new Node(graphicObj);

	node->next =node_ref->next;
	node_ref->next = node;
	node->previous = node_ref;
	if (node->next != nullptr)
		node->next->previous = node;
}


Node* CListaDBL::searchNode(GraphicObjects obj)
{
	Node* node = new Node();
	node = head->next;

	while (node != nullptr)
	{ 
		if(node->graphic_obj.GetType()[0] == obj.GetType()[0])
			if (verifyName(node->graphic_obj.GetName(), obj.GetName()) != 0)
				break;
			
		if (node->graphic_obj.GetType()[0] > obj.GetType()[0])
			break;

		node = node->next;
	}
	node = node->previous;
	return node;
}

Node* CListaDBL::searchNodeToDelete(std::string objectName)
{
	
	Node* node = new Node();
	node = head;

	while (node!=nullptr)
	{
		if (node->graphic_obj.GetName() == objectName)
			break;
		node = node->next;
		
	}
	return node;
}

void CListaDBL::print(std::string fileName)
{
	Node* node = new Node();
	node = head;

	std::ofstream out;
	out.open(fileName);

	while (node!=nullptr)
	{
		out << node->graphic_obj;
		node = node->next;
	}

	out.close();
	delete node;
}

int CListaDBL::verifyName(std::string name1, std::string name2)
{
	std::size_t pos1 = name1.find("_");
	std::size_t pos2 = name2.find("_");
	
	int num1 = stoi(name1.substr(pos1 + 1));
	int num2 = stoi(name2.substr(pos2 + 1));

	if (num1 > num2)
		return 1;
	
	return 0;
}


