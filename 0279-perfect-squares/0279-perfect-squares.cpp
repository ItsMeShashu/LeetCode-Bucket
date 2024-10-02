class Solution {
public:

    int recFunc(int n){
	    if(n == 0){
	        return 0; 
	    }
	    
	    int ans = INT_MAX; 
	    for(int i=1; i<sqrt(n); i++){
	        int newAns = 1 + recFunc(n - i*i) ;
	        ans = min(ans, newAns); 
	    }
	    
	    return ans ; 
	}
	
	int memFunc(int n, vector<int> &dp){
	    if(n <= 0){
	        return 0; 
	    }
	    
	    if(dp[n] != -1){
	        return dp[n]; 
	    }
	    
	    int ans = n; 
	    for(int i=1; i<=sqrt(n); i++){
	        int newAns = 1 + memFunc(n - i*i, dp) ;
	        ans = min(ans, newAns); 
	    }
	    dp[n] = ans ; 
	    return dp[n] ; 
	}
	
	int tabFunc(int n){
	    vector<int> dp(n+1, INT_MAX) ;
	    dp[0] = 0;
	    
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sqrt(n); j++){
                if(i >= j*j)
                    dp[i] = min(1 + dp[i - j*j], dp[i]) ; 
            }
        }
        
        return dp[n] ; 
	}
	
    int numSquares(int n) {
        // return recFunc(n); 
	   
	   vector<int>dp(n+1, -1); 
	   return memFunc(n, dp); 
	    // return tabFunc(n);
    }
};