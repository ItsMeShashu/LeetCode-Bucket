class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) 
            return 0;
        int diff = nums[1] - nums[0], cnt = 2, ans = 0;
        for(int i = 2; i < n; i++){
            if(diff == nums[i]-nums[i-1]) cnt++;
            else{
                if(cnt >= 3) ans += (cnt)*(cnt+1)/2 - 2*cnt + 1;
                diff = nums[i] - nums[i-1];
                cnt = 2;
            }
        }
        if(cnt >= 3) ans += (cnt)*(cnt+1)/2 - 2*cnt + 1;
        return ans;
    }
};