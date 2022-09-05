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
void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
node * check(vector<int>&post,int poststart,int postend,vector<int>&in,int instart,int inend,unordered_map<int,int>&mp){
    if(poststart>postend || instart>inend){
        return NULL;
    }
    node * root=new node(post[postend]);
    int val=mp[root->data];
    int numsleft=val-instart;
    root->left=check(post,poststart,poststart+numsleft-1,in,instart,val-1,mp);
    root->right=check(post,poststart+numsleft,postend-1,in,val+1,inend,mp);
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int> post(n),in(n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        cin>>post[i];
    }
    for(int i=0;i<n;++i){
        cin>>in[i];
        mp[in[i]]=i;
    }
    node * root=check(post,0,n-1,in,0,n-1,mp);
    preorder(root);
    return 0;
}