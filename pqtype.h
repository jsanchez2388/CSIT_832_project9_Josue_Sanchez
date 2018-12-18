#pragma once

#include "heap.h"

typedef pJob ItemType;

class pqtype
{
public:
	pqtype(int);
	pqtype(const pqtype& cpy);
	~pqtype();
	bool isEmpty() const;
	bool isFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	int getLength() const;
private:
	int length;
	HeapType items;
	int maxItems;
};
