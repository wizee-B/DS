#include <bits/stdc++.h> 
using namespace std; 
int static t[101][101];

 int maxsum(int * A,int i,int j){
    if(j-i==0)return A[i];
    if(j-i==1){
        return t[i][j]=max(A[i],A[j]);
    }
    if(t[i][j]!=-1)return t[i][j];
    //if(j+1-i==1)return A[i];
    
    int a,b,c,d;
    a=t[i+2][j];
    b=t[i+1][j-1];
    c=t[i][j-2];
    
     if(a==-1) 
     a=t[i+2][j]=maxsum(A,i+2,j);
     if(b==-1)
     b=t[i+1][j-1]=maxsum(A,i+1,j-1);
     if(c==-1)
     c=t[i][j-2]=maxsum(A,i,j-2);
    
    return t[i][j]=max(A[i]+min(a,b),A[j]+min(c,b));
}

//  int optimalStrategyOfGame(int* arr, int n) 
// { 
//     int table[n][n]; 
//     for (int gap = 0; gap < n; ++gap) { 
//         for (int i = 0, j = gap; j < n; ++i, ++j) { 
//             int x = ((i + 2) <= j) 
//                         ? table[i + 2][j] 
//                         : 0; 
//             int y = ((i + 1) <= (j - 1)) 
//                         ? table[i + 1][j - 1] 
//                         : 0; 
//             int z = (i <= (j - 2)) 
//                         ? table[i][j - 2] 
//                         : 0; 
//             table[i][j] = max( 
//                 arr[i] + min(x, y), 
//                 arr[j] + min(y, z)); 
//         } 
//     } 
//     return table[0][n - 1]; 
// }
 
int main() 
{
    memset(t,-1,sizeof(t));
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];		
	} 
	//cout<<optimalStrategyOfGame(arr, n);
    cout<<maxsum(arr,0,n-1);
	return 0; 
} 
