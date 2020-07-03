#include<bits/stdc++.h>
using namespace std;

int maxsquare(int A[][101],int n,int m){
    int maxx=INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            A[i][j]=1+min(A[i-1][j],A[i][j-1]);
            maxx=max(maxx,A[i][j]);
        }
    }
    return maxx;
}

int main(){

    int n,m;
    int A[101][101];
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>A[i][j];   }// A[i].push_back(x);}

    cout<<maxsquare(A,n,m);
    return 0;
}