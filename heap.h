#pragma once
#include <iostream>
#include <string>

using namespace std;

//Structure for Print Job
struct pJob
{
	string title;
	int jobNumber;
	int priority;
};

typedef pJob ItemType;

struct HeapType
{
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	void swap(ItemType&, ItemType&);
	ItemType* elements;
	int numElements;
};
