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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while(curr){
            curr = curr->next;
            count++;
        }
        if(count == n) return head->next;
        ListNode* temp = head;
        for(int i = 0; i < count - n-1; i++){
            temp = temp->next;
        }
        ListNode* nxt = temp->next->next;
        temp->next = nxt;
        return head;
    }
};