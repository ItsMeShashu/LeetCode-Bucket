class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int N = arr.size(); 
        for(int i=0; i<N; i++){
            
            if(arr[i] == 0)
                arr[i] = -1;
        }
        
        unordered_map<int ,int > map;
        int sum = 0, res = 0, len = 0;
        
        for(int i=0; i<N; i++){
            
            sum = sum + arr[i];
            
            if(sum == 0)
                len = i+1;
                
            if(sum != 0){
                
                if(map.find(sum) != map.end()){
                    len = i - map[sum];
                }
            }
            if(map.find(sum) == map.end())
                map[sum] = i;
            
            res = max(len, res);
        }
        return res;
    }
};