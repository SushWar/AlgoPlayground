#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<double>maxiHeap;
    priority_queue<double,vector<double>,greater<double>>minHeap;
    int size;
public:
    MedianFinder() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        int maxiSize = maxiHeap.size(), minSize = minHeap.size();

        if(maxiSize==0) {
            maxiHeap.push(num);
            return;
        }

        if(size%2==0){
            if(maxiHeap.top() >= num){
                minHeap.push(maxiHeap.top());
                maxiHeap.pop();
                maxiHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
        }
        else{
            if(minHeap.top() <= num){
                maxiHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else{
                maxiHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(size%2==0){
            return (maxiHeap.top() + minHeap.top())/2;
        }
        else{
            return maxiHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */