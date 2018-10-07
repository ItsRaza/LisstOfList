#include<iostream>
#include<string>
#pragma once
using namespace std;

class nodestd
{
private:
	char name[10];
	char seat[10];
	float gpa;
	int count;
	nodestd *next;
public:
	nodestd()
	{
		//this->name = "";
		//this->seat = "";
		this->gpa = 0;
	}
	int getCount()
	{
		return this->count;
	}
	char* getName()
	{
		return this->name;
	}
	char* getSeat()
	{
		return this->seat;
	}
	float getGpa()
	{
		return this->gpa;
	}
	void setSeat(char* seat_in)
	{
		strcpy_s(seat, seat_in);
	}
	void setName(char* name_in)
	{
		strcpy_s(name, name_in);
	}
	void insert_std(char* name_in, char* seat_in, float gpa_in, nodestd **head)
	{
		nodestd *ptr; 
		ptr = (nodestd*)malloc(sizeof(nodestd));
		ptr->setName(name_in);
		ptr->setSeat(seat_in);
		ptr->gpa = gpa_in;
		ptr->next = NULL;
		if (*head == NULL)
		{
			*head = ptr;
			cout << "Student list created and student " << name_in << " is added to list" << endl;
			count++;
		}
		else
		{
			nodestd *curr = *head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = ptr;
			cout << "Student " << name_in << " is added to list" << endl;
			count++;
		}
	}
	void print_std(nodestd *head)
	{
		if (head == NULL)
		{
			cout << "No students Exists in the list" << endl;
		}
		else
		{
			nodestd *curr = head;
			while (curr->next != NULL)
			{
				cout << "Name:" << curr->getName() << endl;
				cout << "Seat No:" <<curr->getSeat() << endl;
				cout << "GPA:" << curr->gpa << endl << endl;
				curr = curr->next;
			}
			cout << "Name:" << curr->getName() << endl;
			cout << "Seat No:" << curr->getSeat() << endl;
			cout << "GPA:" << curr->gpa << endl << endl;
		}
	}
	void search_std(char* seat_in, nodestd **head)
	{
		if (*head == NULL)
		{
			cout << "No student exist in the list" << endl;
		}
		else
		{
			int flag = 0;
			nodestd *curr = *head;
			while (curr->next != NULL)
			{
				if (strcmp(curr->seat,seat_in)==0)
				{
					cout << "Student with Seat No:" << seat_in << " found" << endl;
					flag++;
					break;
				}
				curr = curr->next;
			}
			if ((curr->next == NULL) && strcmp(curr->seat, seat_in) == 0)
			{
				cout << "Student with Seat No:" << seat_in << " found" << endl;
				flag++;
			}
			if (flag == 0)
			{
				cout << "Student with Seat No:" << seat_in << " NOT found" << endl;
			}
		}
	}
	void del_std(char* seat_in, nodestd **head)
	{
		if (*head == NULL)
		{
			cout << "No Student exist in list" << endl;
			return;
		}
		nodestd *curr = *head;
		int flag = 0;
		if (strcmp((*head)->seat,seat_in)==0)
		{
			*head = (*head)->next;
			free(curr);
			flag++;
			cout << "Student with Seat No:" << seat_in << " has been removed" << endl;
			return;
		}
		else
		{
			curr = (*head)->next;
			nodestd *pre = *head;
			while (strcmp(curr->seat,seat_in)!=0)
			{
				if (curr->next == NULL)
				{
					if (flag == 0)
					{
						cout << "Student with Seat No :" << seat_in << " Not found!" << endl;
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
			cout << "Student with Seat No:" << seat_in << " has been removed" << endl;
			return;
		}
	}
};