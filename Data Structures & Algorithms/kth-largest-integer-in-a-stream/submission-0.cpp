class KthLargest {
private:
    int k;

    // The template arguments mean: 
    //1. int, what type of values are stored
    //2. std::vector<int>, What container stores them internally
    //3. greater<int> tells the priority queue that smaller values have higher priority
    // std::priority_queue defaults to int, std::vector<int> and std::less<int>.
    // std::less<int> and std::greater<int> is the diff and they are comparison functions used by the heap algorithm.
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
