#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z){
    return min(min(x, y), z);
}

int editDist(string str1, string str2, int m, int n){
    // Create a table to store results of subproblems
    int dp[m+1][n+1];

    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
    return dp[m][n];
}

// Driver program
int main(){
    string a,b;
    cout<<"Enter 2 strings :\n";
    cin>>a>>b;
    cout << editDist( a , b , a.length(), b.length());
    return 0;
}







/*
#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z){
    return min(min(x, y), z);
}
int editDist(string a , string b , int m ,int n){
    if (m == 0) return n;
    if (n == 0) return m;
    if (a[m-1] == b[n-1])
        return editDist(a, b, m-1, n-1);
    return 1 + min ( editDist(a, b, m, n-1), // Insert
        editDist(a, b, m-1, n), // Remove
        editDist(a, b, m-1, n-1) // Replace
    );
}
int main(){
    string a,b;
    cout<<"Enter 2 strings :\n";
    cin>>a>>b;
    cout << editDist( a , b , a.length(), b.length());
    return 0;
}
*/
