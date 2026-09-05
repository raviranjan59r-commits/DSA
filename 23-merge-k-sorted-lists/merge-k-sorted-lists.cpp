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
    using pp=pair<int,ListNode*>;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        priority_queue<pp,vector<pp>,greater<pp>> pq;

        for(int i=0;i<n;i++){
            if(lists[i]==nullptr) continue;
            pq.push({lists[i]->val,lists[i]});
        }

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            curr->next=temp.second;

            if(temp.second->next) pq.push({temp.second->next->val,temp.second->next});

            curr=curr->next;
        }

        return dummy->next;
    }
};