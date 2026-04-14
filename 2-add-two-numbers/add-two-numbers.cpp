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
        int curr = 0;

        ListNode* temp1 = l1, *temp2 = l2;
        ListNode* dum = new ListNode(0);
        ListNode* temp = dum;

        while(temp1 && temp2){
            int sum = temp1->val + temp2->val +curr;
            curr = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int sum = temp1->val +curr;
            curr = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            temp1 = temp1->next;
        }

        while(temp2){
            int sum = temp2->val +curr;
            curr = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            temp2 = temp2->next;
        }

        if(curr) temp->next = new ListNode(curr);
        return dum->next;
    }
};