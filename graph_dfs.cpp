#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(vector<vector<int>> &g, int start_node, vector<bool> &visited)
{
    stack<int> s;
    s.push(start_node);

    while (!s.empty())
    {
        int current_node = s.top();
        s.pop();

        if (!visited[current_node])
        {
            cout << current_node << " ";
            visited[current_node] = true;
        }

        for(int n : g[current_node])
        {
            if(!visited[n])
            {
                s.push(n);
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
    vector<vector<int>> graph(vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);


    vector<bool> visited(vertices, false);

    dfs(graph, 0, visited);


    return 0;
}