#include<iostream>
#include<string>
#include "nodestd.h"
#include "nodecls.h"

using namespace std;
void main()
{
	nodecls *start = NULL;
	nodecls Class;
	Class.insert_cls("A1", &start);
	Class.insert_cls("A2", &start);
	Class.insert_cls("A3", &start);
	Class.search_cls("A3", &start);
	Class.del_cls("A1", &start);
	Class.print_cls(start);
	int choice;
	cout << "Enter 1 for class insertion and 2 for student insertion" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		
		Class.insert_cls("A1", &start);
		break;
	case 2:
		cout << "Enter class in which you wish add student" << endl;
		char ClassToSer[5];
		cin >> ClassToSer;
		//nodecls Class;
		nodecls *ser;
		ser = Class.search_cls(ClassToSer, &start);
		if (ser == NULL)
		{
			cout << "Class not found" << endl;
		}
		else
		{
			nodestd Stu;
			Stu.insert_std("Raza", "A110", 3.8, &(ser)->head);
			Stu.insert_std("Joey", "A111", 3.5, &(ser)->head);
		}
		break;
	default:
		cout << "Input Error" << endl;
	}
	cout << endl;
	cout << "Printing all classes and students" << endl;
	Class.print_all(start);
	/*nodestd SL;
	SL.setSeat("AB112");
	cout << SL.getSeat() << endl;
	SL.insert_std("Raza", "Abg", 3.0,&head);
	SL.insert_std("Hur", "A111", 2.8, &head);
	SL.insert_std("Joey", "A112", 3.4, &head);
	SL.insert_std("Chandler", "A113", 3.5, &head);
	SL.print_std(head);
	SL.search_std("Abg", &head);
	SL.del_std("Abg", &head);
	SL.print_std(head);*/
	system("pause");
}