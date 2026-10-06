
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 class MyHashMap {
private:
    static const int SIZE = 769;
    vector<list<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(int key, int value) {
        auto& bucket = buckets[hash(key)];
        for (auto& p : bucket) {
            if (p.first == key) {
                p.second = value;   // update existing key
                return;
            }
        }
        bucket.emplace_back(key, value);
    }

    int get(int key) {
        auto& bucket = buckets[hash(key)];
        for (auto& p : bucket) {
            if (p.first == key) return p.second;
        }
        return -1;
    }

    void remove(int key) {
        auto& bucket = buckets[hash(key)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};