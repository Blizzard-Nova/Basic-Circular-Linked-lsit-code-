#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class CircularLinkedList
{
	node* Startpoint;
	node* Endpoint;
	
	void Create_Node(int val);
	void Add_Node_in_any_Position(int val, int pos);
	void Search_Node(int val);
	void Print();
	

	 
public:
	CircularLinkedList()
	{
		Startpoint = NULL;
	

	}

	void Display();
};

/////////////////////////////

void CircularLinkedList::Create_Node(int val)
{
	node* temp = new node;
	temp->data = val;
	

	if (Startpoint == NULL)
	{
		Startpoint = temp;
		Endpoint = temp;
		temp->next = Startpoint;
	
	}

	else
	{
		Endpoint->next = temp;
		Endpoint = temp;
		Endpoint->next = Startpoint;
	}
	
}

/////////////////////////////

void CircularLinkedList::Add_Node_in_any_Position(int val, int pos)
{
	int count = 0;
	node* temp = new node;
	temp = Startpoint;
	while (temp->next != Startpoint)
	{
		temp = temp->next;
		count++;
	}

	if (val > count)
	{
		cout << "Circle has only " << count << "  nodes \n";
	}

	else
	{
		node* curr = new node;
		curr =	Startpoint;
		node* prev = new node;
		prev = Startpoint;
		node* temp1=new node;
		temp1->data = val;

		while (curr->next != Startpoint)
		{
			if (pos==0)
			{
				temp1->next = Startpoint;
				Startpoint = temp1;
				return;
			}
			else if (curr->data == val)
			{
				prev->next = temp1;
				temp1->next = curr;
				return;
			}
		}
		
	}
}

/////////////////////////////

void CircularLinkedList::Print()
{
	node* temp = new node;
	temp = Startpoint;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	
		while (temp->next != Startpoint);
	cout << temp->data << " ";
		
	
	return;
}

void CircularLinkedList::Display()
{
	CircularLinkedList obj;
	obj.Create_Node(100);
	obj.Create_Node(20);
	obj.Create_Node(30);
	obj.Create_Node(40);
	obj.Create_Node(50);
	obj.Create_Node(60);
	
	obj.Print();
}
int main()
{
	CircularLinkedList cll;
	cll.Display();
	return 0;
}