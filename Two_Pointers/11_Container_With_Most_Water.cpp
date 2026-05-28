class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer appraoch
        int l = 0;
        int r= height.size()-1;
        int maxe = INT_MIN;
        while(l < r){
            int len = min(height[l], height[r]);
            int bre = r - l;
            maxe = max(len * bre, maxe);

            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxe;
    }
};
