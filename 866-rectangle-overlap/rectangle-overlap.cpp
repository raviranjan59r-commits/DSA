class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1_left=rec1[0];
        int x1_right=rec1[2];
        int y1_bottom=rec1[1];
        int y1_top=rec1[3];

        int x2_left=rec2[0];
        int x2_right=rec2[2];
        int y2_bottom=rec2[1];
        int y2_top=rec2[3];

        // case 1 x  and y  axis no overlap
        if(x1_left>=x2_right || x1_right<=x2_left || y1_bottom >=y2_top || y1_top<=y2_bottom) return false;

        // case 2 overlap
        return true; 

    }
};