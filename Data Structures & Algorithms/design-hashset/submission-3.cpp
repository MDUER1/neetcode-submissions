class MyHashSet {
private:
    static constexpr int SIZE{ 1000 };
    vector<list<int>> buckets;

public:
    MyHashSet() 
        : buckets(SIZE)
    {
    }
    
    void add(int key) {
        if (contains(key))
            return;
        
        int index = key % SIZE;
        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key % SIZE;

        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it ) {
            if (*it == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int index = key % SIZE;

        for (int value : buckets[index]) {
            if (value == key) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */