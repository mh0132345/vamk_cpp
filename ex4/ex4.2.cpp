#include <iostream>
#include <cstring>
using namespace std;

char** create_names(char ** names, int size_of_names);
void print_names(char **field, int size_of_names);
void sort(char** names, int size_of_names);

int main(){
    int size_of_names, i;

	cout << "How many names do you want to input? ";
	cin >> size_of_names;
	char** names = new char*[size_of_names];

	names = create_names(names, size_of_names);
	sort(names, size_of_names);
	print_names(names, size_of_names);
    return 0;
}


// Create array of names
char** create_names(char** names, int size_of_names){
    for(int i = 0; i < size_of_names; i++){
        names[i] = new char [80];
        cout << "Input names[" << i << "]: ";
        cin >> names[i];
    }
    return names;
}

// Sort array of string in ascending order
void sort(char** names, int size_of_names){
    int i, j;
    char temp[80];
	for(i=0;i<size_of_names;i++)
        for(j=i+1;j<size_of_names;j++){
            if(strcmp(names[i],names[j]) > 0){
                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
            }
        }
}

// Print all names
void print_names(char ** names, int size_of_names){
    for(int i = 0; i < size_of_names; ++i)
        cout << names[i] << endl;
}
