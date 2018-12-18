#include "pqtype.h"

pqtype::pqtype(int max)	
{
	maxItems = max;	//Set max length of queue
	items.elements = new ItemType[maxItems];	//Dynamically allocate memory for queue
	length = 0;	//Set initial length
}

pqtype::pqtype(const pqtype& cpy)	//Copy constructor
{
	length = cpy.length;	//Copy length

	items.elements = new ItemType[cpy.maxItems];	//Allocate memory 

	for (int i = 0; i < length; i++)	//Copy elements
	{
		items.elements[i] = cpy.items.elements[i];
	}
}

pqtype::~pqtype()
{
	delete[] items.elements;	//Deallocate memory
}


 bool pqtype::isEmpty() const
{
	return length == 0;	//Return true if queue is empty
}

bool pqtype::isFull() const
{
	return length == (maxItems - 1);	//Return true if queue is full
}

void pqtype::Enqueue(ItemType newItem)
{
	if (isFull())	//If queue is full, display message
		cout << "Queue is full\n";
	else		//If space in queue
	{
		length++;	//Increase count
		items.elements[length - 1] = newItem;	//Save content
		items.ReheapUp(0, length - 1);	//ReheapUp
	}
}

void pqtype::Dequeue(ItemType & item)
{
	if (isEmpty())	//If queue is empty, display message
		cout << "Queue is empty";
	else		//If queue has items
	{
		item = items.elements[0];	//Save front of queue
		items.elements[0] = items.elements[length - 1];	//Set new front of queue
		length--;	//Decrease length
		items.ReheapDown(0, length - 1);	//ReheapDown
	}
}

int pqtype::getLength() const
{
	return length;	//Return current length of queue
}
