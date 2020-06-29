//all the arrays with exactly b numbers of odd numbers
#include<bits/stdc++.h>
using namespace std;

int totalarrays(int a[],int n,int m){
    int count = 0; 
    int prefix[n] = { 0 }; 
    int odd = 0; 
  
    // traverse in the array 
    for (int i = 0; i < n; i++)  
    { 
  
        prefix[odd]++; 
  
        // if array element is odd 
        if (a[i] & 1) 
            odd++; 
  
        // when number of odd elements>=M 
        if (odd >= m) 
            count += prefix[odd - m];  
    } 
  
    return count;
}

//driver function
int main(){
    int n,A[100000],b;

    //taking inputs from user
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    cin>>b;

    //calling computing function with inputted values
    cout<<totalarrays(A,n,b);

    return 0;
}