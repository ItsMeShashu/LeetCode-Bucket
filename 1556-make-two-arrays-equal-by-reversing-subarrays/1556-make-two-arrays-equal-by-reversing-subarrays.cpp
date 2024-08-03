class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // arrays with same elements and with same frequencies can always be rearranged such that they will be equal.

        vector<int> tCount(1001);
        vector<int> aCount(1001);

        for(auto i : target){
            tCount[i]++ ;
        }
        for(auto i : arr){
            aCount[i]++ ;
        }

        return (tCount == aCount) ; 
    }
};