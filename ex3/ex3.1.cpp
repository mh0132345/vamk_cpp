#include <iostream>
using namespace std;

int main(void){
	char *str1 = "Hello ";
    char *str2 = "World!";
    char *ptr = str1;
    char *&rptr = str1;
    rptr = str2;
	cout << ptr << str1;
	return 0;
}
