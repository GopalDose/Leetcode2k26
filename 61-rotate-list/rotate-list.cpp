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
        if(head==NULL || head->next==NULL|| k==0) return head;
        ListNode* fast = head;
        int count = 0;

        while(fast){
            fast = fast->next;
            count++;
        }
        k %= count;

        fast = head;

        for(int i = 0; i< k; i++) fast = fast->next;

        ListNode* slow = head;

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = head;
        fast->next = temp;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};