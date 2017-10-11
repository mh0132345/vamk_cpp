#include <iostream>
using namespace std;

class room{
	string room_number;
	double area;
	string type;
	double price_per_night;
public:
	void setValue(string room_number, double area, string type, double price_per_night){
		this.room_number = room_number;
		this.area = area;
		this.type = type;
		this.price_per_night;
	}
	string getRoomNumber(){
		return this.room_number;	
	}	
	double getArea(){
		return this.area;
	}
	string getType(){
		return this.type;
	}
	double getPricePerNight(){
		return this.price_per_night;
	}
}

class customer{
	string name;
	string address;
	string room_number;
	string arrive_date;
	int nights;
public:
	string getName(){
		return this.name;
	}
	string getAddress(){
		return this.address;
	}
	string getRoomNumber(){
		return this.room_number;
	}
	string getArriveDate(){
		return this.arrive_date;
	}
	int getNights(){
		return this.nights;
	}
}

class hotel{
	string name;
	string address;
	int stars;
	int number_of_rooms;
	room all_room[100];
	customer all_customer[100];
public:	
	void getCustomerInfo();
	void reverseRoom();
	void printRooms();
	void printCustomers();
}

int main(void){
	
	return 0;
}
