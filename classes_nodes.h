
#include <iostream>
#include <string>
#include <vector>
#include "SLL.h"
#ifndef SLL_CPP
#define SSL_CPP
using namespace std;


class main_node {
public:

	int index;
	avl_node<string>* company, *name, *location, *city, *engine_type, *engine_capacity, *transmission, *color, *assembly, *body_type;
	avl_node<int> *price, *mileage, *model_year;
	string url;
	SLL<avl_node<string>*> features;
	main_node(){}



	void print_main_node() {
		cout << "Index: " << index << "\tCompany: " << company->data << "\tName: " << name->data <<"\tPrice: " << price->data << endl 
			<< "\t\tModel Year: " << model_year->data << "\tLocation: " << location->data << "\tEngine Capacity: " << engine_capacity->data <<endl
			<< "\t\tMileage: " << mileage->data << "\tCity: " << city->data << "\tEngine Type: " << engine_type->data << "\tTransmission: " << transmission->data << endl
			<< "\t\tColour: " << color->data << "\t\tAssembly: " << assembly->data << "\tBody Type: " << body_type->data <<endl
			<< "\t\tURL: " << url << endl<<"\t\t";
		cout << "Features: ";
		sll_node< avl_node<string>*>* temp = features.start;
		while (temp != NULL) {
			cout << temp->data->data<<" " ;
			temp = temp->next;
		}

		cout << endl << endl << endl;
}




};
#endif





