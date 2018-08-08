#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <queue>
using namespace std;								//Use namespace to std. 

//#pragma warning(disable:4996)						//When using 'strtok', warning can appear. Then use this sentence.
//#define _CRT_SECURE_NO_WARNINGS					//When using 'strtok', warning can appear. Then use this sentence.

int vertex, edge, start;							//Store size of graph and start node.
int graph[51][51] = { 0, };							//Two demension array that stores connection between nodes.
int dfs_visit[51];									//Array that stores visited node to 1 in dfs.
int bfs_visit[51];									//Array that stores visited node to 1 in bfs.


////////////////////////////////////////////////
//					 <BFS>					  //
//Description : bfs algorithm that searches	  //
//				shortest path.				  //
////////////////////////////////////////////////
void bfs ()
{
	int cur = start;
	queue<int> q;

	bfs_visit[cur] = 1;
	q.push(cur);

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		cout << cur << " ";
		for (int i = 1; i <= vertex; i++)
		{
			if (graph[cur][i] == 1 && bfs_visit[i] == 0)
			{
				q.push(i);
				bfs_visit[i] = 1;
			}
		}
	}
	cout << "\n";
}


////////////////////////////////////////////////
//					 <DFS>					  //
//Description : dfs algorithm that searches	  //
////////////////////////////////////////////////
void dfs(int x)
{
	dfs_visit[x] = 1;
	cout << x << " ";

	for (int i = 1; i <= vertex; i++)
	{
		if (graph[x][i] == 1 && dfs_visit[i] == 0)
		{
			dfs(i);
		}
	}
}


////////////////////////////////////////////////
//					 <main>					  //
//Description : main function that makes	  //
//				graph and calls bfs			  //
//				and dfs function.			  //
////////////////////////////////////////////////
void main()
{
	cin >> vertex >> edge >> start;

	for (int i = 1; i <= edge; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		graph[tmp1][tmp2] = 1;
		graph[tmp2][tmp1] = 1;
	}

	dfs(start);
	cout << "\n";
	bfs();
}

