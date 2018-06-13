#include <iostream>
#include "liste1.h"
#include <math.h>
using namespace std;

//1. Définir la structure nécessaire pour représenter les points (classe ou struct)
struct point{ //struct that holds the coordonates
    int x, y;
    float getDist(){ //function that returns the distance from origin
    float dist = sqrt(x * x + y * y);
        return dist;
    }
};


int main()
{

// 2. Sauvegarder les points dans une liste liée chainée. Les points sont lus du clavier et l’utilisateur
//sera guidé avec les messages appropriés

    LinkedList <point> points; //initial list of points
    LinkedList <point> sorted_points; //final list of points
    int x,y,n;
    point p1;
    cout<<"How many points would you like to enter? ";
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter x coord. for point nr. "<<i<<" ";
        cin>>x;
        p1.x = x;
        cout<<"Enter y coord. for point nr. "<<i<<" ";
        cin>>y;
        p1.y = y;
        points.addLast(p1);
//        cout<<p1.getDist()<<endl;
    }

    cout<<"Inserted points are: "<<endl;
    point aux;
    for(int i = 0; i < n; i++){
        if(i+1 != n)
            cout<<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<"), ";
        else
            cout<<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<")";
        aux = points.pfirst->info;
        points.removeFirst();
        points.addLast(aux);
    }

    cout<<endl;
    float distances [n],min_dist;
    int min_ind, naux = n;

// 3. Implémenter l’algorithme de tri en ordre croissant. Les points seront réaffichés à l’écran après le
//tri.
//Sorting:
// To better understand my logic, uncomment the couts

//searches the min point from the points, and adds it as last point in sorted_points, afterwards, it removes it from points
    while (!points.isEmpty() && n != 0){ //this continues until there are no more points left in points list
        min_dist = 99999; //at every iteration, min_dist and min_ind is initialised
        min_ind = -1;
        for (int i = 0 ; i < n; i++){ //one complete iteration of the list, where it finds the smallest point
            float dist = points.pfirst->info.getDist(); //and saves its value and indice
            if(dist < min_dist){
                min_dist = dist;
                min_ind = i;

//                cout<<"One min is " <<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<")"<<endl;
//                cout<<"With dist "<<min_dist<<endl;
//                cout<<endl;

            }
            aux = points.pfirst->info;
            points.removeFirst();
            points.addLast(aux);
        }

//         cout<<"After finding min pfirst is " <<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<")"<<endl;
//         cout<<endl;


        for(int i = 0; i < min_ind; i++){ //partial iteration, until smallest point be
            aux = points.pfirst->info;    //This is done in order to be able to remove it
            points.removeFirst();
            points.addLast(aux);

//            cout<<"Loading " <<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<")"<<endl;

        }

//        cout<<"Final min is" <<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<")"<<endl;

        sorted_points.addLast(points.pfirst->info); //adds first point from points list to sorted_points
        points.removeFirst(); //removes first point

//        if(n > 1)
//            cout<<"Removed point -> after removal first is "<<"("<<points.pfirst->info.x<<","<<points.pfirst->info.y<<")"<<endl;
        n--; //decreases points list size
    }
    n = naux; //recovers lost value of n
    cout<<"Sorted points are: "<<endl;
    for(int i = 0; i < n; i++){
        if(i+1 != n)
            cout<<"("<<sorted_points.pfirst->info.x<<","<<sorted_points.pfirst->info.y<<"), ";
        else
            cout<<"("<<sorted_points.pfirst->info.x<<","<<sorted_points.pfirst->info.y<<")";
        aux = sorted_points.pfirst->info;
        sorted_points.removeFirst();
        sorted_points.addLast(aux);
    }

//4. Vérifier si les points sont colinéaires ou non. Un message correspondant sera affiché.
    int col = 1;
    point aux3 = sorted_points.pfirst->info; //first point from list
        int px1, py1;
        px1 = sorted_points.pfirst->info.x; //coord. of first point
        py1 = sorted_points.pfirst->info.y;
        for(int i = 0; i < n - 1; i++){
// iterates through all points and compares the FIXED first point (px1, py2) with
// the variable points (px2, py2), (px3, py3) - point 2 and point 3 will take pfirst and plast alternatively
            int px2, py2, px3, py3;
            aux = sorted_points.pfirst->info;
            sorted_points.removeFirst();
            sorted_points.addLast(aux);

            px2 = sorted_points.pfirst->info.x;
            py2 = sorted_points.pfirst->info.y;
            px3 = sorted_points.plast->info.x;
            py3 = sorted_points.plast->info.y;
            if( (py1 - py2) * (px1 - px3) != (py1 - py3) * (px1 - px2) ) //checks the slopes
                col = 0;

    }
    cout<<endl<<endl;
    if(col == 0)
    cout<<"Not colinear";
    else
    cout<<"Colinear";

}
