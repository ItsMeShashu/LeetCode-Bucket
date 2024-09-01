class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans ;
        int sz = original.size();

        if(m*n != sz) return ans ; 

        int i = 0 ; 
        while(i<sz){
            vector<int> vec ;
            while(i<sz && vec.size() != n){
                vec.push_back(original[i]); 
                i++ ; 
            }

            if(vec.size() == n) ans.push_back(vec) ;  
        } 

        return ans ; 

    }
};