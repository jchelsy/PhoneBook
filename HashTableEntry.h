#pragma once
#include <iostream>
#include <string>

using namespace std;


struct HashTableEntry
{
	int k;  // phone number (key)
	string v;  // name (value)

	HashTableEntry* n;  // 'next' pointer (for chaining)

	HashTableEntry(int k, string v) {
		this->k = k;
		this->v = v;
		this->n = NULL;  // The 1st entry has no 'next' (so it is set to NULL)
	}
};