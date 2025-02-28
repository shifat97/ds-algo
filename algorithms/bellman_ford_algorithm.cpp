#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int u, int v, int w)
    {
        a = u;
        b = v;
        c = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;
    vector<int> dist(n, INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    // Bellman-Ford Algorithm
    dist[0] = 0;
    bool cycle = false;

    for (int i = 0; i < n - 1; i++)
    {
        for (const auto &ed : edge_list)
        {
            if (dist[ed.a] != INT_MAX && dist[ed.a] + ed.c < dist[ed.b])
            {
                dist[ed.b] = dist[ed.a] + ed.c;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto &ed : edge_list)
    {
        if (dist[ed.a] != INT_MAX && dist[ed.a] + ed.c < dist[ed.b])
        {
            cycle = true;
            break;
        }
    }

    if (!cycle)
    {
        cout << "DEBUG::\n";
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INT_MAX)
                cout << i << " -> INF\n";
            else
                cout << i << " -> " << dist[i] << "\n";
        }
    }
    else
    {
        cout << "Negative weighted cycle detected\n";
    }

    return 0;
}
