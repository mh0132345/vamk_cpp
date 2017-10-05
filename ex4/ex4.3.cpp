#include <iostream>
using namespace std;

struct customer{
	char name[80];
	char id[10];
	int purchase;
};

void inputCustomerInfo(customer *allCustomer , int count);
void sortCustomer(customer* allCustomer, int number_of_customer);
void printCustomer(customer* allCustomer, int number_of_customer);

int main(void){
	int number_of_room, number_of_customer, i, j;

	//Input info of all customers
	cout << "Input number of customer: ";
	cin >> number_of_customer;
    customer allCustomer[number_of_customer];
	for(i=0;i<number_of_customer;i++)
		inputCustomerInfo(allCustomer, i);

    sortCustomer(allCustomer, number_of_customer);
	printCustomer(allCustomer, number_of_customer);

	return 0;
}

// Function to read info each customer and save into array
void inputCustomerInfo(customer *allCustomer , int count){
	customer *new_customer = new customer;
	cout << "Input name: ";
	cin >> new_customer->name;
	cout << "Input id: ";
	cin >> new_customer->id;
	cout << "Input number of purchase: ";
	cin >> new_customer->purchase;

	allCustomer[count] = *new_customer;
	delete new_customer;
}

// Sort customer purchase in descending order
void sortCustomer(customer* allCustomer, int number_of_customer){
    int i, j;
    customer temp;
    for(i=0;i<number_of_customer;i++)
        for(j=i+1;j<number_of_customer;j++){
            if(allCustomer[i].purchase < allCustomer[j].purchase){
                temp = allCustomer[i];
                allCustomer[i] = allCustomer[j];
                allCustomer[j] = temp;
            }
        }
}

// Print all customer
void printCustomer(customer* allCustomer, int number_of_customer){
	for(int i=0; i < number_of_customer; i++)
		cout << allCustomer[i].name << " with id: " << allCustomer[i].id << " purchase: " << allCustomer[i].purchase << endl;
}
