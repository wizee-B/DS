#include<bits/stdc++.h>
using namespace std;

static string s;
static int nn;
static int ind[8][2];
static bool vis[100][100];

bool isvalid(int n,int m,int i,int j){
    if(i>=n||j>=m)return 0;
    if(i<0||j<0)return 0;
    return true;
}

bool check(string A[],int n,int m,int x,int y,int index){
    if(index==nn)return true;
   
    cout<<s[index]<<" ";
    vis[x][y]=1;
    bool found=false;

    for(int i=0;i<8;i++){
        int Xprime=x+ind[i][0];
        int Yprime=y+ind[i][1];

        if(isvalid(n,m,Xprime,Yprime) && vis[Xprime][Yprime]==0 && A[Xprime][Yprime]==s[index])
        found |= check(A,n,m,Xprime,Yprime,index+1);
    }

    vis[x][y]=0;
}

int main(){
    s="CODINGCLUB";
    nn=s.length();
    ind[0][0]=-1; ind[0][1]=-1;
    ind[1][0]=-1; ind[1][1]=0;
    ind[2][0]=-1; ind[2][1]=1;
    ind[3][0]=1; ind[3][1]=-1;
    ind[4][0]=1; ind[4][1]=0;
    ind[5][0]=1; ind[5][1]=-1;
    ind[6][0]=0; ind[6][1]=-1;
    ind[7][0]=0; ind[7][1]=1;

    int n,m;
    string A[100];
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
            vis[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;
    }

    cout<<s<<" "<<nn<<" ";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='C'){
                bool fou=check(A,m,n,i,j,1);
                if(fou==true){cout<<"true";return 0;}
            }
        }
    }

    cout<<"false";

    return 0;
}