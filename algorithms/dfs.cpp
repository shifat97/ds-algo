#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> arr[1005];
bool vis[1005];
void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for (int child : arr[src])
    {
        if (!vis[child])
            dfs(child);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
    return 0;
}

/*

7 7
0 2
2 4
0 1
1 5
1 3
0 3
3 6

*/