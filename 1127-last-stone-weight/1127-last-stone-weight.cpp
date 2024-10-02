class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ; 

        for(int num: stones){
            pq.push(num) ; 
        }

        while(pq.size() > 1){
            int num1 = pq.top(); 
            pq.pop(); 
            int num2 = pq.top(); 
            pq.pop() ; 

            int diff = abs(num1 - num2) ; 
            if(diff == 0) continue; 
            else pq.push(diff) ; 
        }

        if(pq.size() == 1) return pq.top(); 
        else return 0 ; 
    }
};