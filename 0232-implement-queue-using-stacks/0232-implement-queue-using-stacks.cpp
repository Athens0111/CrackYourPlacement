class MyQueue {
private:
    stack<int> first;  // Stack to hold elements temporarily
    stack<int> second; // Stack to hold elements in reverse order to simulate queue

public:
    // Constructor: Initializes an empty queue
    MyQueue() {
    }
    
    // Pushes an element onto the queue
    void push(int x) {
        // If the second stack is empty, push the element directly onto the first stack
        if (second.empty()) {
            first.push(x);
        }
        // If the second stack is not empty, move all elements back to the first stack,
        // then push the new element onto the first stack
        else {
            while (!second.empty()) {
                int temp = second.top();
                second.pop();
                first.push(temp);
            }
            first.push(x);
        }
    }
    
    // Pops the front element from the queue and returns it
    int pop() {
        int ans;
        // If the first stack is empty, pop from the second stack (which holds elements in reverse order)
        if (first.empty()) {
            ans = second.top();
            second.pop();
        }
        // If the first stack has elements, move all of them to the second stack,
        // then pop from the second stack to get the front element
        else {
            while (!first.empty()) {
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            ans = second.top();
            second.pop();
        }
        return ans;
    }
    
    // Returns the front element of the queue without removing it
    int peek() {
        int ans;
        // If the first stack is empty, the front element is on top of the second stack
        if (first.empty()) {
            ans = second.top();
        }
        // If the first stack has elements, move all of them to the second stack,
        // then return the top element of the second stack
        else {
            while (!first.empty()) {
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            ans = second.top();
        }
        return ans;
    }
    
    // Checks if the queue is empty
    bool empty() {
        // The queue is empty if both stacks are empty
        return first.empty() && second.empty();
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