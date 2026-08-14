class MyHashMap {
private:
    static constexpr int SIZE{1000};
    vector<list<pair<int, int>>> buckets;

public:
    MyHashMap()
        : buckets(SIZE) 
    {    
    }
    
    void put(int key, int value) {
       int index{key % SIZE};

       for (auto& pair : buckets[index]) // Use ref. to get actual acccess and not a copy
       {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
       }

       buckets[index].emplace_back(key, value);
    }
    
    int get(int key) {
        int index{key % SIZE};

        for (auto pair : buckets[index]) 
        {
            if (pair.first == key) 
            {
                return pair.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int index{key % SIZE};

        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it)
        {
            if (it->first == key)
            {
                buckets[index].erase(it);
                return;
            }
        }
    }
};
