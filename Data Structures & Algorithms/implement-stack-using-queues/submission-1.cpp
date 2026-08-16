class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() = default;
    
    void push(int x) {
        q.push(x);

        for (std::size_t i{0}; i < q.size() - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int value{q.front()};
        q.pop();

        return value;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};