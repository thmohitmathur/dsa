class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // simple sliding window appraoch
        int l = 0;
        int pro = 0;
        for(int r = 0; r < prices.size(); r++){
            if(prices[r] < prices[l]){
                l = r;
            }else{
                pro = max(prices[r] - prices[l], pro);
            }
        }
        return pro;
    }
};
