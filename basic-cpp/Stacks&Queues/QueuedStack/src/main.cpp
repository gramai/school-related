#include <iostream>
#include "queue2.h"
#include <stack>
#include <math.h>
using namespace std;

template <typename T> class QueuedStack{
    private:
        Queue <T> q1,q2;
    public:
        QueuedStack(){};

    void push(T a){
        q1.enqueue(a);
        cout<<"Element pushed "<<a<<endl;
    }

    T pop (){
        while (q1.getSize()>1){
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        q1.dequeue();
        while(q2.getSize()>0){
            q1.enqueue(q2.peek());
            q2.dequeue();
        }
    }
    void printElements(){
        while(!q1.isEmpty()){
            cout<<"Element is "<<q1.peek()<<' '<<endl;
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        while(!q2.isEmpty()){
            q1.enqueue(q2.peek());
            q2.dequeue();
        }
        cout<<endl;
    }

};


template <typename T> class StackedQueue{
    private:
        stack <T> s1,s2;
    public:
        StackedQueue(){};

    void printElements(){
        int my_size=s1.size();
        while(!s1.empty()){
            cout<<"Element number "<<sqrt((s1.size()-my_size)*(s1.size()-my_size))<< " is "<<s1.top()<<endl;
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void enqueue(T x){
        s1.push(x);
    }

    void dequeue (){
        while(s1.size()>1){
        s2.push(s1.top());
        s1.pop();
        }
        s1.pop();
        while(s2.size()>0){
        s1.push(s2.top());
        s2.pop();
        }
    }
};


int main()
{

QueuedStack <int> q1;

q1.push(1);
q1.push(2);
q1.push(3);
q1.push(4);
q1.printElements();
q1.pop();
q1.printElements();
q1.pop();
q1.push(55);
q1.printElements();

}
