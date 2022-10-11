#include <iostream>
#include "CListaDBL.h"

int main()
{
	CListaDBL list;
	GraphicObjects graphicObj={ "Circle", "Circle_1", { "radius", "20" } };

	list.insertObject(graphicObj);
	GraphicObjects graphicObj1 = { "Circle", "Circle_2", { "radius", "40" } };
	list.insertObject(graphicObj1);
	list.insertObject({ "Line","Line_1",{"length:","10"} });
	

	list.print("original_list.txt");

	//int option;

	//std::cin >> option;
	//do
	//{
	//	std::cout << "Type '1' to insert a new object into the list.";
	//	std::cout << "Type '2' to delete an object from the the list.";
	//	std::cout << "Type '0' to stop.";
	//	std::cin >> option;
	//	
	//	switch (option)
	//	{
	//	case 1: {
	//		
	//		GraphicObjects obj;
	//		
	//		list.insertObject(obj);
	//		list.print("insert_list.txt");
	//		break;
	//	}
	//	case 2: {
	//		
	//		std::string objName;
	//		std::cin >> objName;
	//
	//		list.deleteObject(objName);
	//		list.print("delete_list.txt");
	//		break;
	//	}
	//	case 0: break;

	//	default:
	//		std::cout << "Enter proper option number " << std::endl;
	//	}

	//} while (option != 0);
}