#include "stack.h"
/*
English
The user enters a string. Using a stack, verify if the string
is palindrom or not.
Example:
santa at nas

*/

/*
French
L’utilisateur introduit une suite de caractères au
clavier. A l’aide de la pile, on doit vérifier si la suite
est palindrome ou non. (e.g.: rever, tot)
*/

int main()
{
Stack <char> myStack;

string s1;
cout<<"Please enter a string: "<<endl;

std::getline(std::cin, s1);

//cout<<s1<<endl;

for (int i = 0; i<s1.length();i++){
    if(s1.at(i) != ' ')
        myStack.push(s1.at(i));
}
//myStack.print();
myStack.isPalindrome();

}




