class Solution {
public:
    bool solve(vector<int>& position, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = position[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 1;
        int e = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (s <= e) {
            int mid = (e + s) / 2;
            if (solve(position, mid, m)) {
                ans = mid;
                s = mid + 1;
            } 
            else  e = mid - 1;
        }
        return ans;
    }
};