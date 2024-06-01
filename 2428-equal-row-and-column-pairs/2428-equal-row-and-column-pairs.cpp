class Solution {
public: 

    // Brute Force O(N^3)......................................
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int count = 0 ;
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                bool isEqual = true ; 

                for(int i=0; i<n; i++){
                    if(grid[r][i] != grid[i][c]){
                        isEqual = false; 
                        break ;
                    }                                 
                }

                if(isEqual) count++ ;

            }
        }

        return count ;
    }
};