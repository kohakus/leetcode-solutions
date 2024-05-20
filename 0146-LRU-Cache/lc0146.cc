// C++ solution.

class LRUCache {
public:
    LRUCache(int capacity) : _cap{capacity} {
    }
    
    int get(int key) {
        if (_tbl.count(key) == 0) {
            return -1;
        }
        _lst.splice(_lst.begin(), _lst, _tbl[key]);
        return _lst.front().second;
    }
    
    void put(int key, int value) {
        if (_tbl.count(key) > 0) {
            _lst.splice(_lst.begin(), _lst, _tbl[key]);
            _lst.front().second = value;
        } else {
            _lst.emplace_front(key, value);
            _tbl[key] = _lst.begin();
            if (_lst.size() > _cap) {
                _tbl.erase(_lst.back().first);
                _lst.pop_back();
            }
        }
    }
private:
    using object = std::pair<int, int>;
    std::list<object> _lst;
    std::unordered_map<int, std::list<object>::iterator> _tbl;
    int _cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
