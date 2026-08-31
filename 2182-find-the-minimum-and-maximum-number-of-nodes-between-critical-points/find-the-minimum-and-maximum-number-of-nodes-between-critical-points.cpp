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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==nullptr) return {-1,-1};

        ListNode* l=head;
        ListNode* m=head->next;
        ListNode* r=m->next;

        vector<int> v;
        int i=0;
        while(r){
            if(m->val > l->val && m->val > r->val){
                v.push_back(i);
            } 
            else if(m->val < l->val && m->val < r->val){
                v.push_back(i);
            }
            l=m;
            m=r;
            r=r->next;
            i++;
        }
        //v contain the indexes of the critical points 
        //now find minimum and maximum 
        if(v.size()<2) return {-1,-1};
        int mindist=INT_MAX;
        int maxdist=-1;

        for(int i=1;i<v.size();i++){
            mindist=min(v[i]-v[i-1],mindist);
        }

        maxdist=v.back()-v[0];

        return {mindist,maxdist};
        
    }
};