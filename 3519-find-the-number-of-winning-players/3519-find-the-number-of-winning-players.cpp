class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int, int>> vec(n) ;

        for(auto i: pick){
            int p = i[0];
            int c = i[1];
            vec[p][c]++;
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            for (auto mp : vec[i]) {
                if (mp.second > i) {
                    ans++;
                    break;  
                }
            }
        }

        return ans ;
    }
};