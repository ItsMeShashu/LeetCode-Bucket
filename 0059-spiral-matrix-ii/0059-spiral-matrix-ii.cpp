class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, -1)); 

        int elems = 1; 
        int totalElems = n * n; 

        int startRow = 0;
        int startCol = 0;
        int endRow = n - 1;
        int endCol = n - 1 ;

        while(elems <= totalElems){
            
            for(int i = startCol; elems <= totalElems && i<=endCol; i++){
                matrix[startRow][i] = elems;
                elems++;
            }
            startRow++ ;    

            for(int i = startRow; elems <= totalElems && i<=endRow; i++){
                matrix[i][endCol] = elems;
                elems++;
            }
            endCol--;

            for(int i = endCol; elems <= totalElems && i>=startCol; i--){
                matrix[endRow][i] = elems;
                elems++;
            }
            endRow-- ;

            for(int i = endRow; elems <= totalElems && i>=startRow; i--){
                matrix[i][startCol] = elems;
                elems++;
            }
            startCol++;      
        }
        
        return matrix ;
    }
};