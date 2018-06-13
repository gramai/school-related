#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <typename T>
struct Noeud
{ //structure pour un noeud de la liste; contient l'information et les 2 pointeurs
    T info;
    Noeud <T> *next; //pointeur au suivant noeud
    Noeud <T> *prev; //pointeur au noeud precedent
};

template <typename T>
class LinkedList
{
    public:
        Noeud <T> *pfirst; //pointeur au premier noeud
        Noeud <T> *plast; //pointeur au dernier noeud

    void addFirst(T x)
    { //fonction pour ajouter l'information x dans un nouveau noeud, sur la premiere position

        Noeud <T> *paux; //le nouveau noeud
        paux = new Noeud<T>;

        paux->info = x;
        paux->prev = NULL;
        paux->next = pfirst;

        if (pfirst != NULL)
            pfirst->prev = paux;

        pfirst = paux; //on fait la connexion entre l'ancien "first" et le nouveau noeud

        if (plast==NULL)
            plast=pfirst;
    }

    void addLast(T x)
    {//fonction pour ajouter l'information x dans un nouveau noeud, sur la derniere position

        Noeud<T> *paux;

        paux = new Noeud <T>;
        paux->info = x;
        paux->prev = plast;
        paux->next = NULL;

        if (plast != NULL)
            plast->next = paux;

        plast = paux;

        if (pfirst == NULL)
            pfirst = plast;
    }

    T getInfo (Noeud<T>* p)
    {
        return p->info;
    }

    void removeFirst()
    { //fonction pour supprimer le premier element
        Noeud<T>* paux;

        if (pfirst != NULL)
        {

            paux = pfirst->next;

            if (pfirst == plast)
                plast = NULL;

            delete pfirst; //on efface le premier element

            pfirst = paux;  //le suivant devient le nouveau premier

            if (pfirst != NULL)
                pfirst->prev = NULL;
        }
        else
            cout<<"The list is empty"<<endl;
    }

    void removeLast()
    { //fonction pour supprimer le dernier element
        Noeud <T> *paux;

        if (plast != NULL)
        {
            paux = plast->prev;

            if (pfirst == plast)
                pfirst = NULL;

            delete plast; //on efface le dernier element;

            plast = paux; //le precedent devient le nouveau "last"
            if (plast != NULL)
                plast->next = NULL;
        }
        else
            cout<<"The list is empty"<<endl;
    }
    Noeud <T>* findFirstOccurrence(T x)
    { //cherche la premiere apparition du noeud avec l'info x
        Noeud<T> *paux;

        paux = pfirst;
        while (paux != NULL)
        {
            if (paux->info == x)
                return paux;
            paux = paux->next;
        }
        return NULL;
    }

    Noeud <T>* findLastOccurrence(T x)
    { //cherche la derniere apparition du noeud avec l'info x
        Noeud <T> *paux;

        paux = plast;
        while (paux != NULL) {
            if (paux->info == x)
                return paux;
            paux = paux->prev;
        }

        return NULL;
    }

    void removeFirstOccurrence(T x)
    { //efface la premiere apparition du noeud avec l'info x
        Noeud <T> *px;

        px = findFirstOccurrence(x); //px est l'element qu'on doit effacer

        if (px != NULL)
        {//on doit refaire les connexions des pointeurs
            if (px->prev != NULL)
                px->prev->next = px->next;

            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) // si px == pfirst
                pfirst = px->next;

            if (px->next == NULL) // si px == plast
                plast = px->prev;

            delete px; //mainteneant on peut l'effacer
        }
    }

    void removeLastOccurrence(T x)
    { //efface la derniere apparition du noeud avec l'info x
        Noeud <T> *px;

        px = findLastOccurrence(x);

        if (px != NULL)
        {
            if (px->prev != NULL)
                px->prev->next = px->next;

            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) // si px == pfirst
                pfirst = px->next;

            if (px->next == NULL) // si px == plast
                plast = px->prev;

            delete px;
        }
    }

    int isEmpty()
    { //verifie si la liste est vide
        return (pfirst == NULL);
    }

    LinkedList()
    { //constructeur
        pfirst = plast = NULL;
    }

};

