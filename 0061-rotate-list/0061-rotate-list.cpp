/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        ListNode* curr = head ;
        int count = 0 ;
        while(curr != NULL) {
            count++ ;
            curr = curr->next ;
        }

        k = k % count ; 
        if(k==0) return head ;
        ListNode* pt1 = head;
        ListNode* pt2 = head ;

        while(k--){
            pt2 = pt2->next ;
        }
        while(pt2->next != NULL){
            pt1 = pt1->next; 
            pt2 = pt2->next; 
        }

        curr = pt1->next ;
        pt2->next = head; 
        pt1->next = NULL; 

        return curr; 
   
    }
};