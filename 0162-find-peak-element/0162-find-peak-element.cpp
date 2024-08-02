class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size(); 
        int s = 0;
        int e = n-1;
        
        while(s<e){
            int mid = s + (e-s)/2 ; 
            if(arr[mid] <= arr[mid + 1]){
                // e = mid ;
                s = mid + 1;
            }
            else{
                // s = mid + 1;
                e = mid ;
            }
        }
        
        return e;
    }
};