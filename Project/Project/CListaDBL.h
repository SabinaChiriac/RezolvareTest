#pragma once
#include <iostream>
#include "GraphicObjects.h"
#include "Node.h"
#include <fstream>
#include <string>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>

class CListaDBL
{
private:
	Node *head,*tail;
	/*friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& head;
	}*/

public:
	CListaDBL();
	CListaDBL(Node* node);
	~CListaDBL();
	void insertObject(GraphicObjects graphicObj);
	void deleteObject(std::string objectName);

	void insertNodeAtHead(GraphicObjects graphicObj);
	void insertAfterGivenNode(Node*& node_ref, GraphicObjects graphicObj);
	
	Node* searchNode(GraphicObjects obj);
	Node* searchNodeToDelete(std::string objectName);

	void print(std::string fileName);
	
	int verifyName(std::string name1, std::string name2);
};

