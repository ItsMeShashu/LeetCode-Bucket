class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0; 
         
        for(auto str : logs){
            if(str == "./") continue; 
            else if(str == "../"){
                if(count>0) count--; 
                continue; 
            }
            else{
                count++; 
            }
        }

        return count ; 
    }
};