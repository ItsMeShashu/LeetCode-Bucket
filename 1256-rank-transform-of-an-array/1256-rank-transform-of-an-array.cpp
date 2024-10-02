class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int> , greater<int>> pq ; 
        unordered_map<int, int> mp ; 

        for(int num:arr){
            pq.push(num) ; 
        }
        int i=1 ; 
        while(!pq.empty()){
            if(mp[pq.top()] == 0){
                mp[pq.top()] = i ;
                i++ ; 
            } 
            pq.pop() ;  
        }

        for(int i=0; i<arr.size(); i++){
            int val = mp[arr[i]] ; 
            arr[i] = val  ;
        }

        return arr ; 
    }
};