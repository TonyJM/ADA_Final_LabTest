#include <bits/stdc++.h>
using namespace std;

#define V 10

int minDistance(int dist[], bool sptSet[],int n){
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[],int n){
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src,int n){
	int dist[V];
	bool sptSet[V];

	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < n - 1; count++) {
		int u = minDistance(dist, sptSet,n);
		sptSet[u] = true;
		for (int v = 0; v < n; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist,n);
}
int main(){

    int graph[V][V];

    int n,s;
    cout<<"Enter no. of vertices : ";
    cin>>n;
    cout<<"Enter distance matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cout<<"\nEnter source : ";
    cin>>s;



	dijkstra(graph, s,n);

	return 0;
}
