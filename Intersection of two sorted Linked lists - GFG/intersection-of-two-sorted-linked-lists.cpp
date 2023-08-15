//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head = NULL;
    Node* temp = NULL;
    
    while(ptr1 && ptr2){
        if(ptr1->data == ptr2->data){
            if(head == NULL){
                Node* newNode = new Node(ptr1 -> data);
                head = newNode;
                temp = newNode;
            }
            else{
                Node* newNode = new Node(ptr1 -> data);
                temp->next = newNode;
                temp = newNode;
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->data > ptr2->data){
            ptr2 = ptr2->next ;
        }
        else{
            ptr1 = ptr1->next;
        }
    }
    
    return head ;
    
    
}