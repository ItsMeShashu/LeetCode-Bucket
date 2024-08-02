class Solution {
    public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(); 
        // vec = nums + nums ;
        vector<int>vec(nums.begin(), nums.end()) ;
        vec.insert(vec.end(), nums.begin(), nums.end()) ;

        int ones = 0 ;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) ones++ ;
        } 
        if(ones == 0) return 0 ; 

        int zeros = 0, minZeros = INT_MAX;
        for(int j=0; j<ones; j++){
            if(vec[j] == 0) zeros++ ;
        }
        minZeros = min(minZeros, zeros) ;

        for(int j = ones; j<vec.size(); j++){
            if(vec[j] == 0) zeros++; 
            if(vec[j-ones] == 0) zeros-- ; 
            minZeros = min(minZeros, zeros) ;
        }

        return minZeros;   
    }
};