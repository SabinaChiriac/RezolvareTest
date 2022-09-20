#include "CListaDBL.h"
#include <fstream>
#include <iostream>

CListaDBL::CListaDBL()
{
	head = NULL;
}

CListaDBL::CListaDBL(Node* node):
	head(node)
{
}

void CListaDBL::insertObject(GraphicObjects graphicObj)
{
	if (head->graphic_obj.GetType()[0] > graphicObj.GetType()[0])
		insertNodeAtHead(head, graphicObj);

	if (head->graphic_obj.GetType()[0] == graphicObj.GetType()[0])
	{
		if (head->graphic_obj.GetName().back() > graphicObj.GetName().back())
			insertNodeAtHead(head, graphicObj);
		else
		{
			Node* node = new Node();
			node = head->next;
			while (node != NULL && node->graphic_obj.GetType() == graphicObj.GetType())
			{
				if (node->graphic_obj.GetName().back() > graphicObj.GetName().back())
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

	if (head == NULL || nodeToDelete == NULL)
		return;

	if (head == nodeToDelete)
		head = nodeToDelete->next;

	if (nodeToDelete->next != NULL)
		nodeToDelete->next->previous = nodeToDelete->previous;

	if (nodeToDelete->previous != NULL)
		nodeToDelete->previous->next = nodeToDelete->next;

	free(nodeToDelete);
}

void CListaDBL::insertNodeAtHead(Node*& head_ref, GraphicObjects graphicObj)
{
	Node* node = new Node(graphicObj);
	node->next = head;

	if (head != NULL) {
		head->previous = node;
	}

	head = node;
}

void CListaDBL::insertAfterGivenNode(Node*& node_ref, GraphicObjects graphicObj)
{
	if (node_ref == NULL)
		return;

	Node* node = new Node(graphicObj);

	node->next =node_ref->next;
	node_ref->next = node;
	node->previous = node_ref;
	if (node->next != NULL)
		node->next->previous = node;
}


Node* CListaDBL::searchNode(GraphicObjects obj)
{
	Node* node = new Node();
	node = head->next;

	while (node != NULL)
	{
		if(node->graphic_obj.GetType()[0] == obj.GetType()[0])
			if (node->graphic_obj.GetName().back() > obj.GetName().back())
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

	while (node!=NULL)
	{
		if (node->graphic_obj.GetName() == objectName)
			break;
		node = node->next;
		
	}
	return node;
}

void CListaDBL::print()
{
	Node* node = new Node();
	node = head;

	std::ofstream out;
	out.open("lista.txt");

	while (node!=NULL)
	{
		out << node->graphic_obj;
		node = node->next;
	}

	out.close();
	free(node);
}


