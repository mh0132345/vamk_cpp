#include <iostream>
using namespace std;

class hotel;
class customer;

class Room {
    string room_number;
	double area;
	string type;
	double price_per_night;
	bool isReversed;
public:
    Room(){};
	Room(string room_number, double area, string type, double price_per_night){
		this->room_number = room_number;
		this->area = area;
		this->type = type;
		this->price_per_night = price_per_night;
		this->isReversed = false;
	}
	string getRoomNumber(){
		return this->room_number;
	}
	double getArea(){
		return this->area;
	}
	string getType(){
		return this->type;
	}
	double getPricePerNight(){
		return this->price_per_night;
	}
	bool isRoomReversed(){
		return this->isReversed;
	}
	void set_reversed(){
		this->isReversed = true;
	}
	void getInfo(){
		cout << "Room " << this->room_number << " with area of " << this->area << ". Type of room: " << this->type << " and price per night is: " << this->price_per_night << endl;
	}
};

class Customer {
	string name;
	string address;
	string room_number;
	string arrive_date;
	int nights;
	double totalPrice;
public:
    Customer(){};
	Customer(string name, string address, string room_number, string arrive_date, int nights){
		this->name = name;
		this->address = address;
		this->room_number = room_number;
		this->arrive_date = arrive_date;
		this->nights = nights;
		this->totalPrice = 0;
	}
	string getName(){
		return this->name;
	}
	string getAddress(){
		return this->address;
	}
	string getRoomNumber(){
		return this->room_number;
	}
	string getArriveDate(){
		return this->arrive_date;
	}
	int getNights(){
		return this->nights;
	}
	void setTotalPrice(double totalPrice){
		this->totalPrice = totalPrice;
	}
	void getInfo(){
		cout << this->name << " with address: " << this->address << " reverse room " << this->room_number << " from: " << this->arrive_date << " for " << this->nights << " nights. Total price: " << this->totalPrice << endl;
	}
};

class Hotel{
	string name;
	string address;
	int stars;
	int number_of_rooms;
public:
	Hotel(string name, string address, int stars, int number_of_rooms){
		this->name = name;
		this->address = address;
		this->stars = stars;
		this->number_of_rooms = number_of_rooms;
	}
	void getInfo(){
        cout << this->name << " in " << this->address << ". Star: " << this->stars << " with " << this->number_of_rooms << " rooms" << endl;
	}
};
void add_customer(Customer * all_customer, Room *all_room, int index){
	string name;
	string address;
	string arrive_date;
	string room_number;
	int nights, type, check = 1;
	double price_per_night;
	cout << "Name: ";
	cin >> name;
	cout << "Address: ";
	cin >> address;
	cout << "Arrival date: ";
	cin >> arrive_date;
	cout << "Room number: ";
	cin >> room_number;
	cout << "Nights of stay: ";
	cin >> nights;
	while (check==1) {
		cout << "What type of room? Single(1), Double(2) or suite(3) : ";
		cin >> type;
    	switch (type){
			case(1):
				price_per_night = 50;
				all_room[index] = Room(room_number, 10, "Single", price_per_night);
	            check = 0;
	            break;
			case(2):
				price_per_night = 100;
				all_room[index] = Room(room_number, 20, "Double", price_per_night);
				check = 0;
				break;
	  		case(3):
	  			price_per_night = 150;
				all_room[index] = Room(room_number, 30, "Suite", price_per_night);
	            check = 0;
	            break;
		default:
            cout << "Invalid choice" << endl;
		}
	}
	all_room[index].set_reversed();
	all_customer[index] = Customer(name, address, room_number, arrive_date, nights);
	all_customer[index].setTotalPrice(price_per_night * nights);
	cout << "Added customer" << endl;
}

int search_index_room(Room *all_room, int curr_room, string room_number){
    int i;
    for(i=1; i<=curr_room; i++)
        if (all_room[i].getRoomNumber().compare(room_number)==0)
            return i;
    return -1;
}

int search_index_customer(Customer *all_customer, int curr_customer, string room_number){
    int i;
    for(i=1; i<=curr_customer; i++)
        if (all_customer[i].getRoomNumber().compare(room_number)==0)
            return i;
    return -1;
}

void remove_customer(Customer *all_customer, Room *all_room, int curr_customer, int curr_room, string room_number){
    int index_room = search_index_room(all_room, curr_room, room_number);
    int index_customer = search_index_customer(all_customer, curr_customer, room_number);
    if(index_room != -1 && index_customer!=-1){
        cout << "Found!";
        for(;index_room<curr_room-1;index_room++)
            all_room[index_room] = all_room[index_room+1];
        for(;index_customer<curr_customer-1;index_customer++)
            all_customer[index_customer] = all_customer[index_customer+1];
        cout << "Deleted customer" << endl;
    }
    else
        cout << "Wrong room number";
}

int main(void){
	Room all_room[100];
	Customer all_customer[100];
	Hotel hotel("Max_star", "Vaasa", 5, 100);
	int curr_room = 0, curr_customer = 0;
	char selection;
//  curr_room++;
//	curr_customer++;
//	add_customer(all_customer, all_room, curr_customer);
//	all_room[1].getInfo();
//	cout << search_index_room(all_room, curr_room, "1") << endl;
//	cout << search_index_customer(all_customer, curr_customer, "1") << endl;
//	remove_customer(all_customer, all_room, curr_customer, curr_room, "1");
    while(true){
        cout << "\nMENU: " << endl;
        cout << "H: Print Hotel information" << endl;
        cout << "A: add new customer information" << endl;
        cout << "D: delete customer's information" << endl;
        cout << "M: print the list of booked rooms" << endl;
        cout << "N: print the list of customers" << endl;
        cout << "R: search based on room" << endl;
        cout << "S: search based on customer" << endl;
        cout << "Q: quit" << endl;
        cout << "__________________________________" << endl;
        cout << "Enter your selection: ";
        cin.get(selection);
        selection = tolower(selection);
        switch (selection){
            case 'h':// Hotel info
                hotel.getInfo();
                break;
            case 'a'://"A: add new customer information"
                curr_customer++;
                curr_room++;
                add_customer(all_customer, all_room, curr_customer);
                all_customer[curr_customer].getInfo();
                all_room[curr_room].getInfo();
                break;
            case 'd'://"D: delete customer's information"
            {
                string room_number;
                cout << "Input customer's room number to remove: ";
                cin >> room_number;
                remove_customer(all_customer, all_room, curr_customer, curr_room, room_number);
                break;
            }
            case 'r'://"R: search based on room"
            {
                string room_number;
                cout << "Input room number: ";
                cin >> room_number;
                int index_found = search_index_room(all_room, curr_room, room_number);
                all_room[index_found].getInfo();
                break;
            }
            case 'm'://"M: print the list of booked rooms"
            {
                for(int i=1; i<= curr_room; i++){
                    cout << "The following room is booked: " << endl;
                    if(all_room[i].isRoomReversed()) all_room[i].getInfo();
                }
                break;
            }
            case 'n'://"N: print the list of customers"
                for(int i=1; i<=curr_customer; i++)
                    all_customer[i].getInfo();
                break;
            case 's'://"S: search customer based on customer's room"
            {
                string room_number;
                cout << "Input customer's room number: ";
                cin >> room_number;
                int index_found = search_index_customer(all_customer, curr_customer, room_number);
                all_customer[index_found].getInfo();
                break;
            }
            case 'q':// Quit
                cout << "See you next time";
                break;
            default:
                cout << "Input a right value" << endl;
                break;
        }
        cin.get();
    }
	return 0;
}
