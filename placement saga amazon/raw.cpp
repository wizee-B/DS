#include<bits/stdc++.h>
using namespace std;

int mcm(char A[],int ii,int jj){
    if(jj<=ii)return 1;
    if(A[ii]=='0')return mcm(A,ii+1,jj);
    if(A[jj]=='0')return mcm(A,ii,jj-1);
    string a,b="27";
    for(int i=ii;i<=jj;i++)a+=A[ii];
    
    if(a<b)return 1;
    
    int maxx=INT_MIN;
    for(int k=ii;k<=jj;k++){
        int ans=0;
        ans+=mcm(A,ii,k)+mcm(A,k+1,jj);
        
        maxx=max(maxx,ans);
    }
    return maxx;
    
}

int RAW(char A[], int n){
	//write your code here
	for(int i=0;i<n-1;i++){
	    if(A[i]==A[i+1] && A[i]=='0')return -1;
	}
	if(A[0]=='0'||A[n-1]=='0')return -1;
	return mcm(A,0,n-1);
	
}

int main(){
	string input;
	getline(cin,input);
	int n = input.length();
	char char_array[n];
    strcpy(char_array, input.c_str()); 
	int ans = RAW(char_array,n);
	cout<<ans;
	return 0;
}