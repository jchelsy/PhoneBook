#include "HashMapTable.h"

using namespace std;


// Resizing the hash table only requires you to modify the global 'T_S' variable???


HashMapTable::HashMapTable()
{  // Constructor
	ht = new HashTableEntry * [T_S];  // Initialize array

	// Initialize each position as NULL (so each index EXISTS)
	for (int i = 0; i < T_S; i++)
		ht[i] = NULL;
}


int HashMapTable::HashFunc(int key)
{
	return key % T_S;
}

// Insert a value into the correct position in the Hash Table
// If the position is already taken, it will advance through the Linked List, to result as the last record in the Linked List
void HashMapTable::Insert(int k, string v)
{
	int hash_v = HashFunc(k);  // get index position in the Hash Table

	HashTableEntry* p = NULL;  // previous  (initialized NULL - undetermined if there IS a previous)
	HashTableEntry* en = ht[hash_v];  // current entry

	while (en != NULL) {
		p = en;
		en = en->n;
	}
	if (en == NULL) {
		en = new HashTableEntry(k, v);
		if (p == NULL)
			ht[hash_v] = en;  // current position in Hash Table set to new entry
		else
			p->n = en;  // otherwise, the next item is set to new entry
	}
	else
		en->v = v;  // otherwise, entry value is set to the parameter value
}


void HashMapTable::Retrieve(int k)
{
	int hash_v = HashFunc(k);  // hash the key value
	bool flag = false;

	HashTableEntry* en = ht[hash_v];
	if (en != NULL) {
		while (en != NULL) {
			if (en->k == k)
				flag = true;
			if (flag) {
				cout << "\nFound: " << en->v;
				cout << " (" << k << ")" << endl;
//				cout << "Found: " << k << "  : ";
//				cout << en->v << endl;
			}
			en = en->n;  // advance to the next value in the chain
		}
	}
	if (!flag)
		cout << "\nFailure! Unable to find a result from: " << k << endl;
}


// Destructor (prevent memory leak!)
HashMapTable::~HashMapTable()
{
	delete[] ht;
}