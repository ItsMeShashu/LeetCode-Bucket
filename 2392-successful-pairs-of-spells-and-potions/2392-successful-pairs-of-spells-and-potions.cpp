class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans;
        sort(potions.begin(),potions.end());

        for(int i=0;i<n;i++)
        {
            long long spell = spells[i];

            int s = 0;
            int e = m;
            while(s < e)
            {
                int mid = (e + s)/2;
                if(spell * potions[mid] >= success) e = mid;
                else  s = mid + 1;
            }
            ans.push_back(m - s);
        }
        return ans;
    }
};