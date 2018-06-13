#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
// http://www.cplusplus.com/reference/queue/queue/

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
            A[i][j] = A[j][i] = 1;
            edgeInfo[i][j] = 1;
            edgeInfo[j][i] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = A[j][i] = 0; }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = edgeInfo[j][i] = info; }

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

        int getDegre(int i){
            int j, degre = 0;
            for ( j = 0; j < N; j++){
                if (A[i][j] == 1)
                    degre ++;
            }
            return degre;
        }
};

Graph<int, int> g(8);
char* visited;


int ok = 0;
void dfs(int x) {
    ok++;
    int y;
    printf("%d\n", x);
    visited[x] = 1;
    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            {
            dfs(y);
            }
}
int pp = 1;
void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    g.setNodeInfo(S, 1);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
                if(g.getNodeInfo(x) == 1){
                    g.setNodeInfo(y,0);
                }
                else{
                    g.setNodeInfo(y,1);
                }

               Q.push(y);
            }
            else if (visited[y]){
                if(g.getNodeInfo(x) == g.getNodeInfo(y) && pp == 1){
                pp = 0;
                }
            }
    }
}

void init_vect(int vect[]){
    for (int i = 0; i < sizeof(vect) / sizeof(vect[0]); i++){
        vect[i] = 0;
    }
}

int friends[11];

void printFriends(int ut, int n){
    friends[ut] = 1;
    if (n > 0){
        for (int j = 0; j < g.N; j ++){
            if (g.getEdgeInfo(ut, j) == 1){
                if(friends[j] == 0){
                    friends[j] = 1;
                    cout<<j<<" ";
                }
                printFriends(j, n-1);
            }

        }
    }
}

int main() {
    int i;

    //Social Network
    g.addEdge(0, 1);    g.addEdge(2, 3);
    g.addEdge(0, 2);    g.addEdge(0, 6);
    g.addEdge(4, 5);    g.addEdge(7, 5);
    g.addEdge(6, 4);

    int user, degree; // can be changed as convenient
    user = 0;
    degree = 2;
    cout<<endl<<"The user at node "<<user<<"  has friends with the max degree  "<<degree<<" the following: "<<endl;

    printFriends(user,degree);

   return 0;
}

