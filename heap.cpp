#include "heap.h"

//Overload operators for use in other algorithms

inline bool operator<=(pJob a, pJob b)
{
	return (a.priority <= b.priority && a.jobNumber > b.jobNumber);
}

inline bool operator<(pJob a, pJob b)
{
	return (a.priority < b.priority);
}

void HeapType::ReheapDown(int root, int bottom)
{
	//Variables needed for algorithm
	int maxChild;
	int rightChild;
	int leftChild;

	//Set left and right child indexes
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		//Determine max child
		if (leftChild == bottom)	
		{
			maxChild = leftChild;	
		}
		else
		{
			if (elements[leftChild] <= elements[rightChild])
			{
				maxChild = rightChild;
			}
			else
			{
				maxChild = leftChild;
			}
		}
		if (elements[root] < elements[maxChild])	//If child is greater than parent
		{
			swap(elements[root], elements[maxChild]);	//Swap 
			ReheapDown(maxChild, bottom);	//Recursive call to restore order
		}
	}
}

void HeapType::ReheapUp(int root, int bottom)
{
	int parent;	//Needed for algorithm
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;	//Get middle index
		if (elements[parent] < elements[bottom])
		{
			swap(elements[parent], elements[bottom]);	//Swap position of items
			ReheapUp(root, parent);	//Recursive call to restore order
		}
	}
}

void HeapType::swap(ItemType &f, ItemType &s)
{
	ItemType temp = f;	//Save first item
	f = s;	//Copy second item into first
	s = temp;	//Copy saved item into second
}
