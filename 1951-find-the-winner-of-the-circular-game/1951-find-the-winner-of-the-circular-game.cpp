class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for (int i = 1; i <= n; ++i) {
            circle.push_back(i);
        }
        int currIndx = 0;

        while (circle.size() > 1) {
            int elemToRemove = (currIndx + k - 1) % circle.size();
            circle.erase(circle.begin() + elemToRemove);
            currIndx = elemToRemove;
        }

        return circle[0];
    }
};