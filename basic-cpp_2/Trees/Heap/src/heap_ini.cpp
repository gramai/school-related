#include <stdio.h>
#include <iostream>

using namespace std;

///implementation du MIN HEAP a l'aide du vecteur
template<typename T> class Heap {
    public:
        T *H;
        int currentDim, maxDim;

		///constructeur avec la dimension maximale du heap
		///Attention! On commence a l'indice 1.
        Heap(int maxDim) {
            this->maxDim = maxDim;
            H = new T[this->maxDim + 1];
            currentDim = 0;
        }

		///fonction pour inserer un element dans le tas
        void insertElement(T x) {
            if (currentDim == maxDim) {
                fprintf(stderr, "Error!\n");
                return;
            }
            currentDim++;
            H[currentDim] = x;
            filterUp(currentDim);
	}

		///fonction qui retourne la racine, mais ne la supprime pas
		T peek() {
            if (currentDim == 0) {
                fprintf(stderr, "Error!\n");
                T x;
                return x;
            }

            return H[1];
        }

        ///fonction qui efface et affiche le plus petit element (la racine)
		T extractMin() {
            if (currentDim == 0) {
                fprintf(stderr, "Error!\n");
                T x;
                return x;
            }

            T minValue = H[1];
            H[1] = H[currentDim];
            currentDim--;
			if (currentDim > 0)
                filterDown(1);

            return minValue;
        }

		///fonction appelle par la fonction d'insertion pour maintenir les proprietes du heap
        void filterUp(int i) {
            int parent;
            T vaux;
            if ( (i + 1) % 3 == 0 )
                parent = i / 3 + 1;
            else{
                parent = i / 3;
            }

            while (i > 1 && H[parent] > H[i]) {
                vaux = H[parent];
                H[parent] = H[i];
                H[i] = vaux;

                i = parent;


                if ( (i + 1) % 3 == 0 )
                    parent = i / 3 + 1;
                else{
                    parent = i / 3;
                }

            }
        }

        ///fonction appelle par la fonction d'effacement pour maintenir les proprietes du heap
         void filterDown(int i) {
            T vaux;

            while (1) {
                if (3 * i + 1 > currentDim) { //checks if the right child has a valid dimension (exists in heap)
                    if (3 * i - 1 > currentDim) //if the right child and the left child have no valid dimension, there are no more children
                        break;
                    else
                    ///Si on a un deux ou un seul enfant
                        if(3 * i > currentDim) //checks dimension of the middle child
                            if (H[3 * i-1] < H[i]) { // swap the left child
                                vaux = H[3 * i - 1];
                                H[3 * i - 1] = H[i];
                                H[i] = vaux;
                                i = 3 * i - 1;
                            }
                            else
                                break;
                        else
                           if (H[3 * i] < H[i]) {
                                vaux = H[3 * i];
                                H[3 * i] = H[i];
                                H[i] = vaux;
                                i = 3 * i ;
                            }
                            else
                                break;
                    }
                else {
                        ///Voir lequel des enfants est le plus grand
                    if (H[3 * i - 1] <= H[3 * i ] && H[3 * i - 1] <= H[3 * i + 1] &&  H[3 * i - 1] < H[i]) {
                        vaux = H[3 * i - 1];
                        H[3 * i - 1] = H[i];
						H[i] = vaux;
                        i = 3 * i - 1;
                    }
                    else if ((H[3 * i ] <= H[3 * i - 1 ] && H[3 * i ] <= H[3 * i + 1] &&  H[3 * i ] < H[i])) {
                        vaux = H[3 * i ];
                        H[3 * i ] = H[i];
                        H[i] = vaux;
                        i = 3 * i ;
                    }
                    else if ((H[3 * i + 1] <= H[3 * i - 1 ] && H[3 * i + 1 ] <= H[3 * i - 1] &&  H[3 * i + 1] < H[i])) {
                        vaux = H[3 * i + 1];
                        H[3 * i + 1] = H[i];
                        H[i] = vaux;
                        i = 3 * i + 1;
                    }
                    else
                        break;
                }
            }
        }

        T Parent (int CI){
            return H[CI/2];
        }

        T Left_son(int CI){
            return H[3 * CI - 1];
        }

        T Middle_son(int CI){
            return H[3 * CI];
        }

        T Right_son(int CI){
            return H[3 * CI + 1];
        }

        void printHeap(){
            int i;
            for( i = 1; i <= currentDim; i++){
                cout<<H[i] <<" ";
            }
        }

        void print_on_Levels(){
            int i= 1;
            int cl = 0, aux;
            while (i < currentDim){
                aux = cl * 3;
                while (aux){
                    if(i <= currentDim){
                        cout<<H[i]<<" ";
                        i++;
                    }
                    else
                        break;
                    aux--;
                }
                if(i == currentDim){
                    cout<<H[i];
                }
                cout<<endl;
                if(cl == 0){
                    cout<<H[i]<<" "<<endl;
                    i++;
                }
                cl ++ ;
            }
        }


};


int main() {
    Heap<int> heap(100);
    heap.insertElement(10); heap.insertElement(6);
    heap.insertElement(7); heap.insertElement(8);
    heap.insertElement(5); heap.insertElement(13);
    heap.insertElement(6); heap.insertElement(0);
    heap.insertElement(4); heap.insertElement(2);
    heap.insertElement(9);


//    cout<<"L'element min:"<<heap.extractMin()<<endl;
    cout<<"The root is:"<<heap.peek()<<endl;
//    cout<<"L'element min:"<<heap.extractMin()<<endl;
    heap.printHeap();
    cout<<endl;
    heap.print_on_Levels();
    cout<<"Parent of element 5 is "<<endl;
    cout<<heap.Parent(5);

}










