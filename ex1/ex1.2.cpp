#include <iostream>
using namespace std;

struct student {
	char name[80];
	unsigned int id;
	unsigned int grade;
};

int main(void){
	student info[5] = {{"Jaina", 124, 24},
	 		   {"Anduin", 105, 56},
			   {"Malfurion", 267, 15},
			   {"Rexxar", 145, 20},
			   {"Garrosh", 178, 46}};
	int i, j;
	for(i=0;i<5;i++){
		for(j=i+1; j<5;j++){
			if(info[i].grade > info[j].grade){
				student temp = info[i];
				info[i] = info[j];
				info[j] = temp;
			}
		}
	}
	for(i=0; i<5;i++){
		cout << "Name: " << info[i].name << " ID: " << info[i].id << " Grade: " << info[i].grade << endl;
	}
	return 0;
}
