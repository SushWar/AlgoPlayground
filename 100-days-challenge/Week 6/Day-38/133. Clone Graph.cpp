#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(!node){
            // cout<<"empty"<<endl;
            return NULL;
        }

        // cout<<node->val;
        // return node;
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        map<int,Node*>order;
        unordered_set<int>visit;
        
        queue<Node*>travel;
        travel.push(node);
        visit.insert(node->val);

        Node * res;
        while(!travel.empty()){
            Node* take = travel.front();
            travel.pop();

            int data = take->val;
            cout<<endl;
            // cout<<"On => "<<data<<endl;
            
            Node* clone;
            if(!order.count(data)){
                clone = new Node(data);
                order[data] = clone;
            }
            else{
                clone = order[data];
            }
            res = clone;
            // if(take->neighbors.size()==0) continue;
            for(auto x: take->neighbors){
                int temp = x->val;
                if(!visit.count(temp)){
                    travel.push(x);
                    visit.insert(temp);
                }
                
                Node* friends;
                if(!order.count(temp)){
                    friends = new Node(temp);
                    order[temp] = friends;
                }
                else{
                    friends = order[temp];
                }
                // cout<<"friends => "<<temp;
                clone->neighbors.push_back(friends);

            }
        }
        


        return order[1] ;
    }
};