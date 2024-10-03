class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        unordered_map<int, int> mp;
        int length = 0;
        for (int i = 0; i < arr.size(); i++){
            int count= 0;
            int rem = arr[i] - difference ;
            if (mp.find(rem) != mp.end())
                count = mp[rem];

            mp[arr[i]] = 1 + count;

            length = max(mp[arr[i]], length);
        }

        return length;
    }
};