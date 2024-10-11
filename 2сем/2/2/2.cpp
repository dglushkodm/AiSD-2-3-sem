
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool graph[10][10];
struct Edge {
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const& edges, int n)
    {
        adjList.resize(n);
        for (auto& edge : edges) {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
queue<int> Queue;
stack<int> Stack;
int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "введите кол-во вершин и рёбер" << endl;
    cin >> n >> m;
    int mas[100][2];
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "введите пары вершин связанных одним ребром" << endl;
        cin >> u >> v;
        mas[i][0] = u;
        mas[i][1] = v;
        u--, v--;


        graph[u][v] = graph[v][u] = true;
    }

    for (int i = 0; i <= n; i++)
        cout << "{" << mas[i][0] << "," << mas[i][1] << "}";
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                c++;
                cout << 1;
            }
            else
                cout << 0;
        }
        cout << endl;
    }



    int nodes[10];
    for (int i = 0; i < 10; i++)
        nodes[i] = 0; 
    Queue.push(0); 
    while (!Queue.empty())
    {
        int node = Queue.front(); 
        Queue.pop();
        nodes[node] = 2; 
        for (int j = 0; j < 10; j++)
        {
            if (graph[node][j] == 1 && nodes[j] == 0)
            { 
                Queue.push(j); 
                nodes[j] = 1; 
            }
        }
        cout << node + 1 << endl; 
    }
 
 

    int nodess[10];
    for (int i = 0; i < 10; i++)
        nodess[i] = 0;
    Stack.push(0); 
    while (!Stack.empty())
    { 
        int node2 = Stack.top();
        Stack.pop();
        if (nodess[node2] == 2) continue;
        nodess[node2] = 2;
        for (int j = 9; j >= 0; j--)
        { 
            if (graph[node2][j] == 1 && nodess[j] != 2)
            {
                Stack.push(j); 
                nodess[j] = 1; 
            }
        }
        cout << node2 + 1 << endl; 
    }
    cin.get();
    return 0;
}
