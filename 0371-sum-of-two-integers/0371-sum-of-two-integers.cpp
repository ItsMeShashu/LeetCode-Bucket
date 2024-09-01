class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;    // 0 << 1  ==> 0
        }
        return a; 


    }
};