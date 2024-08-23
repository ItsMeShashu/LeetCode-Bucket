class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size() ; 
        vector<pair<int, int>> vec ; 
        priority_queue<int> pq ; 

        for(int i=0; i<n; i++){
            vec.push_back({capital[i], profits[i]}) ; 
        } 

        sort(vec.begin(), vec.end()) ; 
        int j = 0 ; 
        for(int i=0; i<k; i++){
            while(j < n && vec[j].first <= w){
                pq.push(vec[j].second) ; 
                j++ ; 
            }

            if(pq.empty()) break ; 

            w += pq.top() ;
            pq.pop() ;  
        }

        return w; 
    }
};