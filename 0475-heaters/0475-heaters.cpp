class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int m = houses.size();
        int n = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        vector<int> minDist(m, INT_MAX);
        int i =0, j=0; 

        while(i < m && j < n) {
            if(houses[i] <= heaters[j]) {
                minDist[i] = heaters[j] - houses[i];
                i++;
            }
            else j++;
        }

        i = m-1, j=n-1 ; 
        while(i >= 0 && j >= 0) {
            if(houses[i] >= heaters[j]){
                minDist[i] = min(minDist[i], houses[i] - heaters[j]);
                i--;
            }
            else j--;
        }

        return *max_element(minDist.begin(), minDist.end());
    }
};