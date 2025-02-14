//============================================================================
// Name        : 02_Breadth_First_Search_BFS.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
bool vis[1005];

void bfs(int src)
{
	queue<int> q;
	q.push(src);
	vis[src] = true;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		cout << p << " ";
		for (int child : a[p])
		{
			if (vis[child] == false)
			{
				q.push(child);
				vis[child] = true;
			}
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;
	while (e--)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(vis, false, sizeof(vis));
	bfs(0);
	return 0;
}

/*

7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5

*/
