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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head; 
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;  

        while(curr->next != NULL){
            int sum = 0 ;
            curr = curr->next; 
            while(curr->val != 0){
                sum += curr->val; 
                curr = curr->next; 
            }
            ListNode* newNode =  new ListNode(sum); 
            temp->next = newNode; 
            temp = temp->next; 
        }

        return ans->next; 
    }
};