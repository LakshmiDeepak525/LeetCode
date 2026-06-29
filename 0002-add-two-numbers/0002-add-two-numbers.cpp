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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current = new ListNode(0);
        ListNode* head = current;
        
        int sum = 0;
        int digit = 0;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
           int ll1 = 0;
           int ll2 = 0; 
          if(l1 != NULL){
           ll1 = l1->val;
          }
          if(l2 != NULL){
           ll2 = l2->val;
          }

           sum = ll1 + ll2 + carry;
           digit = sum % 10;
           carry = sum / 10;

           current->next = new ListNode(digit);
           current = current->next;
           
           if(l1 != NULL){
            l1 = l1->next;
           }
           if(l2 != NULL){
            l2 = l2->next;
           }
        }
        return head->next;
    }
};