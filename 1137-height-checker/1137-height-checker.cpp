class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0 ;
        int n = heights.size(); 
        vector<int> exp(n);
        exp = heights ;  

        sort(exp.begin(), exp.end()) ;

        for(int i=0 ;i<n; i++){
            if(heights[i] != exp[i]) count++; 
        }

        return count ;
    }
};