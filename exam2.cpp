/* Write a program in C++ language, which can be used to manipulate event data. In the program define class Event, whose attributes are event name, type and location. 
Define necessary constructors and search function, which can receive name or location as argument and return full information of the event. Define also class Concert, which inherits class Event.
Define date, duration and price as attributes of class Concert.
Define necessary constructors and provide search functions so that it will be possible to search concert data also based on date and price.
In the main function, use a pointer to define an array for Concert objects and initialize them. Then call the functions to search and print out the concert information.*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
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

void searchEvent(Concert* all_concert, int num_event, char name[]){
	int i;
	for(i=0; i<num_event; i++){
		if(strcmp(all_concert[i].getName(), name)==0){
			all_concert[i].getInfo();
		}
	}
}

int main(int argc, char *argv[]){
	char date[20], duration[20], name[50], type[20], location[50];
	double price;
	int insert_more = 1, choose;
	
	if(argc<2){
		cout<<"File name missing!"<<endl;
		cout<<"Usage: "<<argv[0]<<" file_path_name"<<endl;
		return -1;
	}

	
	cout << "Type 1 for insert more, type 2 for search concert: ";
	cin >> choose;
	if (choose==1){
		 //Here we open the file output stream for appending data to the file.
		ofstream file_output_stream(argv[1], ios::app);
		//Here we check whether the file is opened or not. 
		if(!file_output_stream) {
			cout<<argv[1]<<" can not be opened"<<endl;
			return 1;
		}
		while(insert_more!=0){
			cout << "Input name: ";
			cin >> name;
			cout << "Input type: ";
			cin >> type;
			cout << "Input location: ";
			cin >> location;
			cout << "Input date: ";
			cin >> date;
			cout << "Input duration: ";
			cin >> duration;
			cout << "Input price: ";
			cin >> price;
			file_output_stream << "Concert " << name << ", type " << type << " and location is " << location << ". ";
			file_output_stream << "It start on date: " << date << ", longs for " << duration << " and cost " << price << endl;
			cout << "Do you want to insert more? (1 for yes, 0 for no) ";
			cin >> insert_more;
		}
		file_output_stream.close();
		cout<<"Data was written successfully to "<<argv[1]<<endl;
	}
	if(choose==2){
		ifstream file_input_stream(argv[1]);
		//Here we check whether the file has been opened or not.
		if(!file_input_stream) {
			cout<<"\nCannot open file!";
			return 1;
		}
		cout << "Please input the name you want to search: ";
		cin >> name;
		char str[255];
		int found = 0;
		while(file_input_stream) {
			//Here we read specified characters to str variable 
			file_input_stream.getline(str, 255);
			//Here we print the content of the line if it is not NULL
			char * pch;
			pch = strstr(str,name);
			if(pch){ 
				found = 1;
				cout<<str<<endl;
			}
		}
		if(found==0)
			cout << "The concert was not found." << endl;
		
		//Here we close the file input stream.
		file_input_stream.close();

	}
	return 0;
}
