class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq1;

        priority_queue<int,vector<int>,greater<int> > pq2;

        for(auto num:nums){
            pq1.push(num-1);
            pq2.push(num-1);

            if(pq1.size()>2) pq1.pop();
            if(pq2.size()>2) pq2.pop();
        }
        int a=pq1.top();
        pq1.pop();
        int b=pq1.top();

        int c=pq2.top();
        pq2.pop();
        int d=pq2.top();

        return max(a*b,c*d);
    }
};