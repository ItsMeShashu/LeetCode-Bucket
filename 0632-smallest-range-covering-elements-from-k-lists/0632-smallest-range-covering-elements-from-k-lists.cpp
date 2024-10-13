class node{
    public:
    int data;
    int row, col; 
    
    node(int d, int r, int c){
        data = d; 
        row = r;
        col = c ;
    }
};

class comp {
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data ;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& arr) {
        int maxi = INT_MIN, mini = INT_MAX ;
        priority_queue<node* , vector<node*>, comp> minHeap ;
        
        for(int i=0; i<arr.size(); i++){
            int elem = arr[i][0]; // 1st element of each row/list
            mini = min(mini, elem);
            maxi = max(maxi, elem);
            minHeap.push(new node(elem, i, 0)); 
        }
        
        int strt = mini, end = maxi ;
        
        while(minHeap.size() > 0){
            node* curr = minHeap.top() ;
            minHeap.pop();
            
            mini = curr->data ; 
            
            if((maxi - mini) < (end - strt)){
                strt = mini; 
                end = maxi ;
            }
            
            if(curr->col + 1 < arr[curr->row].size()){
                maxi = max(maxi, arr[curr->row][curr->col + 1]); 
                minHeap.push(new node(arr[curr->row][curr->col + 1], curr->row, curr->col+1)); 
            }
            else{
                //1 list over
                break; 
            }
        }
        vector<int> ans ;
        ans.push_back(strt);
        ans.push_back(end);
        return ans ; 
    }
};