class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s1.empty() && s2.empty()) return -1;
        if(!s2.empty()) {
            int x= s2.top(); 
            s2.pop();
            return x;
        }
        else
        {
            while(!s1.empty()){
                int x=s1.top(); s1.pop();
                s2.push(x);
            }
            int x= s2.top(); 
            s2.pop();
            return x;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(s1.empty() && s2.empty()) return -1;
        if(!s2.empty()) {
            int x= s2.top();
            return x;
        }
        else
        {
            while(!s1.empty()){
                int x=s1.top();  
                s1.pop();
                s2.push(x);
            }
            int x= s2.top();
            return x;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty()) return 1;
        return 0;
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
