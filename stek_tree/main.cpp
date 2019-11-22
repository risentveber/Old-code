#include <iostream>

typedef int data;

#include "Binary_tree.h"
#include "Queue.h"


using namespace std;

int main()
{
	tree_element* head = create(10);
	insert(head, 50);
	insert(head, 34);
	insert(head, 4);
	insert(head, 1);
	insert(head, 7);
	int f = NULL;
	f = (int)find(head, 5);
	f = (int)find(head, 1);
	remove_item(head, 10);
	f = (int)find(head, 1);
	printer(head);
	clear(head);
}
