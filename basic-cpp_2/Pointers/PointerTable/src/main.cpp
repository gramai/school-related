#include <iostream>
#include <string.h>
using namespace std;

char *getDep (char *p){
    char *space = " ";
    while (*p){
        if(*p == *space){
            cout<<"Le département est ";
            cout<<*(++p);
            cout<<*(++p);
        }
        else{
        *(p++);
        }
    }
}
int main()
{
    cout<< "Req. 1 "<<endl;
    int ar[10];
    int *p1;
    cout<<"Insert int nr. 1 ";
    cin>>(ar[0]);

    p1=&ar[0];
    for(int i=1;i<=5;i++){
        cout<<"Insert int nr. "<<i + 1<<" ";
        cin>>*(++p1);
    }

// EX. 1

    for(int i=0;i<6;i++){
        cout<<ar[i]<<endl;
    }

    cout<<endl<<"Req. 2"<<endl;
// EX. 2
    cout<<endl;
    for (int i = 0; i < 6 ; i ++){
        cout<<*(p1--)<<endl;
    }

    cout<<endl<<"Req. 3"<<endl;
//EX. 3
    string dep, dep2;
    cout<< "Insert city and department ";
    cin>>dep;
    cin>>dep2;
    dep = dep + " " + dep2;
    char *p;
    p = &dep[0];
    getDep(p);

}
