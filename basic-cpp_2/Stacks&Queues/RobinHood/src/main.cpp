#include <iostream>
#include "queue2.h"
#include <stack>
//For checking performance
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

//Constants
int no_of_houses=10;
int rich_guy_house=3;
int robbed[500];


/*
The picking algorithm is based on the nextPrime strategy, meaning that the next house that will be robbed is picked after not robbing (int)nextPrime houses.
    e.g. : Starting at house nr.1, house 1 will be robbed. First prime is = 2, house 2 will be sparred and house 3 will be robbed (nextPrime=next_victim_in_n_houses)
        After that, 3 houses are sparred (4,5,6) -> house 7 will be robbed etc.
If Robin Hood reaches the end of the city, next_victim_in_n_houses continues to count from the beginning.
    e.g. : Starting at house nr.1 (no_of_houses=5), house 1 will be robbed. First prime is = 2, house 2 will be sparred and house 3 will be robbed (nextPrime=next_victim_in_n_houses)
        After that, 3 houses are sparred (4,5,1) -> house 2 will be robbed etc.

To find out what rich_guy_choice is (first house that has to be chosen so that rich_guy_house remains last), the algorithm parses through all the available choices (0->no_of_houses).
If lastVictim==rich_guy_house, the algorithm returns the number of the first victim's house and stops. If next_victim_in_n_houses gets to robb the rich_guy_house, the algorithm checks
if the next house is a better choice as the first Victim.
*/


//Finds what the next prime number is, another Prime number being given.
//Performance can be improved if every nextPrime is saved in a globally declared stack
stack <int> primes;

int nextPrime(int lastPrime){
    stack <int> aux; // empty stack used as auxiliary
    bool ok=1; // used as trigger is a number !=prime
    int nextPrime=lastPrime+1; // checks if next value after lastPrime is prime
    int aux_pop,my_prime;
    if (nextPrime > primes.top()){ //checks if value is bigger than the last found prime number, to know whether value should be searched for or is already found
        while(true){
            for(int i=2;i<=nextPrime/2;i++){ //checks if any divisor exists
                if(nextPrime%i==0)
                    ok=0; // if a divisor is found, ok is set to 0, meaning that nextPrime !=prime
            }
            if(ok==1){
                primes.push(nextPrime);// add next found prime to primes stack
                return nextPrime; //returns the prime number needed for next_victim_in_n_houses
            }
            else{//searches for the next prime
            ok=1;
            nextPrime++;
            }
        }
    }
    else{
        while(nextPrime<primes.top() || primes.empty()){ //stops when last prime is bigger than nextPrime, chooses forelast prime from pe primes stack afterwards
            aux_pop=primes.top();
            aux.push(aux_pop);
            primes.pop();
        }
        my_prime=aux.top();
        while(!aux.empty()){ // puts all the prime numbers back in the primes stack
            aux_pop=aux.top();
            primes.push(aux_pop);
            aux.pop();
        }
        return my_prime; //returns correct nextPrime
    }
}



void createCity(int no_of_houses, Queue <int> &houses){ //creates queue of needed dimension
    for(int i=1;i <= no_of_houses; i++){
        houses.enqueue(i); // adds house_number value to each element of the queue. e.g. : houses will contain the elements 1, 2, 3, 4, 5 if no_of_houses==5
    }
}

void rearrangeCity(Queue <int> &houses){ // resets the arrangement of the city
    int no_of_houses=houses.getSize();
     cout<<"Rearranging City "<<endl;
    for (int i = 1; i <= no_of_houses; i++){// removes all elements from the city
        houses.dequeue();
        robbed[i]=0;
//        cout<<"houses top "<<houses.getHead();//<<" "<< "peek " << houses.peek()<< " ";
    }
    while(!houses.isEmpty()){
        houses.dequeue();
    }

    for (int i = 1; i <= no_of_houses; i++){ // adds the elements in correct order
        houses.enqueue(i);
    }
}

