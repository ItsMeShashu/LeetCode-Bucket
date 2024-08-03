class Solution {
public:

    int flipsCount(vector<int>& arr){
        int flips = 0; 
        int s = 0, e = arr.size() - 1 ; 
        while(s < e){
            if(arr[s] != arr[e]){
                flips++ ;
            }
            s++; 
            e-- ;
        }

        return flips ; 
    }

    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size();  //cols

        int rowflips = 0 ;
        for(int i=0; i<m; i++){
            rowflips += flipsCount(grid[i]); 
        }

        int colFlips = 0 ; 
        for(int j=0; j<n; j++){
            vector<int> col(m) ;
            for(int i=0; i<m; i++){
                col[i] = grid[i][j] ; 
            }
            colFlips += flipsCount(col) ; 
        }

        return min(rowflips, colFlips) ; 
    }
};