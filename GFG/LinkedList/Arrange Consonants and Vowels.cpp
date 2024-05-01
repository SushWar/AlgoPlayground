//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    bool isVowel(char x){
        string check = "aeiou";
        if(check.find(x) < check.size()){return true;}
        return false;
    }
    struct Node* arrangeCV(Node* head) {
        // Code here
        
        /*
            0 - a - b - c - d - e - f - g - h - i
            
        
        */
         Node* vow=new Node('V');
        Node* con=new Node('C');
        Node* temp1=vow;
        Node* temp2=con;
        while(head!=NULL)
        {
            switch(head->data)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    temp1->next=head;
                    temp1=head;
                    break;
                default:
                    temp2->next=head;
                    temp2=head;
                    break;
            }
            head=head->next;
        }
        temp1->next=con->next;
        temp2->next=nullptr;
        head=vow->next;
        delete vow;
        delete con;
        return head;
        
        
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends