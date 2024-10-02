class Solution {
public:

    long long memFunc(vector<vector<int>>& questions, vector<long long >& dp, int n, int idx ){
        if(idx >= n){
            return 0; 
        }

        if(dp[idx] != -1) return dp[idx] ; 

        long long inc = INT_MIN ;
        long long exc = INT_MIN ;

        inc = questions[idx][0] + memFunc(questions, dp, n, idx+questions[idx][1]+1) ;   
        exc = memFunc(questions, dp, n, idx+1) ;   

        dp[idx] = max(inc, exc) ; 
        return dp[idx] ; 
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size() ; 
        vector<long long> dp(n, -1) ; 

        return memFunc(questions, dp, n, 0) ; 
    }
};