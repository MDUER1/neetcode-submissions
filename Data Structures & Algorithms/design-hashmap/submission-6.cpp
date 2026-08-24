class MyHashMap {
private:
    vector<int> data;
public:
    MyHashMap() : data(10000001, -1) {}

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }

};
