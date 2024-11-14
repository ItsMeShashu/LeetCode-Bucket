class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1, e = *max_element(quantities.begin(), quantities.end());
        while(s < e){
            int mid = s + (e-s)/2;
            int total = 0;
            for(int quantity:quantities){
                total += ceil((double)quantity / (double)mid);
            }
            if(total <= n){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s; 
    }
};