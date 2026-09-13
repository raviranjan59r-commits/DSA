class Solution{
public:
    //calculate overlap for a particular shift
    int countOverlaps(vector<vector<int>>&A,vector<vector<int>>&B,int rowOff,int colOff){
        int n=A.size();
        int count=0;

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){

                //shifted position is outside the matrix
                if(row+rowOff<0||row+rowOff>=n||col+colOff<0||col+colOff>=n)
                    continue;

                //both cells must contain 1 for an overlap
                count+=A[row][col]*B[row+rowOff][col+colOff];
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>&A,vector<vector<int>>&B){
        int n=A.size();
        int maxOverlap=0;

        //try every possible row shift
        for(int rowOff=-n+1;rowOff<n;rowOff++){

            //try every possible column shift
            for(int colOff=-n+1;colOff<n;colOff++){
                maxOverlap=max(maxOverlap,countOverlaps(A,B,rowOff,colOff));
            }
        }

        return maxOverlap;
    }
};