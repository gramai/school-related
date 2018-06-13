#include <stdio.h>
#include <queue>
#include <iostream>
#include "list"
#include <fstream>
#include "graphs_matrix.h"
using namespace std;

//Map class that holds all information needed
class Map{
    int no_cities, no_roads, no_stations;
    string *cities, *stations; //will hold cities
    public:
        Map(){}; // empty constructor, all is initialised in getRoads()

        //getRoads will be used to initialise the needed Graph (bellow the function)
        Graph<int, int> getRoads(){
            ifstream f("init.txt"); //init.txt holds on one line two integers separated by " ": number of cities and number of roads
            f>>no_cities;
            f>>no_roads;

            ifstream f2("cities.txt"); // cities.txt holds on one line the city names with the format given in the homework
            cities = new string[no_cities];
            for (int i = 0; i < no_cities; i++){
                f2>>cities[i];
            }

            Graph <int, int> g(no_roads);
            ifstream f3("roads.txt");//roads.txt holds all roads with the format given in the homework
            string r1, r2;
            int g1, g2;
            for (int i = 0; i < no_roads; i++){
                f3>>r1;
                f3>>r2;
                for (int i1 = 0; i1< no_cities; i1++){
                    if(cities[i1] == r1){ //checks if city name corresponds to a certain member of string *cities (the array of cities)
                        g1 = i1;
                    }
                    if(cities[i1] == r2){
                        g2 = i1;
                    }
                }
                g.addEdge(g1,g2); // graphs_matrix.h is the same as adjacencymatrix.cpp given during the labs, with small modifications
//                cout<<"Edge added "<< g1<<" "<<g2<<endl;
            }
            return g;
        }
        Graph <int, int> g = getRoads(); //g is now a Graph that can be access from within the Map class

        //for debugging
            void printRoads(){
                g.printEdges();
            }
            void printCities(){
                for (int i = 0; i < no_cities; i++){
                    cout<<cities[i]<<" ";
                }
                cout<<endl;
            }
        // END

        //Demands

//1.Quelle ville est la plus surpeuplée (en fonction du nombre maximum d'autoroutes qui entrent dans cette ville).
        void demand1(){
        //vector of ints to get all the roads
        std::vector<int> roads_to_vect(no_roads);
        int roads_to[no_cities], roads, max_roads = 0, over_populated = -1;
        for (int i = 0; i < no_cities; i++){
            roads_to_vect = g.roads_to(i);
            int i2 = 0;
            for(int x : roads_to_vect){ //iterates through vector elements
                if(i2 > 7){ //for some reason (which I don't understand yet), first 8 elements of each vector are 0
                roads_to[i2-8] = x;
                //for debugging
//                cout<<"RT "<<roads_to[i2-7]<<endl;
                }
                i2++;
            }

            roads = 0;
            for (int j = 0; j < no_roads; j++){
                if(roads_to[j] != -1) //if value differs -1, a road exists that leads to the i'th city (cities[i])
                    roads ++; //calculates number of roads that lead to a cities[i]
            }
            if(roads > max_roads){ //gets max roads number
                max_roads = roads;
                over_populated = i;
                }
        }
        cout<<"The most overcrowded city is "<<cities[over_populated]<<endl;
      }
//2. Vérifier si la carte est valide (nous considérons que la carte est valide si nous avons au moins un
      //chemin entre 2 villes. Obs: un chemin à sens unique entre 2 villes est suffisant!) ;
      //same principle as demand1, small modifications for finding min_roads
        void demand2(){
        //vector of ints to get all the roads
        std::vector<int> roads_to_vect(no_roads);
        int roads_to[no_cities], roads, min_roads = no_roads + 1, not_populated = -1;
        for (int i = 0; i < no_cities; i++){
            roads_to_vect = g.roads_to(i);
            int i2 = 0;
            for(int x : roads_to_vect){ //iterates through vector elements
                if(i2 > no_roads-1){ //for some reason (which I don't understand yet), first no_roads elements of each vector are 0
                roads_to[i2-no_roads] = x;
                //for debugging
//                cout<<"RT "<<roads_to[i2-7]<<endl;
                }
                i2++;
            }
            roads = 0;
            for (int j = 0; j < no_roads; j++){
                if(roads_to[j] != -1) //if value differs -1, a road exists that leads to the i'th city (cities[i])
                    roads ++; //calculates number of roads that lead to a cities[i]
//                    cout<<"Rt "<<roads_to[j]<<" ";
            }
//            cout<<"roads "<<roads<<endl;
            if(roads < min_roads){ //gets min roads number
                min_roads = roads;
                if(min_roads == 0)
                    {
                    not_populated = i;
                    }
                }
        }
        if (not_populated != -1)
        cout<<"The map is not valid. "<<cities[not_populated]<<" is not populated."<<endl;
        else
        cout<<"The map is valid"<<endl;
      }

//3. Pour une ville spécifique, déterminer quelles villes sont dites «inaccessibles» (deux villes sont
//dites inaccessibles l'une à l'autre si nous n'avons pas de route à double sens entre elles)


            void dijkstra2(int src) //src is starting point, gaz is the initial quantity of gas, cons is the consummation of the vehicle between two cities that have a road
        {
             int dist[no_cities];     // The output array.  dist[i] will hold the shortest
                              // distance from src to i

             bool sptSet[no_cities]; // sptSet[i] will true if node i is included in shortest
                             // path tree or shortest distance from src to i is finalized

             // Initialize all distances as INFINITE and stpSet[] as false
             for (int i = 0; i < no_cities; i++)
                dist[i] = INT_MAX, sptSet[i] = false;

             // Distance of source node from itself is always 0
             dist[src] = 0;

             // Find shortest path for all nodes
             for (int count = 0; count < no_cities-1; count++)
             {
               // Pick the minimum distance node from the set of nodes not
               // yet processed. u is always equal to src in first iteration.
               int u = minDistance(dist, sptSet);
               // Mark the picked node as processed
               sptSet[u] = true;
               // Update dist value of the adjacent vertices of the picked node.
               for (int v = 0; v < no_cities; v++)

                 // Update dist[v] only if is not in sptSet, there is an edge from
                 // u to v, and total weight of path from src to  v through u is
                 // smaller than current value of dist[v]
                 if (!sptSet[v] && A[u][v] && dist[u] != INT_MAX
                                               && dist[u]+A[u][v] < dist[v])
                    {dist[v] = dist[u] + A[u][v];
                    }
             }

             for(int v = 0; v < no_cities; v++){
                if(dist[v] > no_cities * no_cities + 1){
                        dist[v] = -1;
                }
             }
             // print the constructed distance array
//             printSolution(dist, no_cities);
            for (int i21 = 0; i21 < no_cities;i21 ++){
                if(dist[i21] == -1)
                    cout<<"For city "<<cities[src]<< " "<<cities[i21] <<" is inaccessible."<<endl;
            }
        }

    void demand3(int spec){
        dijkstra2(spec);
    }




//4. Déterminer quelle est la station-service la plus proche où une voiture peut s'arrêter (compte tenu
//de sa consommation de gaz, de la quantité initiale de gaz et de sa position initiale).
//DIJSKTRA ALGORITHM FROM // from https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
        char **A = g.returnA();
        //minDistance finds the minimum distance to another node that hasn't been visited before
        int minDistance(int dist[], bool sptSet[])
        {
           // Initialize min value
           int min = INT_MAX, min_index;

           for (int v = 0; v < no_cities; v++) //sptSet holds true if node has been visited and false otherwise
             if (sptSet[v] == false && dist[v] <= min)
                 min = dist[v], min_index = v;

           return min_index;
        }

        // Funtion that implements Dijkstra's single source shortest path algorithm
        // for a graph represented using adjacency matrix representation

        void dijkstra(int src, int gaz, int cons) //src is starting point, gaz is the initial quantity of gas, cons is the consummation of the vehicle between two cities that have a road
        {
             int dist[no_cities];     // The output array.  dist[i] will hold the shortest
                              // distance from src to i

             bool sptSet[no_cities]; // sptSet[i] will true if node i is included in shortest
                             // path tree or shortest distance from src to i is finalized

             // Initialize all distances as INFINITE and stpSet[] as false
             for (int i = 0; i < no_cities; i++)
                dist[i] = INT_MAX, sptSet[i] = false;

             // Distance of source node from itself is always 0
             dist[src] = 0;

             // Find shortest path for all nodes
             for (int count = 0; count < no_cities-1; count++)
             {
               // Pick the minimum distance node from the set of nodes not
               // yet processed. u is always equal to src in first iteration.
               int u = minDistance(dist, sptSet);
               // Mark the picked node as processed
               sptSet[u] = true;
               // Update dist value of the adjacent vertices of the picked node.
               for (int v = 0; v < no_cities; v++)

                 // Update dist[v] only if is not in sptSet, there is an edge from
                 // u to v, and total weight of path from src to  v through u is
                 // smaller than current value of dist[v]
                 if (!sptSet[v] && A[u][v] && dist[u] != INT_MAX
                                               && dist[u]+A[u][v] < dist[v])
                    {dist[v] = dist[u] + A[u][v];
                    }
             }

             for(int v = 0; v < no_cities; v++){
                if(dist[v] > no_cities * no_cities + 1){
                        dist[v] = -1;
                }
             }
             // print the constructed distance array
//             printSolution(dist, no_cities);
            int dmin = 999, dind = -1;
            for (int i21 = 0; i21 < no_cities;i21 ++){
                if(dist[i21] != -1 && g.getNodeInfo(i21) == 1 && dist[i21] < dmin){ //finds shortest distance
                    dmin = dist[i21];
                    dind = i21;
                }
            }
            if(dmin * cons <= gaz) //check if closest station is close enough for the fuel
            {
            cout<<endl;
            cout<<cities[src]<<" - "<<cities[dind]<<endl;
            cout<<"Distance : "<<dmin<<endl;
            cout<<"Total Consummation (distance *  consummation/city) : "<<dmin * cons<<endl;
            cout<<"Fuel left : "<<gaz - cons * dmin<<endl;
            }
            else if (dmin * cons > gaz && dmin != 999 && dind != -1)
            {
            cout<<endl;
            cout<<"No valid station for "<<cities[src]<<endl;
            cout<<"Closest station is "<<cities[dind]<<endl;
            cout<<"Distance : "<<dmin<<endl;
            cout<<"Total Consummation (distance *  consummation/city) : "<<dmin * cons<<endl;
            cout<<"Fuel needed : "<<abs(gaz - cons * dmin)<<endl;
            }
            else{
            cout<<"There is no road to a fuel station starting from "<<cities[src];
            }
        }
//END


    void demand4(){
        ifstream f4("stations.txt");
        f4>>no_stations;
        stations = new string[no_stations];
        for(int i = 0; i < no_stations; i++){
            f4>>stations[i];
            for (int j = 0; j < no_cities; j++){
                if(stations[i] == cities[j]){
                    g.setNodeInfo(j,1); //sets node info of cities that are station to 1
                }
            }
        }
        for (int i = 0; i < no_cities; i ++){
            if(g.getNodeInfo(i) != 1)
                g.setNodeInfo(i, 0); //node info of cities that are not stations is set to 0
        }
        ifstream f5("demand4.txt");
        int no_cars, src, gaz, cons;
        string position;
        f5>>no_cars;
        for(int i = 0; i < no_cars; i++){
            f5>>position;
            for (int j = 0; j < no_cities; j++){
                if(cities[j] == position)
                    {
                    src = j;
                    }
            }
            f5>>gaz>>cons;
            dijkstra(src,gaz,cons);
        }
    }


};
int main() {
Map own_map ;

//IMPORTANT
//To change test sets, don't forget to modify init.txt aswell (number of cities and number of roads)
cout<<"1.";
own_map.demand1();
cout<<endl<<"2.";
own_map.demand2();
cout<<endl<<"3.";
own_map.demand3(5);
cout<<endl<<"4.";
own_map.demand4();
}
