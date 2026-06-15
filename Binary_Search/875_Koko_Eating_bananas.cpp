class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        while(s < e){
            long long totl_hr = 0;
            speed = s + (e - s)/2;

            for(int i = 0; i < piles.size(); i++){
                totl_hr += (piles[i] + speed - 1)/speed;
            }

            if(totl_hr <= h){
                e = speed;
            } 
            else{
                s = speed + 1;
            }
        }
        return s;
    }
};
