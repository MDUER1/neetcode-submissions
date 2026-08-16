class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

    void moveToOutput()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        moveToOutput();

        int value{output.top()};
        output.pop();

        return value;
    }
    
    int peek() {
        moveToOutput();

        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};