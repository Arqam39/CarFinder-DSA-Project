#ifndef hash_H
#define hash_H
#include <iostream>
#include<string>
#include"SLL.h"
//#include"classes_nodes.h"
using namespace std;
#define SIZE 100

template <typename T>
class HashNode {
public:
	SLL<int> list;
};

class HashTable {
public:
	HashNode<int> hash_array[SIZE];

	int getkey(int a)
	{
		return (a % SIZE);
	}

	void Insert(int model_year,int index)
	{
		int k = getkey(model_year);
		hash_array[k].list.insertAtEnd(index);
	}

};



#endif
