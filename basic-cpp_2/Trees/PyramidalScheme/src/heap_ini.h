#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// This is the header used and modified in the lab
// The following modifications have been made:
    // 1. Added to_string_own function, to print details of the employees instead of printing H[i] which is impossible in our case
    // 2. Modified filters kriterion, instead of H[i], H[i].getExp() was used, meaning that the experience is the criterion in which the employees are added
    // 4. Added parseHeap() function that calculates and sets all salaries. parseHeap() contains set_base_salaries and set_salaries.

int b1_salary = 1000,b2_salary = 2000,b3_salary = 3000,b4_salary = 4000,b5_salary = 5000;

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




        int findElement(int exp){
            if (currentDim == 0) {
                fprintf(stderr, "Error findElement!\n");
                T x;
                return 0;
            }
            for (int i = 1; i <= currentDim; i++){
                if(H[i].getExp() == exp){
                    return i;
                }
            }
        }

		///fonction pour inserer un element dans le tas
        void insertElement(T x) {
            if (currentDim == maxDim) {
                fprintf(stderr, "Error insertElement!\n");
                return;
            }
            currentDim++;
            H[currentDim] = x;
            filterUp(currentDim);
        }

    int pow_2[10] = {0,1,2,4,8,16,32,64,128}; // array with powers of 2 to calculate level of heap element

        int find_level(int i){ //returns the level of a certain i'th element
            for (int j = 0; j < 10; j++){
                if(i < pow_2[j]){
                    return j - 1;
                }
            }
        }


        void set_base_salaries(){ //sets base salaries for all members
            int last_level = find_level(currentDim);
            int level;
            for (int i = 1; i <= currentDim; i++){
                level = find_level(i);
                H[i].set_base_salary((last_level - level + 1)* 1000); // base salary criterion is level (1 is last level) * 1000
            }
        }

        float salaries = 0;
        float find_salaries(int i){ // recursive function that finds salaries of all subordonates
                int j = i;
                float salaries = 0;
                j *= 2;

                while (j <= currentDim){
                    j *= 2;
                }

                j = int(j / 2);
                while ( j > i){
                    salaries += H[j].get_salaire_total(); // adds the salary of the left child, if there is a right child, its salary and the salaries of it subordonates is calculated recursively
                    if ( j + 1 <= currentDim){
                        salaries += H[j + 1].get_salaire_total();
                        int k = j + 1;
                        salaries += find_salaries(k);
                        }
                    j = int(j / 2);
                }
        }

        /// recalculates and sets all salaries
        void parseHeap(){ // sets base salaries and total salaries
            set_base_salaries();
            int i;
            float total_salaries;
            for (i = currentDim; i >= 1; i--){
                total_salaries = find_salaries(i);
                H[i].set_total_salary(H[i].get_salaire_base() + total_salaries / 10);
            }
        }
		///fonction qui retourne la racine, mais ne la supprime pas
		T peek() {
            if (currentDim == 0) {
                fprintf(stderr, "Error peek!\n");
                T x;
                return x;
            }

            return H[1];
        }

        ///fonction qui efface et affiche le plus petit element (la racine)
		void extractMin() {
            if (currentDim <= 0) {
                fprintf(stderr, "Error extractMin!\n");
                throw std::invalid_argument( "Reached negative position" );
                T x;
            }

            H[1] = H[currentDim];
            currentDim--;

            cout<<"currentDim is "<<this->currentDim<<endl;

            if (currentDim > 0){
                filterDown(1);
            }

        }

		///fonction appelle par la fonction d'insertion pour maintenir les proprietes du heap
        void filterUp(int i) {
            int parent;
            T vaux;

            parent = i / 2;
            while (i > 1 && H[parent].getExp() < H[i].getExp()) {
                vaux = H[parent];
                H[parent] = H[i];
                H[i] = vaux;

                i = parent;
                parent = i / 2;
            }
        }

        ///fonction appelle par la fonction d'effacement pour maintenir les proprietes du heap
         void filterDown(int i) {
            T vaux;

            while (1) {
                if (2 * i + 1 > currentDim) {
                    if (2 * i > currentDim)
                        break;
                    else
                    ///Si on a un seul enfant
                        if (H[2 * i].getExp() > H[i].getExp()) {
                            vaux = H[2 * i];
                            H[2 * i] = H[i];
                            H[i] = vaux;
                            i = 2 * i;
                        }
                        else
                            break;
                    }
                else {
                        ///Voir lequel des enfants est le plus grand
                    if (H[2 * i].getExp() >= H[2 * i + 1].getExp() && H[2 * i].getExp() > H[i].getExp()) {
                        vaux = H[2 * i];
                        H[2 * i] = H[i];
						H[i] = vaux;
                        i = 2 * i;
                    }
                    else
                    if (H[2 * i + 1].getExp() >= H[2 * i].getExp() && H[2 * i + 1].getExp() > H[i].getExp()) {
                        vaux = H[2 * i + 1];
                        H[2 * i + 1] = H[i];
                        H[i] = vaux;
                        i = 2 * i + 1;
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
            return H[2 * CI];
        }

        T Right_son(int CI){
            return H[2 * CI + 1];
        }

        void printHeap(){
            int i;
            for( i = 1; i <= currentDim; i++){
                cout<<H[i] <<" ";
            }
        }

        string to_string_own(int i){
            string exp = to_string(H[i].getExp());
            string salaire_base= to_string(H[i].get_salaire_base());
            string salaire_total= to_string(H[i].get_salaire_total());
            string level = to_string(find_level(i));
            return "LEVEL: "+level+"; Nom : " + H[i].get_nom() + "; Prenom : " + H[i].get_prenom() + "; EXP : " + exp + "; Salaire de base : " + salaire_base+ "; Salaire total : " + salaire_total;
        }


        //c) (0.5p) Utilisez un algorithme pour afficher les informations des tous les employés par niveau.
        void print_on_Levels(){
            int i= 1;
            int cl = 1, aux;
            while (i < currentDim){
                aux = (cl - 1) * 2 ;
                if (aux == 0)
                    aux = 1;
                while (aux){
                    if(i <= currentDim){
                        cout<<to_string_own(i)<<endl;
                        i++;
                    }
                    else
                        break;
                    aux--;
                }
                cout<<endl<<endl<<endl;
                if(cl == 0){
                        cout<<to_string_own(i)<<endl;
                    i++;
                }
                cl ++ ;
            }
        }

        //d) (3p) Implémentez trois instructions possibles qui peuvent être introduites du clavier :
        //i) Instruction 1 : Afficher si notre entreprise est entière ou non. On dit que l͛entreprise est
        //eŶtiğre si tous les Ŷœuds de l͛arbre ont zéro ou deux fils.

        int entiere(){
            int forelast_level = find_level(currentDim) - 1;
            int i,j;
            int ok = 1;
            i = pow(forelast_level, 2) - 1; // last node of the forelast level
            while ( ok == 1 && i > pow(forelast_level - 1, 2)){
                if( 2 * i + 1 > currentDim){
                    if (2 * i <= currentDim)
                        return 0;
                }
                i--;
            }
            return 1;
        }

        void find_supervisor(int i, int j){
            int fni, sni;
            fni = findElement(i); //first node indice
            sni = findElement(j);
            if (find_level(fni) == find_level(sni)){
                if(floor(fni / 2) == floor(sni / 2))
                    cout<<"Le plus proche patron qui peut résoudre le conflit est "<<H[int(floor(fni / 2))].getExp();
                else
                    cout<<"Le plus proche patron qui peut résoudre le conflit est "<<H[int(floor(sni / 4))].getExp();
            }
            else{
                if (fni > sni )
                    {
                        int aux = fni;
                        fni = sni;
                        sni = aux;
                    }
                int potential_sup = floor(float(fni) / 2);
                int ok = 0;
                int br_ind = 4;
                while (potential_sup > 1  && ok == 0){
                    if (potential_sup == floor(float(sni) / br_ind))
                        {
                        cout<<"Le plus proche patron qui peut résoudre le conflit est "<<H[potential_sup].getExp();
                        ok = 1;
                        }
                    br_ind *= 2;
                    potential_sup = floor(float(fni) / ( (br_ind) * 2));
                }
                cout<<"Le plus proche patron qui peut résoudre le conflit est "<<H[potential_sup].getExp();
                }

        }

};











