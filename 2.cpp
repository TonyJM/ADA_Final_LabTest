#include <iostream>
#include <time.h>

using namespace std;

void knapsack(){
    int n,c,x,i,j,k;
    cout<<"Enter no. of items : ";
    cin>>n;
    int w[n],v[n],r[n];
    cout<<"Enter weights and values of items :\n";
    for(i=0;i<n;i++)
        cin>>w[i]>>v[i];
    cout<<"Enter capacity : ";
    cin>>c;
	int a[n+1][c+1];
	for(i=0;i<=n;i++)
		a[i][0]=0;
	for(j=0;j<=c;j++)
		a[0][j]=0;

	for(i=1;i<=n;i++){
		for(j=1;j<=c;j++){
            x=j-w[i-1];
			if(x>=0)
				a[i][j]=max(a[i-1][j],v[i-1]+a[i-1][x]);
			else
				a[i][j]=a[i-1][j];
		}
	}

    i=n;j=c;
    k=0;
    while(i>0 && j>0){
        if(a[i-1][j]<a[i][j]){
            r[k++]=i;
            j-=w[i-1];
        }
        i--;
    }

    cout<<"\nMax Value : "<<a[n][c];
    cout<<"\nItems : ";
    for(i=0;i<k;i++)
        cout<<r[i]<<"\t";
}

int main(){
	clock_t start,end;
	double time;
	start=clock();
    knapsack();
	end=clock();
	time=(double(end)-double(start))/double(CLOCKS_PER_SEC);
	cout<<"\nTime Taken = "<<time<<"s\n";
}
