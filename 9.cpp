#include <bits/stdc++.h>
using namespace std;
#define V 10
#define INF 99999

void printSolution(int dist[][V],int n);

void floyd (int graph[][V],int n){
	int dist[V][V], i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist,n);
}
void printSolution(int dist[][V],int n){
	cout<<"Shortest distances between every pair of vertices \n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (dist[i][j] == INF)
				cout<<"INF"<<"	 ";
			else
				cout<<dist[i][j]<<"	 ";
		}
		cout<<endl;
	}
}
int main(){

    int n,graph[V][V];
    cout<<"Enter no. of vertices : ";
    cin>>n;
    cout<<"Enter distance matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> graph[i][j];
            if (graph[i][j]==-1)
                graph[i][j]=INF;
        }
    }

    floyd(graph,n);
    return 0;
}
