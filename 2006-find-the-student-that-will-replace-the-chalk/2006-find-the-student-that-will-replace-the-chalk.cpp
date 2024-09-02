class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size() ; 
        long long sum  =  0 ; 
        for(int i=0; i<n; i++){
            sum += chalk[i] ; 
        }
        while(k >= sum){
            k = k - sum ; 
        }
        int i ; 
        for(i=0; i<n; i++){
            if(k >= chalk[i]) k = k-chalk[i] ; 
            else break ; 
        }

        return i ; 
    }
};