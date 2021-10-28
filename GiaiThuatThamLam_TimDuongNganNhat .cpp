#include<bits/stdc++.h>
using namespace std;

string s[9] ={"A","B","C","D","E","F","G","H","I"};
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < 9; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void show(int dist[], int n)
{
	cout << "Khoang cach tu A den: " << endl;
	cout << "Diem" << "\t" << "Khoang cach" << endl;
	for(int i=1; i<n; i++)
		cout << s[i] << "\t" << dist[i] << endl;
}

void dijkstra(int graph[9][9], int src)
{
    int dist[9];
 
    bool sptSet[9];

    for (int i = 0; i < 9; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
 

    for (int count = 0; count < 9 - 1; count++) {
        int u = minDistance(dist, sptSet);
 
        sptSet[u] = true;
 
        for (int v = 0; v < 9; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    show(dist, 9);
}

int main()
{
	int graph[9][9] = {
					  { 0,  0, 10, 10, 9,  0,  0,  0, 0},
					  { 0,  0,  0,  0, 0,  0,  8, 12, 5},
					  {10,  0,  0,  6, 0,  0,  0, 20, 0},
					  {10,  0,  6,  0, 7,  7,  8,  0, 0},
					  { 9,  0,  0,  7, 0,  0,  0,  0, 6},
					  { 0,  0,  0,  7, 0,  0, 10, 15, 0},
					  { 0,  8,  0,  8, 0, 10,  0,  0, 5},
					  { 0, 12, 20,  0, 0, 15,  0,  0, 0},
					  { 0,  5,  0,  0, 6,  0,  5,  0, 0}
					  };
	dijkstra(graph,0);
}