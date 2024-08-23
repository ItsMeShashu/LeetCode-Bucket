class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        priority_queue<int> pq ;
        vector<int> ans ;
        int i=0, j=k; 
        for(int it=0; it<k; it++){
            pq.push(nums[it]) ;
            mp[nums[it]]++; 
        }
        ans.push_back(pq.top()); 

        while(j<nums.size()){
            mp[nums[j]]++; 
            pq.push(nums[j]); 
            mp[nums[i]]--; 
            i++ ;

            while(mp[pq.top()] <= 0){
                pq.pop(); 
            }
            // if(mp[pq.top()] > 0){  
            //     ans.push_back(pq.top()); 
            // }
            ans.push_back(pq.top());
            j++ ;
        }

        return ans ;
    }
};