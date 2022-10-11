#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
bool dfs(int vertex, int par)
{
    vis[vertex] = true;
    bool loopExist = false;
    for (int child : g[vertex])
    {
        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return true;
        loopExist |= dfs(child, vertex);
    }
    return loopExist;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool exist(0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            exist = 1;
            break;
        }
    }
    cout << exist << endl;
    return 0;
}
