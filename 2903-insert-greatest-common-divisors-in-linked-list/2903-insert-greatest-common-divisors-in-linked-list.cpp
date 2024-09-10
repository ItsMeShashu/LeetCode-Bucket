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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* node1 = head;
        ListNode* node2 = head->next;

        while (node2 != NULL) {
            int gcdValue = __gcd(node1->val, node2->val);  //inbuilt gcd function
            ListNode* gcdNode = new ListNode(gcdValue);

            node1->next = gcdNode;
            gcdNode->next = node2;

            node1 = node2;
            node2 = node2->next;
        }

        return head;
    }
};