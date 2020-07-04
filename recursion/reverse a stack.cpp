#include<bits/stdc++.h>
using namespace std;

void print(stack<int> &s){
    if(s.empty())return ;

    int x=s.top();
    cout<<x<<" ";
    s.pop();
    print(s);
    s.push(x);
}

void put_at_end(stack<int> &s, int x){
    if(s.empty()){s.push(x);return ;}

    int y=s.top();
    s.pop();

    put_at_end(s,x);

    s.push(y);
}

void stack_reverse(stack<int> &s){

    if(s.size()<=1)return;
    
    int x=s.top();
    s.pop();
    stack_reverse(s);
    put_at_end(s,x);

}


int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s.push(6);
    // s.push(7);
    // s.push(8);
    // s.push(9);
    // s.push(10);
    print(s);

    stack_reverse(s);

    print(s);
    
}