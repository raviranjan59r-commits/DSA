class Solution {
public:
    struct node{
        int maxLen=0;
        int leftMostIdx=-1;
        int rightMostIdx=-1;
    };
    vector<node> st;
    int M=5e4+5;
    node merge(node left,node right){
        if(left.leftMostIdx==-1) return right;
        if(right.leftMostIdx==-1) return left;

        node curr=node();

        curr.maxLen=max({left.maxLen , right.maxLen , right.leftMostIdx-left.rightMostIdx});

        curr.leftMostIdx=left.leftMostIdx;

        curr.rightMostIdx=right.rightMostIdx;

        return curr;
    }
    void update(int i,int l,int r,int idx){
        if(l==r){
            st[i].leftMostIdx=idx;
            st[i].rightMostIdx=idx;
            st[i].maxLen=0;
            return;
        }

        int mid=l+(r-l)/2;

        if(idx<=mid){
            update(i*2+1,l,mid,idx);
        }
        else{
            update(i*2+2,mid+1,r,idx);
        }

        // Recalculate current node
        st[i]=merge(st[i*2+1],st[i*2+2]);
    }
    node getMax(int i,int l,int r,int start,int end){
        if(l>end || r<start) return node();
        if(start<=l  && r<=end) return st[i];
        int mid=l+(r-l)/2;

        node left=getMax(i*2+1,l,mid,start,end);
        node right=getMax(i*2+2,mid+1,r,start,end);

        return merge(left,right);
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n=queries.size();
        st.resize(4*M);
        vector<bool> ans;
        update(0,0,M-1,0);
        for(int i=0;i<n;i++){
            if(queries[i][0]==1){
                update(0,0,M-1,queries[i][1]);
            }
            else{
                node temp=getMax(0,0,M-1,0,queries[i][1]);
                int best=temp.maxLen;
                int x=queries[i][1];

                // Gap from last obstacle to x
                best=max(best,x-temp.rightMostIdx);

                if(best>=queries[i][2]) ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};