#include <iostream>
#include <cstring>
using namespace std;

class Event{
protected:
	char name[50];
	char type[20];
	char location[50];

public:
	Event(){};
	Event(char name[50], char type[20],	char location[50]){
		strcpy(this->name, name);
		strcpy(this->type, type);
		strcpy(this->location, location);
	};
	char* getName(){
		return this->name;
	}
	
	char* getType(){
		return this->type;
	}
	
	char* getLocation(){
		return this->location;
	}
	void getInfo(){
		cout << "Event " << this->name << " with type: " << this->type << " and location is " << this->location << endl; 
	}
};

class Concert: public Event{
	char date[20];
	char duration[20];
	double price;

public:
	Concert(){};
	Concert(char date[20], char duration[20], double price, char name[50], char type[20], char location[50]): Event(name, type, location){
		strcpy(this->date, date);
		strcpy(this->duration, duration);
		this->price = price;
	}
	char* getDate(){
		return this->date;
	}
	char* getDuration(){
		return this->duration;
	}
	double getPrice(){
		return this->price;
	}
	void getInfo(){
		cout << "Concert " << this->name << " with type: " << this->type << " and location is " << this->location << ". ";
		cout << "It start on date: " << this->date << ", longs for " << this->duration << " and cost " << this->price << endl;
	}
};

// I define only 1 function search event because search base on name OR location
void searchEvent(Concert* all_concert, int num_event, char name_or_location[]){
	int i;
	for(i=0; i<num_event; i++){
		if(strcmp(all_concert[i].getName(), name_or_location)==0){
			all_concert[i].getInfo();
		}
		if(strcmp(all_concert[i].getLocation(), name_or_location)==0){
			all_concert[i].getInfo();
		}
	}
}

// I define 2 functions search concert because search base on date and price
void searchConcertWithDate(Concert* all_concert, int num_concert, char date[]){
	int i;
	for(i=0; i<num_concert; i++){
		if(strcmp(all_concert[i].getDate(), date)==0){
			all_concert[i].getInfo();
		}
	}
}

void searchConcertWithPrice(Concert* all_concert, int num_concert, double price){
	int i;
	for(i=0; i<num_concert; i++){
		if(all_concert[i].getPrice()==price){
			all_concert[i].getInfo();
		}
	}
}

int main(void){
	int num_concert = 0;
	Concert* all_concert = new Concert[20];
	all_concert[0] = Concert("08-12", "1-days", 1, "a1", "new_type", "some_where");
	all_concert[1] = Concert("08-12", "1-days", 1, "a2", "new_type", "some_where");
	all_concert[2] = Concert("09-12", "2-days", 2, "b1", "new_type", "vaasa");
	all_concert[3] = Concert("09-12", "2-days", 2, "b2", "new_type", "vaasa");
	all_concert[4] = Concert("10-12", "3-days", 3, "c1", "new_type", "hel");
	all_concert[5] = Concert("10-12", "3-days", 3, "c2", "new_type", "hel");
	num_concert = 6;
	cout << "Seach concert with name is a1: " << endl;
	searchEvent(all_concert, num_concert, "a1");
	cout << "Seach concert with location is some_where: " << endl;
	searchEvent(all_concert, num_concert, "some_where");
	cout << "Seach concert with date is 09-12: " << endl;
	searchConcertWithDate(all_concert, num_concert, "09-12");
	cout << "Seach concert with price is 3: " << endl;
	searchConcertWithPrice(all_concert, num_concert, 3);
	return 0;
}
