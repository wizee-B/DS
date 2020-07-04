#include<bits/stdc++.h>
using namespace std;


    bool Match(string s, string p) {
        if(s.size()==0 && p.size()==0)return true;
        if(s.size()==0 || p.size()==0)return false;
        if(s==p)return true;
        //if(s=="aab" && p=="c*a*b")return true;
        
        char c=p[0];
        char d=s[0];
        p.erase(p.begin()+0);

        if(c=='.' || c==d){s.erase(s.begin()+0);return Match(s,p);}
        
        
        if(c=='*'){
            bool b=false;
            while(s.size()!=0 && s[0]==d && b==false){
                b|=Match(s,p);
                s.erase(s.begin()+0);
            }
            //s.erase(s.begin()+0);
            b|=Match(s,p);
            
            return b;
        }
        
        return false;
    }


int main(){
    string a="aaaab",b="*b";
    cout<<Match(a,b);
    return 0;
}