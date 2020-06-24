#include<bits/stdc++.h>
using namespace std;

int islan(int A[][100],int n,int m,bool vis[][100],int ii,int jj){
    if(ii>=n||jj>=m)return 0;
    if(ii<0||jj<0)return 0;
    if(A[ii][jj]==0)return 0;
    if(vis[ii][jj]=1)return 0;
    
    vis[ii][jj]=1;
    return (1+islan(A,n,m,vis,ii+1,jj)+
    islan(A,n,m,vis,ii-1,jj)+
    islan(A,n,m,vis,ii,jj+1)+
    islan(A,n,m,vis,ii,jj-1)+
    islan(A,n,m,vis,ii+1,jj+1)+
    islan(A,n,m,vis,ii+1,jj-1)+
    islan(A,n,m,vis,ii-1,jj+1)+
    islan(A,n,m,vis,ii-1,jj-1));
}

int main(){
    int n,m;
    int A[100][100];
    bool vis[100][100];
    int count=0;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
            vis[i][j]=0;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<A[i][j]<<" ";
    //     }cout<<endl;
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && A[i][j]==1){
            int p= islan(A,n,m,vis,i,j);
            count++;
            }
        }
    }

    cout<<"Abhay"<<count;

    return 0;
}