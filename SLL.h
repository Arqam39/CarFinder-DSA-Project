#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include<string>
//#include"classes_nodes.cpp"
using namespace std;

template<typename S>
class sll_node {
public:
	S data;
	sll_node<S>* next;
	sll_node(S d) {
		data = d;
		next = NULL;
	}
};


template <class S>
class SLL {//class for single linked list
public:
	sll_node<S>* start;
	sll_node<S>* last;

	sll_node<S>* lock;
	sll_node<S>* plock;
	sll_node<S>* slock;
	int length = 0;
	SLL<S>() {//empty list inititiated
		start = NULL;
		last = NULL;
		lock = NULL;
		plock = NULL;
		slock = NULL;
	}
	bool isEmpty();
	void printList();
	void insertAtEnd(S data);
	//void printList();
};

template <typename S>
bool SLL<S>::isEmpty() {//return if function is empty or not
	return start == NULL;
}



template <typename S>
void SLL<S>::printList() {//print the leements of the list
	if (!isEmpty()) {
		sll_node<S>* temp = start;
		cout << "List is: ";
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != NULL);
	}
	else
		cout << "List is Empty" << endl;
	cout << endl;
}



template <typename S>
void SLL<S>::insertAtEnd(S data) {// for inserting a value at the last end of the list

	/*S* newS = new (S)(c, n, l, ct, e_t, e_c, tr,
		cl, assem, b_t, u, i, p, m_y, mil);*/
	sll_node<S>* newS = new sll_node<S>(data);
		//newS->data = value;
	if (isEmpty()) {// in case of empty list initializing teh first S as start and last
		start = newS;
		last = newS;
		start->next = NULL;
	}
	else {//case list is not empty
		last->next = newS;
		last = newS;
	}
	length++;
}

//template <class main_node>
//class SLL{
//public:
//	main_node* start;
//	main_node* last;
//
//	main_node* lock;
//	main_node* plock;
//	main_node* slock;
//	int length = 0;
//
//	SLL() {//empty list inititiated
//		start = NULL;
//		last = NULL;
//		lock = NULL;
//		plock = NULL;
//		slock = NULL;
//	}
//	bool isEmpty();
//	void printList();
//	//void print_main_node(main_node* t);
//	void insertAtEnd(string c, string n, string l, string ct, string e_t, string e_c, string tr,
//		string cl, string assem, string b_t, string u, int i, int p, int m_y, int mil);
//};
//
//template<typename main_node>
//void SLL<main_node>::printList() {
//	if (!isEmpty()) {
//		main_node* temp = start;
//		cout << "List is: ";
//		do {
//			print_main_node(temp);
//			temp = temp->next;
//		} while (temp != NULL);
//
//	}
//	else
//		cout << "List is Empty" << endl;
//	cout << endl;
//}
//
//template<typename main_node>
//void /*SLL<main_node>::*/print_main_node(main_node* t) {
//	cout << t->index<< t->index << "\t" << t->company << "\t" << t->data.name << "\t" << t->data.price << "\t" <<
//		t->data.model_year << "\t" << t->data.location << "\t" << t->data.mileage << "\t" << t->data.city << "\t" << t->data.eng_type << "\t" <<
//		t->data.eng_capacity << "\t" << t->data.transmission << "\t" << t->data.color << "\t" << t->data.assembly << "\t" << t->data.body_type << "\t";
//}
//
//
//template <typename main_node>
//void SLL<main_node>::insertAtEnd(string c, string n, string l, string ct, string e_t, string e_c, string tr,
//	string cl, string assem, string b_t, string u, int i, int p, int m_y, int mil) {// for inserting a value at the last end of the list
//
//	sll_node<main_node>* newS = new (c, n, l, ct, e_t, e_c, tr,
//		cl, assem, b_t, u, i, p, m_y, mil);
//	//sll_node<main_node>* newS = new (data);
//	//newS->data = value;
//	if (isEmpty()) {// in case of empty list initializing teh first S as start and last
//		start = newS;
//		last = newS;
//		start->next = NULL;
//	}
//	else {//case list is not empty
//		last->next = newS;
//		last = newS;
//	}
//	length++;
//}

#endif










