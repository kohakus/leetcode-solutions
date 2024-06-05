// C++ solution.

struct Node {
    int key;
    int val;
    int freq;
};

class LFUCache {
public:
    LFUCache(int capacity) : _cap{capacity}, _minfreq{0} {}

    int get(int key) {
        if (_tbl.count(key) <= 0) { return -1; }
        int val = _tbl[key]->val;
        adjustFreqLists(_tbl[key]);
        return val;
    }

    void put(int key, int value) {
        if (!_cap) { return; }
        if (_tbl.count(key) > 0) {
            _tbl[key]->val = value;
            adjustFreqLists(_tbl[key]);
        } else {
            if (_tbl.size() >= _cap) {
                _tbl.erase(_lists[_minfreq].back().key);
                _lists[_minfreq].pop_back();
                if (_lists[_minfreq].empty()) {
                    _lists.erase(_minfreq);
                }
            }
            _lists[1].emplace_front(key, value, 1);
            _tbl[key] = _lists[1].begin();
            _minfreq = 1;
        }
    }

private:
    void adjustFreqLists(const std::list<Node>::iterator& it) {
        int key = it->key;
        int val = it->val;
        int freq = it->freq;

        _lists[freq].erase(it);
        if (_lists[freq].empty()) {
            _lists.erase(freq);
            if (_minfreq == freq) {
                _minfreq++;
            }
        }
        _lists[freq+1].emplace_front(key, val, freq+1);
        _tbl[key] = _lists[freq+1].begin();
    }

private:
    std::unordered_map<int, std::list<Node>> _lists;
    std::unordered_map<int, std::list<Node>::iterator> _tbl;
    int _cap;
    int _minfreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
