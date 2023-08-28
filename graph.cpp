#include "bits/stdc++.h"
using namespace std;
bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited,
         int node, int &count)
{
    if (pathVisited[node])
    {
        count++;
        return true;
    }
    if (visited[node])
        return false;
    visited[node] = pathVisited[node] = true;
    for (auto &adjNode : adj[node])
    {
        if (dfs(adj, visited, pathVisited, adjNode, count))
            return true;
    }
    pathVisited[node] = false;
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int b[k];
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        adj[b[i] - 1].push_back(a[i] - 1);
    }
    vector<bool> visited(n, 0), pathVisited(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            bool y = dfs(adj, visited, pathVisited, i, count);
    }
    cout << count << endl;
    //  cout<<104÷5<<endl;
}
