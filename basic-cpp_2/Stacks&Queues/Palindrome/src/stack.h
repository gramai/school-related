#define STACK_H_INCLUDED
#include <string>

#include <iostream>
using namespace std;
#define NMAX 20 // pre-processing directive



template<typename T>
class Stack {
    private:
        T stackArray[NMAX]; //un tableau de max NMAX elements
        int topLevel; //la tete de la pile, qui represente l’indice du dernier element du tableau stackArray: 0, 1, 2, ....

    public:
        void print(){
        for (int i = topLevel; i >= 0; i--)
            cout<<" Elem. nr "<<i<<" is " << stackArray[i]<<endl;
        }

        void push(T x) //met un element dans stack array
		 {
            if (topLevel >= NMAX - 1) //	verifie si stackArray a la dimension maximale
            {
                cout<<"The stack is full: we have already NMAX elements!\n";
                //on sort de la fonction sans rien faire
                return;
            }
            /* ajoute un element=> l’indice du dernier element du stackArray est incremente et on met la valeur du nouvel element dans le stackArray */
            stackArray[++topLevel] = x;
        }

      int isEmpty()
        {
            //retourne 1, si topLevel>=0, donc la pile a des elements
            // sinon, retourne 0
            return (topLevel < 0);
        }

    void isPalindrome(){
        char c2[NMAX];
        int ok=1;
        int i2=0;
        for (int i = topLevel; i >= 0; i--)
            c2[i2++]=stackArray[i];
        for (int i = topLevel; i >= 0; i--){
//            cout<< "stack is "<<stackArray[i]<< " char is "<<c2[i]<<endl;
            if(stackArray[i]!=c2[i])
                ok=0;
        }
        if(ok==1)
            cout<<"The string is palindrome";
        else
            cout<<"The string is not palindrome";
    }


     T pop() // extrait un element du stackArray et renvoie la nouvelle tete
     {
       if (isEmpty())
        {
            // on fait l’extraction seulement si la pile n’est pas vide
            cout<<"The stack is empty! \n";
            T x;
            return x;
        }
        return stackArray[topLevel--]; 	// topLevel decroit et on change le nouveau “top”
	//difference return stackArray[--topLevel] ?
    }

    T peek()
    {
    // retourne la tete de la pile
	    if (isEmpty())
        {
            // on fait l’extraction seulement si la pile n’est pas vide
            cout<<"The stack is empty! \n";
            T x;
            return x;
        }
        return stackArray[topLevel];
}

    Stack()
    { // constructeur
        topLevel = -1; //la pile est vide au debut
    }

    ~Stack() {} // destructeur
};
