#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<string>
#include<string.h>
#include"AVL.h"
#include"SLL.h"
#include"hash.h"
#include"classes_nodes.h"
using namespace std;
sll_node<int>* intersection(sll_node<int>* first_list_ptr, sll_node<int>* second_list_ptr);

AVL<string> company, name, location, city, engine_type, engine_capacity, transmission, color, assembly, body_type, features;
AVL<int> price, mileage, model_year;		//creating AVL trees for each column
string url;
HashTable price_hashtable;

main_node* main_node_array = new main_node[46085];	//our main class node in which at each index there are pointers to the data for a 
													//single car

void parsor() {

	ifstream fin;

	string line;
	int  i = 1;
	//char* str_ptr = strtok(*line, "|");
	fin.open("./dataset/data.csv");		//openeing the file for reading

	while (fin) {
		//cout << "LOOP entered";
		getline(fin, line);		//input taking a full line untill endline statement
		char* cstr = new char[line.length() + 1];		//converting the string to a char* type for use in strtok_s function
		strcpy(cstr, line.c_str());
		char* end_str = 0;
		char* str_ptr = strtok_s(cstr, "|", &end_str);		//strtok_s is used for seperating an input string based on a entered delimitter

		while (str_ptr) {
			//int temp = atoi(str_ptr);
			main_node_array[i].index = i;
			//cout << i << endl;
			str_ptr = strtok_s(NULL, "|", &end_str);			//here the third argument is used for storing the rest of the line 
			company.root = company.insert(str_ptr, company.root, i);
			main_node_array[i].company = company.return_pointer;
			//company

			str_ptr = strtok_s(NULL, "|", &end_str);
			name.root = name.insert(str_ptr, name.root, i);		//inserting values in respective avl trees
			main_node_array[i].name = name.return_pointer;		//and then saving the address of node of avl tree in which insertion took place
			//name												//in the main_class(respective row)

			str_ptr = strtok_s(NULL, "|", &end_str);
			price.root = price.insert(atoi(str_ptr), price.root, i);
			main_node_array[i].price = price.return_pointer;
			//price

			str_ptr = strtok_s(NULL, "|", &end_str);
			model_year.root = model_year.insert(atoi(str_ptr), model_year.root, i);
			main_node_array[i].model_year = model_year.return_pointer;
			//model_year


			price_hashtable.Insert(atoi(str_ptr), i);


			str_ptr = strtok_s(NULL, "|", &end_str);
			location.root = location.insert(str_ptr, location.root, i);
			main_node_array[i].location = location.return_pointer;
			//location

			str_ptr = strtok_s(NULL, "|", &end_str);
			mileage.root = mileage.insert(atoi(str_ptr), mileage.root, i);
			main_node_array[i].mileage = mileage.return_pointer;
			//mileage

			str_ptr = strtok_s(NULL, "|", &end_str);
			city.root = city.insert(str_ptr, city.root, i);
			main_node_array[i].city = city.return_pointer;
			//city

			str_ptr = strtok_s(NULL, "|", &end_str);
			engine_type.root = engine_type.insert(str_ptr, engine_type.root, i);
			main_node_array[i].engine_type = engine_type.return_pointer;
			//eng_type

			str_ptr = strtok_s(NULL, "|", &end_str);
			engine_capacity.root = engine_capacity.insert(str_ptr, engine_capacity.root, i);
			main_node_array[i].engine_capacity = engine_capacity.return_pointer;
			//eng_capacity

			str_ptr = strtok_s(NULL, "|", &end_str);
			transmission.root = transmission.insert(str_ptr, transmission.root, i);
			main_node_array[i].transmission = transmission.return_pointer;
			//transmission

			str_ptr = strtok_s(NULL, "|", &end_str);
			color.root = color.insert(str_ptr, color.root, i);
			main_node_array[i].color = color.return_pointer;
			//color

			str_ptr = strtok_s(NULL, "|", &end_str);
			assembly.root = assembly.insert(str_ptr, assembly.root, i);
			main_node_array[i].assembly = assembly.return_pointer;
			//assembly

			str_ptr = strtok_s(NULL, "|", &end_str);
			body_type.root = body_type.insert(str_ptr, body_type.root, i);
			main_node_array[i].body_type = body_type.return_pointer;
			//body_type

			str_ptr = strtok_s(NULL, "|", &end_str);

			char* features_line = str_ptr, * feat_str = NULL;

			char* str_features = strtok_s(features_line, ",", &feat_str);
			//features
			while (str_features) {

				features.root = features.insert(str_features, features.root, i);
				main_node_array[i].features.insertAtEnd(features.return_pointer);
				str_features = strtok_s(NULL, ",", &feat_str);

			}

			str_ptr = strtok_s(NULL, "|", &end_str);
			main_node_array[i].url = str_ptr;
			//url
			str_ptr = strtok_s(NULL, "|", &end_str);
		}
		i++;
	}
	fin.close();
}

