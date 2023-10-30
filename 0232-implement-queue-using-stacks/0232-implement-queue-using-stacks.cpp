class MyQueue {
public:
    stack<int>s1, s2 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x) ;
    }
    
    int pop() {
        if(s1.empty()){
            return -1 ;
        }
        while(!s1.empty()){
            int val = s1.top();
            s1.pop();
            s2.push(val) ;
        }    

        int ans = s2.top() ;
        s2.pop() ;

        while(!s2.empty()){
            int val = s2.top();
            s2.pop();
            s1.push(val) ;
        }

        return ans ;
    }
    
    int peek() {
        while(!s1.empty())  
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */