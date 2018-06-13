#include <stdio.h>
#include <queue>
#include "list"
#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

// Modifications:
// 1) at addEdge, removeEdge from A[i][j] = A[j][i] = 1; to A[i][j] = 1; or similar, to obtain an oriented graph
// 2) Added function printEdges()
// 3) Added function roads_to(int i)
template<typename TnodeInfo, typename TedgeInfo>
class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;
        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            // allocate the adjacency matrix
            A = new char*[N];
            for (i = 0; i < N; i++)
                A[i] = new char[N];
			for (i = 0; i < N; i++)
                for (j = 0; j < N; j++) A[i][j] = 0;

            // allocate the array with node information
            nodeInfo = new TnodeInfo[N];

            // allocate the matrix of edge information
            edgeInfo = new TedgeInfo*[N];
            for (i = 0; i < N; i++)
                edgeInfo[i] = new TedgeInfo[N];
        }

        void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = 0; }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = info; }

        void printEdges(){ //function that has been added to the adjancencymatrix.cpp given during the lab
                           //prints to console all edges from the adjacency matrix
            for (int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(A[i][j] == 1)
                    cout<<"Edge from "<< i<<" to "<< j<<endl;
                }
            }
        }

        //returns a vector of int which contains all the roads that lead to a city
        std::vector<int> roads_to(int i){
            std::vector<int> roads(N);
            for (int j = 0; j < N; j++){
                if(A[j][i] == 1){
                    roads.push_back(j); //saves value of city if there exists a road -1 otherwise
                    //debugging
//                    cout<<"To "<<i<<" is "<<j<<endl;
                }
                else{
                    roads.push_back(-1);
                }
            }
            return roads;
        }
        char** returnA(){
            return A;
        }

        int roads_to_from(int i, int j){
            if (A[i][j] == A[j][i] && A[j][i] == 1){
                return 1;
            }
            else{
            return 0;
            }
        }



        TedgeInfo getEdgeInfo(int i, int j) {
            return edgeInfo[i][j]; }

        ~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
                delete edgeInfo[i];
            }
            delete A;
            delete edgeInfo;
            delete nodeInfo;
        }
};
