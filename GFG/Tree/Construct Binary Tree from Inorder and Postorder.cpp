//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{   
    unordered_map<int,int>inOrderVal;
    public:
    Node *constructNode(int post[], int postStart, int postEnd, int in[], int inStart, int inEnd){
        
        if(postStart > postEnd || inStart > inEnd){return NULL;}
        
        Node* newRoot = new Node(post[postEnd]);
        int elem = inOrderVal[newRoot->data];
        int nElem = elem - inStart;
        
        newRoot->left = constructNode(post, postStart, postStart + nElem -1, in, inStart, elem-1);
        newRoot->right = constructNode(post, postStart+nElem, postEnd-1, in,elem+1, inEnd);
        
        return newRoot;
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        
        /*
            -> find the root :- last element post order
            -> check boundary in inorder from the root node
        */
        
        inOrderVal.clear();
        
        for(int i=0;i<n;i++){
            inOrderVal[in[i]] = i;
        }
        
        
        return constructNode(post, 0, n-1, in, 0, n-1);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends