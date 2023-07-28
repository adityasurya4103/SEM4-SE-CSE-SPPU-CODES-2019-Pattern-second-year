#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    string name;
    vector<int> neighbors;
};

vector<node> adj_list;

int visited[50] = {0};

void dfs(int s, string arr[])
{
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int neighbor : adj_list[s].neighbors)
    {
        if (!visited[neighbor])
            dfs(neighbor, arr);
    }
}

void bfs(int s, string arr[])
{
    bool visited[50] = {false};
    queue<int> bfsq;
    bfsq.push(s);
    visited[s] = true;
    while (!bfsq.empty())
    {
        int v = bfsq.front();
        bfsq.pop();
        cout << arr[v] << " ";
        for (int neighbor : adj_list[v].neighbors)
        {
            if (!visited[neighbor])
            {
                bfsq.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    cout << "Enter the number of vertices : ";
    int n, u;
    cin >> n;

    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of vertices. Please try again." << endl;
        return 0;
    }

    string nodes[50];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter node " << i + 1 << " (name): ";
        cin >> nodes[i];
    }
    cout << "\nYour Nodes are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "Node " << i + 1 << ": " << nodes[i] << endl;

    adj_list.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int yes;
            cout << "Enter the Edges (0/1) " << nodes[i] << " and " << nodes[j] << ": ";
            cin  >> yes;
            if(yes == 1)
            {
                adj_list[i].neighbors.push_back(j);
                adj_list[j].neighbors.push_back(i);
            }
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << nodes[i] << ": ";
        for (int neighbor : adj_list[i].neighbors)
        {
            cout << nodes[neighbor] << " ";
        }
        cout << endl;
    }

    cout << "Enter the starting vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u - 1, nodes);
    cout << endl;
    cout << "BFS: ";
    bfs(u - 1, nodes);
    cout << endl;

    return 0;
}
