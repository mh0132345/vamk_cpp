#include <iostream>
using namespace std;

struct student{
	double active;
	bool project;
	double percent;
	unsigned int pass: 3;
};

int main(void){
	student new_student;
	cout << "Input the student's activeness: ";
	cin >> new_student.active;
	cout << "Has the project done?(0 for false, 1 for true): ";
	cin >> new_student.project;
	cout << "Input the percentage of points got from the exam: ";
	cin >> new_student.percent;
	if(!new_student.project || new_student.percent < 40)
		new_student.pass = 0;
	else {
		new_student.pass = (int)(new_student.percent- 40)/15+1;
 		if(new_student.active > 0.5) new_student.pass++;
	}
	cout << "Final grade: " << new_student.pass << endl;
}
