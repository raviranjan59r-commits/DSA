class Solution {
public:
    vector<int> path;
    void helper(int label){
        if(label==0) return;
        path.push_back(label);
        int row=log2(label);

        int lower_range=pow(2,row);
        int upper_range=pow(2,row+1) -1;
        int correct_num=(lower_range + upper_range) - label;

        helper(correct_num/2);
    }
    vector<int> pathInZigZagTree(int label) {
        helper(label);
        reverse(path.begin(),path.end());
        return path;
    }
};