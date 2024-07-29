class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;
        for(int i=0; i<n; i++){
            int leftSmaller = 0, leftBigger = 0, rightSmaller = 0, rightBigger = 0;
            for(int j=i-1; j>=0; j--){
                if(rating[j] < rating[i]) leftSmaller++;
                else leftBigger++;
            }
            for(int j=i+1; j<n; j++){
                if(rating[j] < rating[i]) rightSmaller++;
                else rightBigger++;
            }
            result += (leftSmaller * rightBigger + leftBigger * rightSmaller); 
        }
        return result;
    }
};