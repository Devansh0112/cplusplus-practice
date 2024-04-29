// In this code we will use dfs to detect a cycle in the undirected graph

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool find_cycle(vector<vector<int>> &g, int start_node, vector<bool> &visited)
{
    stack<int> s;

    s.push(start_node);

    while(!s.empty())
    {
        int current_node = s.top();
        s.pop();

        if(!visited[current_node])
        {
            visited[current_node] = true;
        }

        for (int n: g[current_node])
        {
            if(!visited[n]){
                s.push(n);
            }
            else {
                return true;
            }
        }
    }

    return false;

}


void add_edge(vector<vector<int>> &g, int u, int v)
{
    g[u].push_back(v);
}

int main()
{
    int vertices = 4;
    vector<vector<int>> graph(vertices);

    add_edge(graph, 0,1);
    add_edge(graph, 0,2);
    add_edge(graph, 1,2);
    add_edge(graph, 2,3);

    vector<bool> visited(vertices, false);

    bool is_cycle = find_cycle(graph, 0, visited);

    cout << "Is there a cycle in the graph : " << is_cycle << endl;
    
    return 0;
}