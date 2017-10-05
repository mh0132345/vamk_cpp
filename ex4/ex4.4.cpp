#include <iostream>
using namespace std;

float first_sum(float n);
float second_sum(float n);

int main(void){
	cout << "Calculate first sum " << endl;
	cout << first_sum(7) << endl;
	cout << "Calculate second sum " << endl;
	cout << second_sum(5) << endl;
	return 0;
}

float first_sum(float n){
    float sum;
    if(n==1)
        return 0.5;
    sum = 1 /( 2*n) + first_sum(n-1);
    return sum;
}

float second_sum(float n){
    float sum;
    if(n==1)
        return -1.0/3.0;
    sum = - n/(2*n+1) + second_sum(n-1);
    return sum;
}

