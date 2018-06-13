#include <stdio.h>
#include <iostream>
#define NMAX 1000

using namespace std;
template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail,size;
    public:

        void enqueue(T x) {
            if (tail == NMAX) { //on verifie si la queue est pleine
                cout<<"Error 101 - The queue is full!\n";
                return;
            }
            queueArray[tail] = x; //on ajoute l’element a la fin de la queue
            tail = (tail + 1) % NMAX;
            size++;
        }

        T dequeue() {
            if (isEmpty()) { //on verifie si la queue est vide
                cout<<"Error 102 - The queue is empty!\n";
                T x;
                return x;
            }
            T x = queueArray[head]; //on retourne l’element de la tete
            head = (head + 1) %NMAX;
            size--;
            return x;   }

        T peek() {
            if (isEmpty()) {//on verifie si la queue est vide
                cout<<"Error 103 - The queue is empty!\n";
                T x;
                return x;
            }
            return queueArray[head]; //on retourne l’element situe dans la tete de la queue
        }

        int isEmpty() {
            return (size==0); //si head et tail representent les memes indices, la queue est vide
        }

        int getHead(){
            return head;
        }
        int getTail(){
            return tail;
        }
        int getSize(){
            return size;
        }

    Queue() {
        head = tail = size = 0; // la queue est vide au debut
    }
};
