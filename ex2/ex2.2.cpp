#include <iostream>
using namespace std;

struct Property{
    char house[10];
    char * car;
    char * boat;
};

int main(void) {

    int i;
    Property friends[] = { {"Yes", (char *)"0", (char *)"2"}, {"No", (char *)"1", (char *)"0"}, {"No", (char *)"0", (char *)"0"} };

    Property *p;
    p=friends;

    for(i=0; i<(sizeof(friends)/sizeof(friends[0])); i++) {
        cout<<"\nFriend "<<(i+1)<<" owns a house? "<<p[i].house;
        cout<<"\tFriend "<<(i+1)<<" owns "<<p[i].car<<"car(s).";
        cout<<"\tFriend "<<(i+1)<<" owns "<<p[i].boat<<"boat(s)."<<endl;
    }
    return 0;
}

