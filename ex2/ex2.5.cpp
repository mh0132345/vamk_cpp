#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    int i = 0, max_len;
    char *str1 = "HelloWorld\0";
    char *str2 = "HelloYou\0";
    if(strlen(str1)>strlen(str2))
        max_len = strlen(str1);
    else max_len = strlen(str2);

    while (i<max_len){
        if(*(str1+i) != *(str2+i))
            cout << *(str1+i) << " is different to " << *(str2+i) << endl;
        i++;
    }

    return 0;
}

