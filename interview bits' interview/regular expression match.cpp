#include<bits/stdc++.h>
using namespace std;

bool match(string a,string b,int i,int j,int n,int m){
    //if a.sub(i)==b.sub(j) return true;
    if(i>=n && j>=m)return true;
    if(a.substr(i,n-i)==b.substr(j,m-j))return true;

    if(a[i]==b[j])return (a,b,i+1,j+1,n,m);

    if(b[j]=='*'){
        char c=a[i];
        bool boo=false;
        //boo|=match(a,b,i,j+1,n,m);
        while(a[i]==c && i<n){
            boo|=match(a,b,i,j+1,n,m);
            i++;
        }
        if(i==n){boo|=match(a,b,i,j+1,n,m);}
        return boo;
    }

    if(b[j]=='?')return match(a,b,i+1,j+1,n,m);

    return false;
}

int main(){
    string a="aaaa",b="*";
    cout<<match(a,b,0,0,a.length(),b.length());
    return 0;
}