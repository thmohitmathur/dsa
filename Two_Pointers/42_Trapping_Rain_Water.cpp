class Solution {
public:
    int trap(vector<int>& height) {
        // find right and left higest find min trhn subtract current height
        int n = height.size(); 
        int sum = 0;
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        pre[0] = height[0];
        for(int i= 1; i < n; i++){
            pre[i] = max(height[i], pre[i-1]);
        }
        suf[n-1] = height[n-1];
        for(int i= n-2; i >= 0; i--){
            suf[i] = max(height[i], suf[i+1]);
        }

        for(int i = 0; i < n; i++){

            sum += min(suf[i], pre[i]) - height[i];

        }
        return sum;
    }
};
