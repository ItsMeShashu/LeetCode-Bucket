class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //O(N) approach...........
        int n = nums.size();
        unordered_map<int,int> m ;
        for(int i =0 ; i< n ; i++){
            m[nums[i]]++;
        }

        for(int i =0 ; i< n ; i++){
            if(m[nums[i]] > n/2){
                return nums[i];
            }
        }

        return -1; 
        
    }
};