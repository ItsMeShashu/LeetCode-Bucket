class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int maxDist = 0 ; 
        int smallest = arr[0][0] ; 
        int largest = arr[0].back() ;

        for(int i=1; i<arr.size(); i++){
            maxDist = max(maxDist, arr[i].back() - smallest) ; 
            maxDist = max(maxDist, largest - arr[i][0]) ; 
            largest = max(largest, arr[i].back()) ;
            smallest = min(smallest, arr[i][0]) ;
        } 

        return maxDist ; 
    }
};