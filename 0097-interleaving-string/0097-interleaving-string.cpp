class Solution {
public:

    bool solve(string A, string B, string C,int indxa,int indxb,int indxc,vector<vector<int>>&dp){
        if(indxa==A.size() and indxb==B.size() and indxc==C.size()){
            return true;
        }
        if(indxc==C.size() and (indxb<B.size() || indxa<A.size()) ){
            return false;
        }
        
        if(dp[indxa][indxb] != -1){
            return dp[indxa][indxb];
        }
        
        bool lenA=0, lenB=0;
        
        if(A[indxa] == C[indxc]){
            lenA = solve(A,B,C,indxa+1,indxb,indxc+1,dp);         //0 or 1
        }
        if(B[indxb]==C[indxc]){
            lenB= solve(A,B,C,indxa,indxb+1,indxc+1,dp);          // 0 or 1
        }
        
        return dp[indxa][indxb] = max(lenA, lenB);
    }
   
   
    bool isInterleave(string A, string B, string C) {
        int a = A.length();
        int b = B.length();
        int c = C.length();
        if((a+b) != c){
            return false;
        }
        if( (a == 0 && (b != c)) || (b==0 && (a != c)) ){
            return false ;
        }
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        return solve(A,B,C,0,0,0,dp);
    }
};