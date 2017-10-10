#include <iostream>
using namespace std;

class employee {
	string name;
	string id;
	int salary;
public:
	void set_values(string, string, int);
	void print_values();
	friend employee* search_employee(string, employee[], int);
};

void employee::set_values(string name, string id, int salary){
	this->name = name;
	this->id = id;
	this->salary = salary;
}

void employee::print_values(){
	cout << "Employee " << this->name << " with id: " << this->id << " have salary: " << this->salary << endl;
}

employee * search_employee(string check_id, employee all_employee[], int number_of_employee){
	int i;
	for(i=0; i< number_of_employee; i++){
		if (all_employee[i].id == check_id){
			return all_employee + i;
			break;
		}
	}
	return 0;
}

int main(void){
	int i, number_of_employee = 0;
	char choose;
	employee *all_employee = new employee[100];
	number_of_employee = 10;
	for(i=0; i<10; i++){
		all_employee[i].set_values("abc", to_string(i), 100);
		all_employee[i].print_values();
	}

	while(choose!='Q'){
		cout << "A: add new employee information\nR: remove employee's information\nS: search based on employee's ID\nQ: quit" << endl;
		cin >> choose;
		switch(choose){
			case 'A':{
				string name, id;
				int salary;
				cout << "Input name: ";
				cin >> name;
				cout << "Input id: ";
				cin >> id;
				cout << "Input salary: ";
				cin >> salary;
				all_employee[number_of_employee++].set_values(name, id, salary);
				cout <<"Added" << endl;
				break;
			}
			case 'R':{
				string id;
				cout << "Input ID of employee who you want to remove: ";
				cin >> id;
				employee *p = search_employee(id, all_employee, number_of_employee);
				delete search_employee(id, all_employee, number_of_employee);
				p = NULL;
				cout << "Employee deleted!" << endl;
				break;
			}
			case 'S':{
				string id;
				cout << "Input ID of employee who you want to search: ";
				cin >> id;
				search_employee(id, all_employee, number_of_employee)->print_values();
				break;
			}
			case 'Q':
				cout << "See you next time!" << endl;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
	}


	return 0;
}