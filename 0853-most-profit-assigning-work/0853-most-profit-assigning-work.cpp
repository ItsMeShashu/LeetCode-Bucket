class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> diffToProfit;
        for (int i = 0; i < difficulty.size(); i++) {
            diffToProfit.push_back({difficulty[i], profit[i]});
        }
        sort(diffToProfit.begin(), diffToProfit.end());
        
        vector<pair<int, int>> maxProfitForDiff;
        int maxProfit = 0;
        for (auto vec : diffToProfit) {
            int d = vec.first, p = vec.second;
            maxProfit = max(maxProfit, p);
            maxProfitForDiff.push_back({d, maxProfit});
        }
        
        int totalProfit = 0;
        for (int w : worker) {
            int ind = binarySearch(maxProfitForDiff, w);
            if (ind >= 0 && w >= maxProfitForDiff[ind].first) {
                totalProfit += maxProfitForDiff[ind].second;
            }
        }
        return totalProfit;
    }
    
private:
    int binarySearch(vector<pair<int, int>>& list, int work) {
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (list[mid].first <= work) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};