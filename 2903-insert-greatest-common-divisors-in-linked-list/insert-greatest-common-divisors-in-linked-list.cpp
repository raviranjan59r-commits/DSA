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
        if(head==NULL || head->next==nullptr) return head;

        ListNode * slow=head;
        ListNode * fast=head->next;

        while(fast){
            ListNode* new_node=new ListNode(gcd(slow->val,fast->val));

            slow->next=new_node;
            new_node->next=fast;

            slow=fast;
            fast=fast->next;
        }
        return head;
    }
};