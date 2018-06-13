#include <iostream>
#include <stack>
#define NMAX=10
using namespace std;

// A class is created to better implement the problem
class Bucket{
    private:
        stack <int> liter_list; // Is a stack where each element can be int(1)
        int bucket_size;// Max size of bucket
    public:
        Bucket(int bucket_size){
            this->bucket_size=bucket_size;
        }
        int getLiters(){
            return liter_list.size();
        }

        void emptyBucket(){
                liter_list.pop();
        }

        // Transfers from another bucket until target_bucket is full or donor_bucket is empty
        void fillBucket(Bucket &donor_bucket){
                while(liter_list.size()<bucket_size && !donor_bucket.isEmpty())
                    {donor_bucket.emptyBucket();
                     liter_list.push(1);
                    }
        }

        // Method only used for filling the 20 liters bucket
        void fillBucket(){
            while(liter_list.size()<bucket_size)
                liter_list.push(1);
        }

        int getSize(){
            return bucket_size;
        }

        bool isEmpty(){
            return (liter_list.size()==0);
        }
        bool isFull(){
            return (liter_list.size()==bucket_size);
        }
};

// Returns state for all 3 buckets (L1, L2, L3)
void return_state(Bucket b1, Bucket b2, Bucket b3, int &state){
    cout<<"State "<<state<<endl;
    cout<<"Bucket with max capacity "<<b1.getSize()<<" l holds "<<b1.getLiters()<<" l of wine "<<endl;
    cout<<"Bucket with max capacity "<<b2.getSize()<<" l holds "<<b2.getLiters()<<" l of wine "<<endl;
    cout<<"Bucket with max capacity "<<b3.getSize()<<" l holds "<<b3.getLiters()<<" l of wine "<<endl;
    cout<<endl;
    state++;
}

// int no_of_liters is the number of the desired liters to measure
void measure_liters(int no_of_liters,Bucket &b8, Bucket &b5,Bucket &b20){
    // Checks if any bucket contains the desired no_of_liters
    int state=1;
    while (b8.getLiters()!=no_of_liters && b5.getLiters()!=no_of_liters  && b20.getLiters()!=no_of_liters  ){
/*
The algorithm is a circular one and goes like this:
b20->b8->b5
Meaning that:
    -1)b8 is filled from b20 only when b8 is empty
    -2)b5 is filled from b8 every time b5 contains <5l of wine
        -is the main element because the quantity will vary between b8 and b5
    -3)b5 is emptied in b20 when b5 is full

    -e.g. :b20=20, b8=0, b5=0; -> b20=12, b8=8, b5=0; ->b20=12, b8=3, b5=5;
               ->b20=17, b8=3, b5=0; ->b20=17, b8=0, b5=3; ... etc
*/

        if(b8.isEmpty()){
            b8.fillBucket(b20);
            return_state(b8,b5,b20,state);
        }
        else if(b5.isEmpty()){
            b5.fillBucket(b8);
            return_state(b8,b5,b20,state);
        }
        else if(b5.isFull()){
            b20.fillBucket(b5);
            return_state(b8,b5,b20,state);
        }
        else if (!b5.isFull())
            {b5.fillBucket(b8);
             return_state(b8,b5,b20,state);
            }
        else{
        cout<<"Other state, quitting"<<endl<<endl;
        return;
        }
    }
    if(b8.getLiters()==no_of_liters)
        cout<<"Success! Measured "<<no_of_liters<<" l in Bucket with 8l max capacity "<<endl<<endl;
    else if(b5.getLiters()==no_of_liters)
        cout<<"Success! Measured "<<no_of_liters<<" l in Bucket with 5l max capacity "<<endl<<endl;
    else{
        cout<<"Success! Measured "<<no_of_liters<<" l in Bucket with 20l max capacity "<<endl<<endl;
    }
}

void reset_state(Bucket &b1,Bucket &b2,Bucket &b3){
    while(!b1.isEmpty() || !b2.isEmpty() || !b3.isEmpty()){
        if(!b1.isEmpty())
            b1.emptyBucket();
        if(!b2.isEmpty())
            b2.emptyBucket();
        if(!b3.isEmpty())
            b3.emptyBucket();
    }
    b3.fillBucket();
}


int main()
{
// I thought that it would be more interesting to be able to measure any quantity of liters
    int no_of_liters=0; // inputs desired no. of liters to measure
    bool entered=0; // checks if there existed a first attempt to insert no_of_lites
    while(no_of_liters<1 || no_of_liters>20) //asks user to input a correct value of no_of_liters
    {   if(entered==0){
            cout<< "Insert number of desired liters to measure (1-20)"<<endl;
            cin>>no_of_liters;
            entered=1;
        }
        else{
            cout<<"Please insert a number between 1 and 20 "<<endl;
            cin>>no_of_liters;
        }
    }
// Create 3 buckets with max capacities of 8,5 and 20 liters
    Bucket b8 = Bucket(8);
    Bucket b5 = Bucket(5);
    Bucket b20 = Bucket(20);
    b20.fillBucket(); // fills the bucket with 20l max capacity

    measure_liters(no_of_liters,b8,b5,b20);

}
