//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    struct Node* reverseList(struct Node *head)
    {
        Node* curr = head;
        Node* next;
        Node* prev = NULL;
        
         if(head==NULL)
        {
            return head;
        }
        
        while(curr !=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        }
       
        
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* sl = head;
        Node* fa = head;
        while(fa!=NULL && fa->next!=NULL){
            fa = fa->next->next;
            sl = sl->next;
            
        }
        Node* h = reverseList(sl);  // h pointing to last element now
        sl->next = NULL;

        while(h!=NULL){
            if(head->data!=h->data) 
                return false;
                
            head = head->next;
            h = h->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends