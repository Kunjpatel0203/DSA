#include <iostream>
#include<queue>

using namespace std;
class dJ
{
    enum
    {
        max_size = 10
    };
    int a[max_size][max_size];

public:
    dJ()
    {
        for (int i = 0; i < max_size; i++)
        {
            for (int j = 0; j < max_size; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    void add_edge(int u, int v, int w)
    {
        a[u][v] = w;
    }
    void display(int V)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
    }
    void dijikstra(int V)
    {
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (a[i][j] > a[i][k] + a[k][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }

    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < max_size; ++i)
        {
            if (a[v][i] != 0 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startVertex)
    {
        bool visited[max_size] = {false};
        DFSUtil(startVertex, visited);
    }

    void BFS(int startVertex)
    {
        bool visited[max_size] = {false};
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int i = 0; i < max_size; ++i)
            {
                if (a[currentVertex][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};
int main()
{
    // Create an object of class dJ
    dJ d;

    // Number of vertices in the graph
    int V = 3;
    d.add_edge(0, 1, 4);
    d.add_edge(0, 2, 11);
    d.add_edge(1, 0, 6);
    d.add_edge(1, 2, 2);
    d.add_edge(2, 0, 3);
    d.add_edge(2, 1, 400);
    cout << "Before Replacing values \n\n";
    d.display(V);
    d.dijikstra(V);

    cout << "\nDFS Traversal: ";
    d.DFS(0);

    cout << "\nBFS Traversal: ";
    d.BFS(0);

    cout << "\n\n After applying Dijikstra's Algorithm \n\n";
    d.display(V);
    return 0;
}