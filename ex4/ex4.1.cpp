#include <iostream>
using namespace std;

int *max_value(int *arr, int size_of_arr);
int *min_value(int *arr , int size_of_arr);
void read_arr(int *arr, int size_of_arr);

int main(void){
	int size_of_arr;
	cout << "How many numbers do you want to input? ";
	cin >> size_of_arr;
	int arr[size_of_arr];
	read_arr(arr, size_of_arr);
	cout << "Max: " << *max_value(arr, size_of_arr) << endl;
	cout << "Min: " << *min_value(arr, size_of_arr) << endl;
	return 0;
}

void read_arr(int *arr, int size_of_arr){
	int i;
	for(i=0;i<size_of_arr;i++){
		cout << "Input arr[" << i << "]: ";
		cin >> arr[i];
	}
}

int *max_value(int * arr, int size_of_arr){
	int *max_position = &arr[0], max = arr[0], i;
	for(i=0;i<size_of_arr;i++)
		if(arr[i]>max){
			max = arr[i];
			max_position = &arr[i];
		}
	 return max_position;
}

int *min_value(int * arr, int size_of_arr){
	int *min_position = &arr[0], min = arr[0], i;
	for(i=0;i<size_of_arr;i++)
		if(arr[i]<min){
			min = arr[i];
			min_position = &arr[i];
		}
	 return min_position;
}