sll_node<int>* intersection(sll_node<int>* first_list_ptr, sll_node<int>* second_list_ptr) {
	SLL<int> common_indexes_list;
	while (first_list_ptr != NULL && second_list_ptr != NULL) {
		if (first_list_ptr->data == second_list_ptr->data) {
			common_indexes_list.insertAtEnd(first_list_ptr->data);
			first_list_ptr = first_list_ptr->next;
		}
		else if (first_list_ptr->data < second_list_ptr->data)
			first_list_ptr = first_list_ptr->next;
		else
			second_list_ptr = second_list_ptr->next;
	}
	return common_indexes_list.start;
}

//sll_node<int>* search_specs(int parameter_no) {
//	string string_input;
//	int int_input;
//	sll_node<int>* temp = NULL;
//	cout << "Enter the specification: ";
//	if (parameter_no > 0 && parameter_no < 11)
//		cin >> string_input;
//	else
//		cin >> int_input;
//	switch (parameter_no) {
//	case 1:
//		temp = company.search_node(string_input)->carsList.start;
//	case 2:
//		temp = name.search_node(string_input)->carsList.start;
//	case 3:
//		temp = location.search_node(string_input)->carsList.start;
//	case 4:
//		temp = city.search_node(string_input)->carsList.start;
//	case 5:
//		temp = engine_type.search_node(string_input)->carsList.start;
//	case 6:
//		temp = engine_capacity.search_node(string_input)->carsList.start;
//	case 7:
//		temp = transmission.search_node(string_input)->carsList.start;
//	case 8:
//		temp = color.search_node(string_input)->carsList.start;
//	case 9:
//		temp = assembly.search_node(string_input)->carsList.start;
//	case 10:
//		temp = body_type.search_node(string_input)->carsList.start;
//	case 11:
//		temp = price.search_node(int_input)->carsList.start;
//	case 12:
//		temp = mileage.search_node(int_input)->carsList.start;
//	case 13:
//		temp = model_year.search_node(int_input)->carsList.start;
//	case 14:
//		temp = features.search_node(string_input)->carsList.start;
//	}
//	return temp;
//}
//
//void select_parameters(int choice) {
//	int parameter_no = 0, i = 0;
//	
//	cout << "Parameters are: " << endl;
//	cout << "1. Company\t2. Name\n3. Location\t4. City\n5. Engine_type\t6. Engine_capacity\n7. Transmission\t8. Color"
//		"\n9. Assembly\t10. Body_type\n11. Price\t12. Mileage\n13. Model_Year\t14. Features" << endl << endl;
//	while (parameter_no < 1 || parameter_no>14) {
//		cout << "Select parameter number " << i << ": ";
//		cin >> parameter_no;
//	}
//
//	search_specs(parameter_no);
//	
//}



int main() {
	int choice = 0;
	cout << "1. Start parsing." << endl;
	cout << "2. Exit\n" << endl;
	while (choice != 1 && choice != 2) {
		cout << "Your choice: ";
		cin >> choice;
	}
	if (choice == 1) {
		system("CLS");
		cout << "Parsing in progress" << endl;
		parsor();
	}
	else
		return 0;
	system("CLS");
	cout << "Parsing completed." << endl;


	/*
	cout << "Enter the no. of parameters on basis of which you want to search cars(1,2,3)." << endl;
	choice = 0;
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "Your choice: ";
		cin >> choice;
	}
	
	if (choice == 2) {

	}*/
	int p;			
	cout << "Enter the model year for cars to be displayed of:  ";
	cin >> p;			//input price
	int k = price_hashtable.getkey(p);
	sll_node<int>* temp = price_hashtable.hash_array[k].list.start;
	while (temp != NULL) {
		main_node_array[temp->data].print_main_node();
		temp = temp->next;
	}
		

	

















	//int index;
	
	/*company.preorder(company.root);
	cout << endl;
	
	name.preorder(name.root);
	cout << endl;
	price.preorder(price.root);
	cout << endl;
	
	location.preorder(location.root);
	cout << endl;
	mileage.preorder(mileage.root);
	cout << endl;
	city.preorder(city.root);
	cout << endl;
	engine_type.preorder(engine_type.root);
	cout << endl;
	engine_capacity.preorder(engine_capacity.root);
	cout << endl;
	cout << main_node_array[1].assembly->data;
	cout << endl;*/

	/*sll_node<int>* temp = price.search_node(2385000)->carsList.start;
	int x;
	while (temp != NULL) {
		x = temp->data;
		main_node_array[x].print_main_node();
		temp = temp->next;
	}*/
	/*mileage.preorder(mileage.root);
	cout << endl;*/
	/*sll_node<int>* temp1 = location.search_node("Jehlum Punjab")->carsList.start;
	sll_node<int>* temp2 = company.search_node("Suzuki")->carsList.start;
	sll_node<int>* temp = intersection(temp1, temp2);
	int x;
	while (temp != NULL) {
		x = temp->data;
		main_node_array[x].print_main_node();
		temp = temp->next;
	}*/

	
}































