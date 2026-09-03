class NumArray {
public:
    vector<int> arr;
    vector<int>blocks;
    int n;
    int blocksize;
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        blocksize=ceil(sqrt(n));
        blocks.resize(blocksize,0);

        for(int i=0;i<n;i++){
            int blockidx=i/blocksize;

            blocks[blockidx]+=arr[i];
        }
    }
    
    void update(int index, int val) {
        int blockidx=index/blocksize;


        blocks[blockidx] = blocks[blockidx] - arr[index] + val;
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        int left_block_idx=left/blocksize;
        int right_block_idx=right/blocksize;
        int sum=0;
        if(left_block_idx == right_block_idx){
            for(int i=left;i<=right;i++){
                sum+=arr[i];
            }
            return sum;
        }
        //left sum -> left to this complete left block

        for(int i=left;i<=((left_block_idx + 1) * blocksize)-1;i++){
            sum+=arr[i];
        }

        // middle/complete block sum

        for(int i=left_block_idx + 1;i<=right_block_idx - 1;i++){
            sum+=blocks[i];
        }

        //right sum -> right block sum till right

        for(int i=(right_block_idx * blocksize) ;i<=right;i++){
            sum+=arr[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */