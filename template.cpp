#include<bits/stdc++.h>
using namespace std;

void islands(int A[][1000],int n,int m,bool vis[][1000],int ii,int jj){
    if(ii>=n||jj>=m || ii<0||jj<0 || A[ii][jj]==0)return ;
    vis[ii][jj]=1;
    islands(A,n,m,vis,ii+1,jj);
    islands(A,n,m,vis,ii-1,jj);
    islands(A,n,m,vis,ii,jj+1);
    islands(A,n,m,vis,ii,jj-1);
}

int main(){
    int n,m;
    int A[10000][1000];
    bool vis[1000][1000]={};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] && A[i][j]==0)continue;
            islands(A,n,m,vis,i,j);
            count++;
        }
    }

    cout<<"Abhay"<<count;

    return 0;
}