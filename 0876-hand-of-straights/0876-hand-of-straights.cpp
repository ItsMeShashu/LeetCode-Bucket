class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }
        sort(hand.begin(), hand.end());
        
        for (int i = 0; i < n; i++) {
            if (mp[hand[i]] == 0) {
                continue;
            }
            for (int j = 0; j < groupSize; j++) {
                int currCard = hand[i] + j;

                if (mp[currCard] == 0) {
                    return false;
                }

                mp[currCard]--;
            }
        }
        return true;
    }
};