// C++ solution.

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = _cache.find(key);
        if (it == _cache.end()) { return -1; }
        update(it);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = _cache.find(key);
        if (it != _cache.end()) {
            update(it);
            it->second.first = value;
        } else {
            if (_capacity == _cache.size()) {
                _cache.erase(_used.back());
                _used.pop_back();
            }
            _used.push_front(key);
            _cache[key] = {value, _used.begin()};
        }
    }
private:
    // key, value and link
    typedef unordered_map<int, pair<int, list<int>::iterator>> LinkedHash;

    int _capacity;
    list<int> _used;
    LinkedHash _cache;

    void update(LinkedHash::iterator& it) {
        int key = it->first;
        _used.erase(it->second.second);
        _used.push_front(key);
        it->second.second = _used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */