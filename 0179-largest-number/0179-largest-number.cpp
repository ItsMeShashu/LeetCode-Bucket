class Solution {
public:

    // static bool cmp(int a, int b){
    //     string first = to_string(a) + to_string(b);
    //     string second = to_string(b) + to_string(a);
    //     return first>second;
    // } 

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(), [](int a, int b){
            string first = to_string(a) + to_string(b);
            string second = to_string(b) + to_string(a);
            return first>second;
        });
        string ans="";
        
        for(int i=0;i<nums.size();i++) 
            ans+= to_string(nums[i]);

        if(ans[0] == '0')
            return "0";
                
        return ans;
    }
};