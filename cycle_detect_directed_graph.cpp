// In this code we will use dfs to detect a cycle in the directed graph
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool find_cycle(vector<vector<int>> &g, int start_node, vector<bool> &visited, vector<bool>& path_visited)
{
    stack<int> s;
    s.push(start_node);
    path_visited[start_node] = true;

    while(!s.empty())
    {
        
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

    add_edge(graph, 0,1);
    add_edge(graph, 0,2);
    add_edge(graph, 1,2);
    add_edge(graph, 2,3);
    add_edge(graph, 3,0);

    vector<bool> visited(vertices, false);
    vector<bool> path_visited(vertices, false);

    for(int i=0; i<vertices; ++i)
    {
        if (!visited[i] && find_cycle(graph, i, visited, path_visited)) 
        {
            cout << "There is a cycle in the graph!" << endl;
            return 0;
        }
    }
    
    
    return 0;
}