#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node* left;
  node* right;
  string s = "";
  node(int n)
  {
    data = n;
    left = NULL;
    right = NULL;
  }
};
void Right(node* root,int l , int h , vector<int> arr);
void Left(node *root , int l , int h , vector<int> arr)
{
    if(l < h)
    {
        root->left = new node(arr[(l+h)/2]);
        Left(root->left,l,((l+h)/2),arr);
        Right(root->left,((l+h)/2)+1, h,arr);
    }
}
void Right(node* root,int l , int h , vector<int> arr)
{
    if(l < h) 
    {
        root->right = new node(arr[(l+h)/2]);
        Left(root->right,l,((l+h)/2),arr);
        Right(root->right,((l+h)/2)+1, h , arr);
    }
}
void preorder(node* root)
{
    root->s = root->s + to_string(root->data);
    if(root->left != NULL)
    {
        root->s = to_string(root->left->data)+" <- "+root->s;
        preorder(root->left);
    }
    else
    {
        root->s = ". <- "+root->s;
    }
    if(root->right != NULL)
    {
        root->s = root->s+" -> "+to_string(root->right->data);
        preorder(root->right);
    }
    else
    {
        root->s = root->s + " -> .";
    }
}
void preder(node* root)
{
    cout<<root->s<<endl;
    if(root->left != NULL)
    {
        preder(root->left);
    }
    if(root->right != NULL)
    {
        preder(root->right);
    }
}

int main() {
    /* https://unstop.com/code/challange-asesment/250181?moduleId=411 */  
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
      cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    node* root = new node(arr[n/2]);
    Left(root,0,(n/2),arr);
    Right(root,(n/2)+1, n,arr);
    preorder(root);
    preder(root);

    return 0;
}