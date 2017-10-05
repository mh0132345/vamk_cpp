#include <iostream>
using namespace std;

int main(void){
	int *array = new int[100];
	int low,high, i, count = 0;
	cout << "Enter the lower number";
	cin >> low;
	cout <<"Enter the higher number";
	cin >> high;
	while(low<=high){
		bool prime = true;
		for(i=2;i<=(low/2);i++){
			if(low%i == 0){
				prime = false;
				break;
			}
		}
		
		if(prime)
			array[count++] = low;
			
		low++;
	}
	
	for(i=0;i<count;i++)
		cout << array[i] << " ";
	delete array;
	return 0;
}