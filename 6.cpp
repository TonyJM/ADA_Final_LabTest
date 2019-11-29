#include<bits/stdc++.h>
using namespace std;

int c[20][20];

void prims(int n){
    int ne=0,mini;
    int mincost=0,u,v;
    int elec[n];
    for(int i=1;i<=n;i++){
        elec[i]=1;
    }
    elec[1]=1;
    while(ne!=n-1){
        mini=9999;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(elec[j]==1){
                    if(c[i][j]<mini){
                        mini=c[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(elec[v]==1){
            cout<<u<<"-->"<<v<<"="<<mini<<"\n";
            elec[v]=0;
            ne=ne+1;
            mincost=mincost+mini;
        }
        c[u][v]=9999;
        c[v][u]=9999;
    }
    cout<<"mincost="<<mincost;
}

int main(){
    int n;
    cout<<"enter no. of vertices";
    cin>>n;
    cout<<"\nenter cost matrix\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]==-1 || i==j)
                c[i][j]=9999;
        }
    }
    prims(n);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define V 3

int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
void printMST(int parent[], int graph[V][V]){
	cout<<"Edge \t| Weight\n";
    cout<<"--------|--------\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" -> "<<i<<" \t| "<< graph[i][parent[i]]<<" \n";
}
void primMST(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}

int main()
{
	int graph[V][V];
    cout<<"Enter graph weights:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
            if(graph[i][j]==-1)
                graph[i][j]=INT_MAX;
        }
    }

    cout<<"\nThe Given Graph:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\nPrim's Minimal Spanning tree solution:\n\n";
	primMST(graph);

	return 0;
}
*/
