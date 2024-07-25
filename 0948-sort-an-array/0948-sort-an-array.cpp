class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size(); 
        priority_queue<int, vector<int>, greater<int>> prq;
        
        for(int i=0; i<n; i++){
            prq.push(arr[i]);
        }
        while(prq.empty() == false){
           ans.push_back(prq.top());
           prq.pop();
        }
        return ans;
    }
};