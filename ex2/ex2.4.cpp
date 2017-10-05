#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

    int i, j, n;
    char *t;
    char str[80];
    cout << "Input the string: ";
    cin >> str;
    n = strlen(str);

    for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(*(str+i) > *(str+j)){
                int temp = *(str+i);
                *(str+i)= *(str+j);
                *(str+j)= temp;
			}
		}
	}

    cout << str;



    return 0;
}

