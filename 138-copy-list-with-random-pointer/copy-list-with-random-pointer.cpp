/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
                if (!head) return NULL;

        Node* temp = head;

        while(temp){
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = n->next;
        }
        temp = head;
        while(temp){
            if(temp->random)temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        
        temp = head;
        Node* newhead = head->next;
        while(temp){
            Node* copy = temp->next;
            temp->next = copy->next;

            if(copy->next) copy->next = copy->next->next;
            temp = temp->next;
        }
        
        return newhead;
    }
};