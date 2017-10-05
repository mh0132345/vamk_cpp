#include <iostream>
using namespace std;

int main(void) {

    int i = 0;
    char *str = "   Hello World \tclass\0";
    while (*(str+i) != '\0'){
        if(!isspace(*(str+i)))
            cout << *(str+i);
        i++;
    }

    return 0;
}

