#include<iostream>
using namespace std;

const int MAX_VERTICES = 100;

class Graph {
private:
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

    public:

    Graph(int V) {
        numVertices = V;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge (int v, int u){  //for undirected graph
        adjMatrix[v][u] = 1;
        adjMatrix[u][v] = 1;
    }

/*
     void add_edge(int u,int v,int w)
		{
			a[u][v]=w;
		}
    void BFS(int startVertex) {
        // Mark the current node as visited and enqueue it
        bool visited[MAX_VERTICES] = {false};
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        // BFS loop
        while (!q.empty()) {
            // Dequeue a vertex from the queue and print it
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            // Enqueue all adjacent unvisited vertices and mark them as visited
            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }*/

   void DFS(int startVertex) {
    // Mark the current node as visited and print it
    bool visited[MAX_VERTICES] = {false};
    visited[startVertex] = true;
    cout << startVertex << " ";

    // Recursive DFS for all adjacent vertices
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}



    void display_Matrix (){
        for (int i=0; i<numVertices; i++){
            for (int j=0; j<numVertices; j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main (){
    
    cout<<"Enter total number of vertices and edges respectively"<<endl;
    int x,y;
    cin>>x>>y;

    Graph g=x;

    cout<<"Enter the pair vertices having an edge between them"<<endl;
    for(int i=0; i<y; i++){
        int v,u;
        cin>>v>>u;
        g.addEdge(v,u);
    }

    g.display_Matrix();

   cout << "Enter the starting vertex for DFS: ";
    int startVertex;
    cin >> startVertex;
    cout << "DFS Traversal: ";
    g.DFS(startVertex);

   /*  cout << "Enter the starting vertex for BFS: ";
    int startVertex;
    cin >> startVertex;
    cout << "BFS Traversal: ";
    g.BFS(startVertex);
*/
    return 0;
}