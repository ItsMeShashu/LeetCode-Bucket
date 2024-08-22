#include <bits/stdc++.h>

class Solution {
public:
    int numberOfBits(int n) {
        int count = 0;
    
        while (n > 0) {
            count++;
            n = n/2 ; 
        }

        if(count > 0) return count ; 
        else return 1 ;  // Return 1 for the case where n is 0
    }

    int findComplement(int num) {
        int numBits = numberOfBits(num);

        int mask = (1LL << numBits) - 1;

        int comp = num ^ mask;

        return comp;
    }
};