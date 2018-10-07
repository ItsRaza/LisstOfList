#include<iostream>
#include<string>
#include "nodestd.h"
#pragma once

using namespace std;
class nodecls
{
private:
	char name[10];
	int Nos;
	nodecls *next;
	
public:
	nodestd *head;
	nodecls(){}
	void setName(char* name_in)
	{
		strcpy_s(name, name_in);
	}
	char* getName()
	{
		return this->name;
	}
	void insert_cls(char *name_in, nodecls **start)
	{
		nodecls *ptr;
		ptr = (nodecls*)malloc(sizeof(nodecls));
		ptr->setName(name_in);
		ptr->next = NULL;
		ptr->head = NULL;
		if (*start == NULL)
		{
			*start = ptr;
			cout << "Class list created. Name of the class is " << name_in << endl;
		}
		else
		{
			nodecls *curr = *start;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = ptr;
			cout << "New class " << name_in << " is added to class list." << endl;
		}
	}
	void print_cls(nodecls *start)
	{
		if (start == NULL)
		{
			cout << "No class exist!" << endl;
		}
		else
		{
			nodecls *curr = start;
			while (curr->next != NULL)
			{
				cout << "Class Name: " << curr->getName() << endl;
				curr = curr->next;
			}
			cout << "Class Name: " << curr->getName() << endl;
		}
	}
	nodecls* search_cls(char* name_in, nodecls **start)
	{
		if (*start == NULL)
		{
			cout << "No class exist!" << endl;
		}
		else
		{
			nodecls *curr = *start;
			int flag = 0;
			while (curr->next != NULL)
			{
				if (strcmp(curr->name, name_in) == 0)
				{
					cout << "Class " << name_in << " found" << endl;
					flag++;
					break;
				}
				curr = curr->next;
			}
			if ((curr->next == NULL) && (strcmp(curr->name, name_in) == 0))
			{
				cout << "Class " << name_in << " found" << endl;
				flag++;
			}
			if (flag > 0)
			{
				return (curr);
			}
			if (flag == 0)
			{
				cout << "Class " << name_in << " NOT found" << endl;
				return NULL;
			}
		}
	}
	void del_cls(char* name_in, nodecls **start)
	{
		if (*start == NULL)
		{
			cout << "No Class exist" << endl;
			return;
		}
		nodecls *curr = *start;
		int flag = 0;
		if (strcmp((*start)->name, name_in) == 0)
		{
			*start = (*start)->next;
			free(curr);
			flag++;
			cout << "Class " << name_in << " has been removed" << endl;
			return;
		}
		else
		{
			nodecls *pre = *start;
			curr = (*start)->next;
			while (strcmp(curr->name, name_in) != 0)
			{
				if (curr->next == NULL)
				{
					if (flag == 0)
					{
						cout << "Class " << name_in << " NOT found" << endl;
						return;
					}
					break;
				}
				curr = curr->next;
				pre = pre->next;
			}
			pre->next = curr->next;
			free(curr);
			flag++;
			cout << "Class " << name_in << " has been removed" << endl;
			return;
		}
	}
	void print_all(nodecls *start)
	{
		if (start == NULL)
		{
			cout << "No Class exist" << endl;
		}
		else
		{
			nodecls *curr = start;
			while (curr->next != NULL)
			{
				cout << "Class Name: " << curr->getName() << endl;
				(curr->head)->print_std(curr->head);
				curr = curr->next;
			}
			cout << "Class Name: " << curr->getName() << endl;
			(curr->head)->print_std(curr->head);
		}
	}
};