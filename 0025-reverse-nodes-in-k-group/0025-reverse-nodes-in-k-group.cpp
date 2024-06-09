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
    ListNode* reverseKGroup(ListNode* head, int k) {    
        // Base condition
        ListNode* temp = head ;
        for(int i=0; i<k; i++){
            if(temp == NULL)
                return head ;
            temp = temp->next ;
        }
        // Small work
        ListNode* prev = NULL ;
        ListNode* fwd = NULL ;
        ListNode* current = head ;
        int count = 0 ;
        while(current != NULL && count < k)  {                           
            fwd = current -> next ;
            current -> next = prev ;
            prev = current ;       
            current = fwd ;        
            count++ ;
        }
        // Recursion
        if(current != NULL) head -> next = reverseKGroup(current, k) ;         
        return prev ;
    }
};