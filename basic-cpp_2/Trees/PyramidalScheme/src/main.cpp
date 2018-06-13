#include <iostream>
#include "heap_ini.h"
#include <fstream>
using namespace std;


// a) (1p) Créer la classe/struct Employe avec les champs nom, prénom, salaire de base, salaire total,
//expérience. Ajoutez les constructeurs et les méthodes nécessaires.
class Employee{
public:
    string nom, prenom;
    int exp;
    float salaire_base = 0, salaire_total = 0;
Employee (){} // empty constructor to match the structure of heap_ini.h .
              // all will be initialised in the function emp_init

void emp_init(string nom, string prenom, int exp){
    this->nom = nom;
    this->prenom = prenom;
    this->exp = exp;
}

string getNom(){
return nom;
}

int getExp(){
return this->exp;
}

string get_nom(){
    return nom;
}

string get_prenom(){
    return prenom;
}


void set_base_salary(int sb){
    this->salaire_base = sb;
}

void set_total_salary(int st){
    this->salaire_total = st;
}


float get_salaire_base(){
    return salaire_base;
}

float get_salaire_total(){
    return salaire_total;
}

};

void instruction_1(Heap<Employee> company_structure){
    int entiere = company_structure.entiere();
    if (entiere == 0){
        cout<<"L'entreprise n'est pas entiere"<<endl;
        cout<<"The company is not whole"<<endl;
    }
    else{
        cout<<"L'entreprise est entiere"<<endl;
        cout<<"The company is whole"<<endl;

    }
}

void instruction_2(Heap<Employee>& company_structure){
    company_structure.extractMin();
    company_structure.parseHeap();
    cout<<endl;
//    company_structure.print_on_Levels();
    cout<<"New Manager is ";
    cout<<company_structure.to_string_own(1)<<endl;
    cout<<endl<<"INSTRUCTION 2 DONE!"<<endl;

}

void instruction_3(Heap<Employee> company_structure){
    int first_node, second_node;
    cout<<"Insert first node in conflict "<<endl;
    cin>>first_node;
    cout<<"Insert second node in conflict "<<endl;
    cin>>second_node;
    company_structure.find_supervisor(first_node, second_node);
}

int main()
{

Heap <Employee> company_structure (100); // heap on which the company is structured

ifstream f("employees.txt"); // file that contains initial employees
                             //file can be changed if needed
int nr_emp_init; // number of initial employees existent in the company
f>>nr_emp_init;

//auxiliary variables
string s1, s2;
int e1;

//b) (1.5p) Créer des objets de type Employe et sauvegardez-les dans le tas. Soyez attentifs pour
//actualiser les valeurs des salaires totales des employés après chaque insertion.
for (int j = 0; j < nr_emp_init; j++){
    f>>s1;f>>s2;f>>e1;
//    cout<<"s1 "<< s1 <<" s2 "<< s2<<" e1 "<<e1<<endl;
    Employee e_aux;
    e_aux.emp_init(s1,s2,e1);
    company_structure.insertElement(e_aux); // see insertHeap() - from heap_ini.h for salary actualisation
}
company_structure.parseHeap();
cout<<endl;
company_structure.print_on_Levels();

int instr;
cout<<endl;

instr = 405;
while(instr != 404){

cout<<endl<<endl<<endl<<"Please insert one of the following "<<endl;
cout<<"1 to check if the company is whole"<<endl;

cout<< "2 if you want to fire the manager"<<endl;

cout<<"3 if there exists a conflict "<<endl;

cout<< "404 to exit"<<endl;
cin>>instr;

if(instr == 1){
    instruction_1(company_structure);
}

else if (instr ==2){
    instruction_2(company_structure);
}
else
    instruction_3(company_structure);
}
}
