#include <iostream>
#include <limits.h>
using namespace std;

#define N 10
int ptr[100];

void findSmallestRange(int a[][N], int n, int k){
	int i,minval,maxval,minrange,minel,maxel,flag,minind;
	for(i = 0;i <= k;i++)
		ptr[i] = 0;
	minrange = INT_MAX;
	while(1){
		minind = -1;
		minval = INT_MAX;
		maxval = INT_MIN;
		flag = 0;
		for(i = 0;i < k;i++){
			if(ptr[i] == n){
				flag = 1;
				break;
			}

			if(ptr[i] < n && a[i][ptr[i]] < minval){
				minind=i;
				minval=a[i][ptr[i]];
			}

			if(ptr[i] < n && a[i][ptr[i]] > maxval){
				maxval = a[i][ptr[i]];
			}
		}
		if(flag)
			break;
		ptr[minind]++;
		if((maxval-minval) < minrange){
			minel = minval;
			maxel = maxval;
			minrange = maxel - minel;
		}
	}
	cout<<"\nThe smallest range is "<<"["<<minel<<" "<<maxel<<"]"<<endl;
}

int main(){
    int n,k,i,j;

	cout<<"Enter no. of lists and size of list: ";
	cin>>k>>n;
    int a[k][N];
	for(i=0;i<k;i++){
        cout<<"\nList "<<i+1<<" : ";
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }

	findSmallestRange(a,n,k);
	return 0;
}
