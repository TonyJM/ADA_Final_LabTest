#include <bits/stdc++.h>
using namespace std;
//void lcs( char *X, char *Y, int m, int n )
void lcs( string X, string Y, int m, int n ){
    int L[m+1][n+1];
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    int index = L[m][n];
    cout<<"Length:"<<L[m][n]<<endl;
    //char lcs[index+1];
    //lcs[index] = '\0';
    string lcs="";
    int i = m, j = n;
    while (i > 0 && j > 0){
        if (X[i-1] == Y[j-1]){
            //lcs[index-1] = X[i-1];
            lcs=X[i-1]+lcs;
            i--; j--; index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    cout << "LCS:" << lcs<<"\n";
}
int main(){
//char X[30],Y[30];
    string X,Y;
    cout<<"Enter 1st Sequence:";
    cin>>X;
    cout<<"Enter 2nd Sequence:";
    cin>>Y;
    int m = X.length();//strlen(X);
    int n = Y.length();//strlen(Y);
    lcs(X, Y, m, n);
    return 0;
}
