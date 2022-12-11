#pragma once
#include "HashTableEntry.h"

using namespace std;

// constant global variable
const int T_S = 200;  // table size


class HashMapTable
{
public:
	HashTableEntry** ht, ** top;
	HashMapTable();  // Constructor

	int HashFunc(int key);  // Hash Function

	void Insert(int k, string v);
	void Retrieve(int k);

	~HashMapTable();  // Destructor
};

// possibly go back to make variables not ALL public? (private/protected)