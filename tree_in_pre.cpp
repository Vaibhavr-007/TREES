#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node * right;
    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void postorder(node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node * check(vector<int>&pre,int prestart,int preend,vector<int>&in,int instart,int inend,unordered_map<int,int>&mp){
    if(prestart>preend || instart> inend){
        return NULL;
    }
    node * root=new node(pre[prestart]);
    int val=mp[root->data];
    int numsleft=val-instart;
    root->left=check(pre,prestart+1,prestart+numsleft,in,instart,val-1,mp);
    root->right=check(pre,prestart+numsleft+1,preend,in,val+1,inend,mp);
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int> pre(n),in(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        cin>>pre[i];
    }
    for(int i=0;i<n;++i){
        cin>>in[i];
        mp[in[i]]=i;
    }
    node * root=check(pre,0,n-1,in,0,n-1,mp);
    postorder(root);
    return 0;
}