class MyQueue {
private:
    stack<int> first;
    stack<int> second;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(second.empty())
            first.push(x);
        else{
            while(!second.empty()){
                int temp = second.top();
                second.pop();
                first.push(temp);
            }
            first.push(x);
        }
    }
    
    int pop() {
        int ans;
        if(first.empty()){
            ans = second.top();
            second.pop();
        }
        else{
            while(!first.empty()){
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            ans = second.top();
            second.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans;
        if(first.empty()){
            ans = second.top();
        }
        else{
            while(!first.empty()){
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            ans = second.top();
        }
        return ans;
    }
    
    bool empty() {
        if(first.empty() && second.empty())
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