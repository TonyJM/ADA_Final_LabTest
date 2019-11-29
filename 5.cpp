#include<bits/stdc++.h>
using namespace std;
#define INF 999
//#define N 3
//#define A 8
int N,A;
void coinChange(int d[], int C[], int S[]) {
    int i, p, min, coin;
    //when amount is 0
    //then min coin required is 0
    C[0] = 0;
    S[0] = 0;
    for(p = 1; p <= A; p++) {
        min = INF;
        for(i = 1; i <= N; i++) {
            if(d[i] <= p) {
                if(1 + C[p - d[i]] < min) {
                    min = 1 + C[p - d[i]];
                    coin = i;
                }
            }
        }
        C[p] = min;
        S[p] = coin;
    }
}
void coinSet(int d[], int S[]) {
    int a = A;
    cout<<"Coins Used :\n";
    while(a > 0) {
        //cout<<"\nUse coin of denomination: "<< d[S[a]];
        cout<<d[S[a]]<<"\t";
        a = a - d[S[a]];
    }
    cout<<endl;
}
/*
void display(int arr[]) {
    int c;
    for(c = 0; c <= A; c++) {
        printf("%5d", arr[c]);
    }
    cout<<"\n";
}
*/
int main() {
    cout<<"Enter no.of coins:";
    cin>>N;
    int d[N+1];
    d[0]=0;
    cout<<"Enter the denominations:\n";
    for(int i=1;i<=N;i++){
        cin>>d[i];
    }
    cout<<"Enter the amount:";
    cin>>A;
    int C[A+1];
    int S[A+1];
    coinChange(d, C, S);
    /*
    cout<<"\nC[p]\n";
    display(C);
    cout<<"\nS[p]\n";
    display(S);*/
    cout<<"\nMinimum coins required: "<<C[A]<<endl;//<<A<<" ="<< C[A]<<"\n";
    //cout<<"\nCoin Set\n";
    coinSet(d, S);
    return 0;
}







/*
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V){
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];
    // Base case (If given value V is 0)
    table[0] = 0;
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++){
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
            if (coins[j] <= i){
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}

// Driver program to test above function
int main()
{
    int coins[20],n,v;
    cout<<"Enter no. of coins : ";
    cin>>n;
    for( int i =0;i<n;i++)
    {
        cout<<"Enter coin "<<i+1<<"'s value : ";
        cin>>coins[i];
    }
    cout<<"Enter value : ";
    cin>>v;
	cout << "Minimum coins required is : "<< minCoins(coins, n, v);
	return 0;
}*/
