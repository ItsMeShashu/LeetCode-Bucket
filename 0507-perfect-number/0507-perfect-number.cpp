class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        int i = 1;

        while(i <= num/2 ){
            if(num % i == 0){
                sum += i; 
            }
            i++; 
        }

        if(sum == num)
            return true;
        else
            return false;     
    }
};