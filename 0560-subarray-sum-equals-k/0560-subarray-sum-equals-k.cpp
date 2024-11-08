class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> Map;
        int sum = 0;
        int count = 0;
        // Map[sum] = 1; 

        for(auto it:nums){
            sum = sum + it ;
            if(sum == k) count++; 

            int rem = sum - k; 
            if(Map.find(rem) != Map.end()){
                count += Map[rem]; 
            }

            Map[sum]++; 
        }

        return count; 
    }
};

