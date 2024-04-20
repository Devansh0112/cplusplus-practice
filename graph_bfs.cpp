#include<iostream>
#include<queue>
#include<vector>

using namespace std;


void bfs(vector<vector<int>> &g, int start_node, vector<bool> visited)
{
    queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";

        for(int n: g[current_node])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }   
        }
    }
}

void add_edge(vector<vector<int>> &g, int u, int v)
{
    g[u].push_back(v);
}

int main()
{
    int vertices = 5;
    vector<vector<int>> g(vertices);

    add_edge(g, 0,1);
    add_edge(g, 0,2);
    add_edge(g, 1,3);
    add_edge(g, 1,4);
    add_edge(g, 2,4);

    vector<bool> visited(vertices, false);

    cout << "BFS traversal starting from 0: " << endl;

    bfs(g, 0, visited);


    return 0;
}