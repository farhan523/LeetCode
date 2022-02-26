class MyQueue {
    stack<int>stk1;
    stack<int>stk2;
    int top;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if(!stk2.empty()){
             top = stk2.top();
            stk2.pop();
            return top;
        }
         while(!stk1.empty()){
             top = stk1.top();
            stk1.pop();
            stk2.push(top);
        }
         top = stk2.top();
            stk2.pop();
            return top;
    }
    
    int peek() {
         if(!stk2.empty()){
             top = stk2.top();
           
            return top;
        }
        while(!stk1.empty()){
             top = stk1.top();
            stk1.pop();
            stk2.push(top);
        }
         top = stk2.top();
           
            return top;
    }
    
    bool empty() {
        if(stk1.empty() && stk2.empty())
            return true;
        return false;
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