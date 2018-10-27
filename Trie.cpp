#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    struct TrieNode *children[28];
    int cnt[28];
    bool enode;
    
};
struct TrieNode *get(void)
{
    struct TrieNode *p= new TrieNode();
    p->enode=false;
    for(int i=0;i<28;i++)
    { 
        p->children[i]=NULL;
        p->cnt[i]=0;
    }
    return p;
    
}
struct TrieNode *root=get();
void insert(string s)
{
    struct TrieNode *temp=root;
    int t;
    for(int i=0;i<s.length();i++)
    {
        t=s[i]-'a';
        temp->cnt[t]+=1;
        if(temp->children[t]==NULL)
        {
            temp->children[t]=get();
        }
        temp=temp->children[t];
    }
    temp->enode=true;
}
int search(string s)
{
    int n=s.size();
    int t;
    struct TrieNode *temp=root;
    for(int i=0;i<n;i++)
    {
        t=s[i]-'a';
        if(temp->children[t]==NULL)
        {
            return 0;
        }
        if(i==n-1)
        {
            return temp->cnt[t];
        }
        temp=temp->children[t];
    }
    return -1;
    
}
int main() {
    int x;
    cin>>x;
    while(x--)
    {
        string s,t;
        cin>>s;
        if(s=="add")
        {
            cin>>t;
            insert(t);
        }
        else
        {
            cin>>t;
            cout<<search(t)<<endl;
        }
    }
    return 0;
}
