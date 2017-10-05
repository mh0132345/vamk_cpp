#include <iostream>
using namespace std;

struct room{
	char room_id[10];
	char type[10];
	double price;
};

struct customer{
	char name[80];
	char room_id[10];
	int nights;
};

void inputRoomInfo(room *allRoom , int count);
void inputCustomerInfo(customer *allCustomer , int count);
void printOccupiedRooms(customer* allCustomer, int number_of_customer);
void printCustomer(customer* a_customer);

int main(void){
	int number_of_room, number_of_customer, i, j;
	
	cout << "Input number of room: ";
	cin >> number_of_room;
	cout << "Input number of customer: ";
	cin >> number_of_customer;
	
	//Input info for rooms and customers
	room allRoom[number_of_room]; 
    	customer allCustomer[number_of_customer];
    	for(i=0;i<number_of_room;i++)
		inputRoomInfo(allRoom, i);
	for(i=0;i<number_of_customer;i++)
		inputCustomerInfo(allCustomer, i);
	
	//Display all room occupied
	printOccupiedRooms(allCustomer, number_of_customer);
	
	return 0;
}

void inputRoomInfo(room *allRoom , int count){
	room *new_room = new room;
	cout << "Input room_id: ";
	cin >> new_room->room_id;
	cout << "Input type of room: ";
	cin >> new_room->type;
	cout << "Input price per night: ";
	cin >> new_room->price;
	allRoom[count] = *new_room;
	delete new_room;
}

void inputCustomerInfo(customer *allCustomer , int count){
	customer *new_customer = new customer;
	cout << "Input name: ";
	cin >> new_customer->name;
	cout << "Input room_id: ";
	cin >> new_customer->room_id;
	cout << "Input number of nights: ";
	cin >> new_customer->nights;

	allCustomer[count] = *new_customer;
	delete new_customer;
}

void printOccupiedRooms(customer* allCustomer, int number_of_customer){
	for(int i=0; i < number_of_customer; i++)
		cout << allCustomer[i].room_id << " is occupied by " << allCustomer[i].name << " " << allCustomer[i].nights << " nights." << endl;
}
