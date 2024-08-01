class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count  = 0; 
        for(auto str: details){
            string temp = ""; 
            temp.push_back(str[11]);
            temp.push_back(str[12]);

            int age = stoi(temp); 
            if(age > 60) count++; 
        }

        return count; 
    }
};