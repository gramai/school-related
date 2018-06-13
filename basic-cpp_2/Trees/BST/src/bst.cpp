#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int nb_niv = 0;
//definition de maniere recursive
template<typename T> class BinarySearchTree {
    public:
        //le noeud courant contient des references: vers la racine, enfant gauche, enfant droit, parent
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        //information du noeud courant
        T *pinfo;

        //constructeur
        BinarySearchTree() {
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
            parent = NULL;
        }

        void setInfo(T info) {
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x) {
            if (pinfo == NULL)
                setInfo(x);
            else
                insert_rec(x);
        }

        //insertion recursive pour trouver la position de l'info
        void insert_rec(T x) {
            int next_son;
			if (x <= (*pinfo))
                next_son = 0; //gauche
            else
                next_son = 1; //droit

            if (next_son == 0) {  // enfant gauche
                if (left_son == NULL) {

                    //info
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;

                    //liaisons
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                } else
                    left_son->insert_rec(x); //on va plus loin a la gauche
            } else { // enfant droit

                if (right_son == NULL) {

                    //info
                    right_son = new BinarySearchTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;

                    //liaisons
                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                } else
                    right_son->insert_rec(x);
            }
        }

        //trouver le noeud qui a l'information x
		BinarySearchTree<T>* find(T x) {
            BinarySearchTree<T> *rez;

            if (pinfo == NULL)
                return NULL;

            if ((*pinfo) == x)
                return this;

            if (x <= (*pinfo)) { //information plus petite
                if (left_son != NULL)
                    return left_son->find(x);
                else
                    return NULL;
            } else {            //information plus grande
                if (right_son != NULL)
                    return right_son->find(x);
                else
                    return NULL;
            }
        }

        //effacer le noeud avec une certaine info
        void removeInfo(T x) {
            BinarySearchTree<T> *t = find(x);
            if (t != NULL)
                t->remove();
        }

		void remove() {
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL) { //pas d'enfant gauche ou droit du noeud courant
                if (parent == NULL) { // this == root, efface la racine
                    delete this->pinfo;
                    root->pinfo = NULL;  //l'arbre reste vide
                } else {
                    if (parent->left_son == this) //le noeud courant est un enfant gauche
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL; //le noeud courant est un enfant droit

                    delete this->pinfo; //efface info du noeud curant
                    delete this;
                }
            } else { //enfant gauche et / ou droit

                if (left_son != NULL) { // enfant gauche != NULL
                    p = left_son;
                    while (p->right_son != NULL) //trouver le plus grand element parmis les descendants de l'enfant gauche
                        p = p->right_son;
                }
                else { // enfant droit != NULL
                    p = right_son;
                    while (p->left_son != NULL) //trouver le plus petit element parmis les descendants de l'enfant droit
                        p = p->left_son;
                }

                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux; //on met dans this la nouvelle valeur

                p->remove(); //on efface l'ancienne valeur
            }
        }

        //parcours GRD
        void inOrderTraversal() {
            if (left_son != NULL)
                left_son->inOrderTraversal();

            cout<< *pinfo<<" ";

            if (right_son != NULL)
                right_son->inOrderTraversal();
        }

        //parcours RGD
        void preOrderTraversal(){
            cout<< *pinfo<<" ";

            if(left_son != NULL)
                left_son->preOrderTraversal();

            if(right_son != NULL)
                right_son->preOrderTraversal();
        }
        //parcours GDR
        void postOrderTraversal(){
            if(left_son != NULL)
                left_son->postOrderTraversal();

            if(right_son != NULL)
                right_son->postOrderTraversal();

            cout<< *pinfo<<" ";
        }

        void plusPetite(){
            if(left_son != NULL)
                left_son->plusPetite();
            else{
                cout<<"Smallest value is "<<*pinfo<<endl;
            }
        }

        void plusGrande(){
            if(right_son != NULL)
                right_son->plusGrande();
            else{
                cout<<"Biggest value is "<<*pinfo<<endl;
            }
        }

        void no_niv(int level){
            if(level > nb_niv){
                nb_niv = level;
            }
          if (left_son != NULL)
                left_son->no_niv(level + 1);
          if (right_son != NULL)
                right_son->no_niv(level + 1);
        }

};



int main() {

    BinarySearchTree<int> *r = new BinarySearchTree<int>; //pointeur vers la racine

    r->insert(6);
    r->insert(8);
    r->insert(1);
    r->insert(9);
	r->insert(10);
    r->insert(4);
    r->insert(13);
    r->insert(1);
    r->insert(12);
    cout<<"In order traversal:"<<endl;
    r->inOrderTraversal();
    cout<<endl;
    cout<<"Pre order traversal:"<<endl;
    r->preOrderTraversal();
    cout<<endl;
    cout<<"Post order traversal:"<<endl;
    r->postOrderTraversal();
    cout<<endl;
    r->plusPetite();
    r->plusGrande();

    r->no_niv(0);
    nb_niv++;
    cout<<"Height is "<<nb_niv<<endl;

    cout<<"Search element 100 "<<endl;
    cout<< r->find(100)<<endl;


    cout<<"Search element 1 "<<endl;

    cout<< r->find(1)<<endl;


    cout<<"Search element 4 "<<endl;

    cout<< r->find(4)<<endl;

    cout<< "Remove 6th element"<<endl;
    (r->find(6))->remove();

    cout<<"In order Traversal"<<endl;
    r->inOrderTraversal();

    return 0;

}




