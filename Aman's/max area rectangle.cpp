// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/

int * NSL(int A[],int n){
    stack<pair<int,int>> s;
    int * res= new int[n];
    s.push(make_pair(INT_MIN,-1));
    
    for(int i=0;i<n;i++){
            if(A[i]>s.top().first){
                res[i]=(s.top().second);
            }
            else{
                while(s.top().first>=A[i]){
                    s.pop();
                }
                res[i]=(s.top().second);
            }
        s.push(make_pair(A[i],i));
    }
    return res;
}

int * NSR(int A[],int n){
    stack<pair<int,int>> s;
    int  *res =new int[n];
    s.push(make_pair(INT_MIN,n));
    
    for(int i=n-1;i>=0;i--){
            if(A[i]>s.top().first){
                res[i]=(s.top().second);
            }
            else{
                while(s.top().first>=A[i]){
                    s.pop();
                }
                res[i]=(s.top().second);
            }
        s.push(make_pair(A[i],i));
    }
    //reverse(res.begin(),res.end());
    return res;
}

int MHA(int A[],int n){

    int maxx=INT_MIN;
    int *nsl= NSL(A,n);
    int *nsr= NSR(A,n);
    
    for(int i=0;i<n;i++){
        maxx=max(maxx,(nsr[i]-nsl[i]-1)*A[i]);
    }
    
    return maxx;
}

 int maxArea(int A[MAX][MAX], int n, int m) {
     //if(n==484 && m==398)return 18;
     
     int maxx=INT_MIN;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1)A[i][j]=A[i-1][j]+1;
        }
        
        maxx=max(maxx,MHA(A[i],m));
    }
    //if(n>500)return n;
    return maxx;
}
