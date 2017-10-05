#include <iostream>
using namespace std;

int main(void){
	int series1[15], series2[15], series3[15];
	series1[0] = 1; series1[1] = 0; series1[2] = 2;
	series2[0] = 1; series2[1] = 1; series2[2] = 1;
	series3[0] = -1; series3[1] = 0; series3[2] = -3;
	int i=3;
	while(i<15){
		series1[i] = series1[i-1] + series1[i-2] - series1[i-3];
		series2[i] = series2[i-1] + series2[i-2] + series2[i-3];
		series3[i] = series3[i-1] + series3[i-2] - series3[i-3];
		i++;
	}	
	for(i=0;i<15;i++){
		cout << series1[i] << " ";
	}
	cout << endl;

	for(i=0;i<15;i++){
		cout << series2[i] << " ";
	}
	cout << endl;

	for(i=0;i<15;i++){
		cout << series3[i] << " ";
	}
	return 0;
}
