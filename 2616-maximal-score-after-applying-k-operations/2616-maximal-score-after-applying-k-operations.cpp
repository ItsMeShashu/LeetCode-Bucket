class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin(), nums.end()) ; 
        long long ans  = 0 ;

        while(k--){
            ans += pq.top(); 
            long long val = ceil((double)pq.top()/3.0) ; 
            pq.pop(); 
            pq.push(val) ; 
        }

        return ans ; 
    }
};