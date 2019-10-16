#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // For number of Vertices (V) and number of edges (E)
vector<vector<int>> G;	//图
vector<bool> visited;	
vector<int> ans;

void dfs(int v)
{
	visited[v] = true;
	for (int u : G[v])
	{
		if (!visited[u])
			dfs(u);
	}
	ans.push_back(v);
}
/*			
 *              0->1, 0->2, 1->2
 *							
 *			G[]			G[][]		visited（初始）     ans(结果)
 *			0			2 1				0					0
 *			1			2				0					0
 *			2							0					0
 */
void topological_sort()
{
	visited.assign(n, false);//初始化visited，均未访问
	ans.clear();
	for (int i = 0; i < n; ++i)	//访问每个顶点
	{
		if (!visited[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());//后面只有出度，无入度
}

int main()
{
	cout << "Enter the number of vertices and the number of directed edges\n";
	cin >> n >> m;
	int x, y;
	G.resize(n, vector<int>());
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		x--, y--; // to convert 1-indexed to 0-indexed
		G[x].push_back(y);
	}
	topological_sort();
	cout << "Topological Order : \n";
	for (int v : ans)
	{
		cout << v + 1 << ' '; // converting zero based indexing back to one based.
	}
	cout << '\n';
	return 0;
}
