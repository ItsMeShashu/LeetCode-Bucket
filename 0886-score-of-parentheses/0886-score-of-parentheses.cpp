

class Solution {
public:
    int scoreOfParentheses(string s){
        stack<int> stack;
        int currentScore = 0;
        for(auto&c : s){
            if(c == '('){
                stack.push(currentScore);
                currentScore = 0;
            } 
            else {
                int lastScore = stack.top();
                stack.pop();

                if(currentScore > 0){
                    currentScore = lastScore + 2 * currentScore;
                }
                else{
                    currentScore = lastScore + 1 ;
                }
                
            }
        }
        return currentScore;
    }
};