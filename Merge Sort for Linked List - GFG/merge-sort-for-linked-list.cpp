//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution{
  public:
  

    Node* middle(Node* head)
{
    Node* slow = head; 
    Node* fast = head -> next ;
    
    while( fast != NULL  && (fast -> next ) != NULL )      // 1st condition helps when size is odd and second cond. when size is even. 
    {
        slow = slow -> next ;
        fast = fast -> next -> next;
    }
    
    Node* afterMiddle = slow -> next ;     // Storing the address of the node which is just after the mid node.
    slow -> next = NULL ;
    return afterMiddle ;
    
    return 0 ;
}
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL)    //if the size of the list is 0 or 1 then no need to sort . 
            return head;

        Node* afterMiddle = middle(head);          // Storing the address of the node which is just after the mid node.
    
        Node* part1 = mergeSort(head);
        Node* part2 = mergeSort(afterMiddle);        // afterMiddle address's node becomes the head of the 2nd half of the list .
    
        Node *curr1 = part1, *curr2 = part2;
    
        Node *si = NULL, *ei = NULL;           // Starting index and end index .
    
        while(curr1 != NULL && curr2 != NULL){
            if(curr1->data <= curr2->data){
                if(si == NULL){
                    si = curr1;
                    ei = curr1;
                }else{
                    ei->next = curr1;
                    ei = curr1;
                }
                curr1 = curr1->next;
            }else{
                if(si == NULL){
                    si = curr2;
                    ei = curr2;
                }else{
                    ei->next = curr2;
                    ei = curr2;
                }
                curr2 = curr2->next;
            }
        }
    
    
        while(curr1 != NULL){
            ei->next = curr1;
            ei = curr1;
            curr1 = curr1->next;
        }
    
        while(curr2 != NULL){
            ei->next = curr2;
            ei = curr2;
            curr2 = curr2->next;
        }
    
        return si;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends