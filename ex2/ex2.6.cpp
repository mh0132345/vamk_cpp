#include <iostream>
#include <cstring>
using namespace std;

struct Property{
    char house[10];
    unsigned short car;
    unsigned short boat;
};

void printInfo(Property *a_friend);
bool compare(Property *friend1, Property *friend2);

int main(void) {

    int i, j, len1, len2;
    Property friends1[] = { {"Yes", 0, 1}, {"Yes", 0, 2}, {"No", 0, 3} };
    Property friends2[] = { {"No", 0, 1}, {"Yes", 0, 1}, {"Yes", 0, 2} };
    len1 = sizeof(friends1)/sizeof(friends1[0]);
    len2 = sizeof(friends2)/sizeof(friends2[0]);

    for(i=0;i<len1;i++){
         for(j=0;j<len2;j++){
            if(compare(friends1+i, friends2+j)){
                printInfo(friends1+i);
            }
         }
    }
    return 0;
}

void printInfo(Property *a_friend){
    cout << a_friend->house << " " << a_friend->car << " " << a_friend->boat << endl;
}

bool compare(Property *friend1, Property *friend2){
    int max_len, i = 0;
    bool sameHouse = true;

    //compare string house
    if(strlen(friend1->house)>strlen(friend2->house))
        max_len = strlen(friend1->house);
    else max_len = strlen(friend2->house);

    while (i<max_len){
        if(*(friend1->house+i) != *(friend2->house+i)){
            sameHouse = false;
            break;
        }
        i++;
    }

    //compare two property
    if( sameHouse && friend1->boat == friend2->boat && friend1->car == friend2->car)
        return true;
    return false;
}