//AVL<string> company, name, location, city, engine_type, engine_capacity, transmission, color, assembly, body_type, features; //all the attributes in the avl.  it is because we have repetitive values in every column. so we have stored the distinct values in the avl and then to that specific node we have stored the pointer of the repetitions in the link list .
//AVL<int> price, mileage, model_year;
//string url;
//
//main_node* main_node_array = new main_node[46085];
//
//class driverFunction
//{
//public:
//	void parsor();
//	void getPrice();
//	void getCompany();
//	void getName();
//	void getCity();
//	void getModel_year();
//	void getBody_type();
//	void getColor();
//};
//

//	void driverFunction::getPrice()
//	{
//		int input;
//		cout << "Enter price::" << endl;
//		cin >> input;
//		sll_node<int>* temp = price.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}void driverFunction::getColor()
//	{
//		string input;
//		cout << "Enter COLOR::" << endl;
//		cin >> input;
//		sll_node<int>* temp = color.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}
//	void driverFunction::getCompany()
//	{
//		string input;
//		cout << "Enter Company Name::" << endl;
//		cin >> input;
//		sll_node<int>* temp = company.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}
//	void driverFunction::getBody_type()
//	{
//		string input;
//		cout << "Enter Body Type::" << endl;
//		cin >> input;
//		sll_node<int>* temp = body_type.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}
//	void driverFunction::getModel_year()
//	{
//		int input;
//		cout << "Enter Model Year::" << endl;
//		cin >> input;
//		sll_node<int>* temp = model_year.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}
//	void driverFunction::getName()
//	{
//		string input;
//		cout << "Enter Name of the Car::" << endl;
//		cin >> input;
//		sll_node<int>* temp = name.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}
//	
//	void driverFunction::getCity()
//	{
//		string input;
//		cout << "Enter City of the Car ::" << endl;
//		cin >> input;
//		sll_node<int>* temp = location.search_node(input)->carsList.start;
//		int x;
//		while (temp != NULL) {
//			x = temp->data;
//			main_node_array[x].print_main_node();
//			temp = temp->next;
//		}
//	}
//	int main()
//	{
//		driverFunction d1;
//		cout << "1. Start Parsing \n 2. Search based on city /n 3. Search based on Model Year /n 4. Search based on Body type /n 5. Search based on Color of the Car /n 6. Search based on Price of the Car /n 7. Search based on Name of the Car /n 8. Search based on Name of the company /n /n 9. Clear screen /n 10. Exit " << endl;
//
//		int choice;
//		do {
//			cout << "Select any option" << endl;
//			cin >> choice;
//			switch (choice)
//			{
//			case 1:
//			{
//				d1.parsor();
//				break;
//			}
//			case 2:
//			{
//				d1.getCity();
//				break;
//			}
//			case 3:
//			{
//				d1.getModel_year();
//				break;
//			}
//			case 4:
//			{
//				d1.getBody_type();
//				break;
//			}
//			case 5:
//			{
//				d1.getColor();
//				break;
//			}
//			case 6:
//			{
//				d1.getPrice();
//				break;
//			}
//			case 7:
//			{
//				d1.getName();
//				break;
//			}
//			case 8:
//			{
//				d1.getCompany();
//				break;
//			}
//			case 9:
//			{
//				system("cls");
//				cout << "1. Start Parsing \n 2. Search based on city /n 3. Search based on Model Year /n 4. Search based on Body type /n 5. Search based on Color of the Car /n 6. Search based on Price of the Car /n 7. Search based on Name of the Car /n 8. Search based on Name of the company /n 9. Clear screen /n 10. Exit " << endl;
//				break;
//			}
//			default:
//			{
//				cout << "Enter valid option" << endl;
//				break;
//			}
//			}
//		} while (choice != 10);
//	}