void chooseHouse(int next_victim_in_n_houses, Queue <int> &houses){ //chooses next house to robb by moving the chosen_house to the head of the queue
    cout<<endl<<endl;
    cout<<"Next victim in "<<next_victim_in_n_houses<<" houses"<<endl;
    while(next_victim_in_n_houses > 0){
        int dequeued=houses.dequeue();// saves head to be able to add it to the tail afterwards. This option has been chosen to be able to print the "spared" houses, for debugging purposes
//        cout<<dequeued<<" spared ";
        houses.enqueue(dequeued);
        next_victim_in_n_houses--;
    }
    cout<<endl;
}

void checkRobbedArray(){ //prints the array of robbed houses to the console. Each element is either a 0 (not robbed) or a 1 (robbed)
    for(int i=0;i<=no_of_houses;i++){
        cout<<endl;
        cout<<" Robbed["<<i<<"]= "<<robbed[i]<<" ";
    }
}

int lastVictim(int beforeVictim, Queue <int> houses,int rich_guy_house){ // returns the last victim, given a first victim under the beforeVictim parameter
    int victim_in_n_houses=beforeVictim,robbed_count=0;
    while (true){
        cout<<"Houses robbed until now: "<<robbed_count;
//Uncomment next line if you want to see array of robbed houses. Mention: Robbed[0] is not used, house numbers coincide with their indices e.g. : Robbed[1]=1 means that house no.1 was robbed.
//        checkRobbedArray();
        chooseHouse(victim_in_n_houses, houses);//house is passed by refference, to be able to modify the arrangement of the city
        if(robbed_count==houses.getSize()-1){
            for (int i = 1;i <= houses.getSize(); i++)
                if(robbed[i]==0)
                    return i;// returns the number of the house that was robbed
            return -2;
        }
        if(robbed[houses.peek()]==0){ // robbs house if not already robbed
            cout<<"Robbing "<<houses.peek()<<endl;
            robbed[houses.peek()]=1;
            robbed_count++; // increments the number of robbed houses
            if(houses.peek()==rich_guy_house) // if the house that is robbed belongs to the rich guy, the algorithm starts again with beforeVictim++
                return -1;
        }
        else{
            cout<<"Chosen "<<houses.peek()<<endl;
            cout<<"Already robbed this, moving on"<<endl;
        }
    if(robbed_count==1)
        victim_in_n_houses=1; //initialisez vitcim_in_n_houses so that primes will start with 2,3,5... and not with beforeVictim,nextPrime(beforeVictim)
    victim_in_n_houses=nextPrime(victim_in_n_houses);

}
}

int firstVictim(int rich_guy_house, Queue <int> houses){ //returns the first house that has to be robbed so that the rich guy's house remains intact
    int last_victim;
    for(int i = 1; i <= houses.getSize(); i ++){
        cout<<endl;
        rearrangeCity(houses);
        cout<<"First choice is "<<i<<endl;
        last_victim=lastVictim(i-1,houses,rich_guy_house);
        if(last_victim==rich_guy_house){
            return i;
        }
    }
    return -1;
}

int main()
{
primes.push(1); //add 1 as first prime to (stack)primes pass the 'Segmentation Fault' error when trying to access primes.top() and primes.empty()==1
primes.push(2);
primes.push(3);

    std::clock_t start;
    double duration;
    start = std::clock();

// Don't forget to change constants at the beginning of the file!
    Queue <int> houses; //Queue of houses = city
    createCity(no_of_houses, houses); //creates a city with no_of_houses houses
    int rich_guy_choice=firstVictim(rich_guy_house,houses); //returns the first house that has to be robbed so that rich_guy_house remains last
    if(rich_guy_choice!=-1)
        cout<<"Rich guy choice is "<<rich_guy_choice;
    else
        cout<<"No matter the coice, he will get robbed (guess it's an unlucky number)";
        // There are some combinations that always return -1, meaning that no matter what house is chosen first, the rich_guy_house will be robbed before the last one
        // e.g. : for no_of_houses=10 and rich_guy_house=10

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    cout<<endl;
    cout<<"Duration is : "<< duration <<endl;
}
