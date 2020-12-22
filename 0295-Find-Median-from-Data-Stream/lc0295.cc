// C++ solution.

// If we have a sorted array, we can find median number easily.
// However, we should deal with data stream, the given numbers can not be sorted in an array efficiently.
// To sorted data dynamically, a natural way is to use heap.
// In this problem we need to find the median number, so we can use two heaps like this:
//                  -
//                -
//              -
//            *
//
//         *
//       -
//     -
//   -
// 1. the left half of the data can be maintained by a max heap, whose data is smaller;
// 2. the right half of the data can be maintained by a min heap, whose data is larger;
class MedianFinder {
public:
    MedianFinder() : _pq_left(), _pq_right() {}

    void addNum(int num) {
        if (_pq_left.empty() || _pq_left.top() > num) {
            _pq_left.push(num);
        } else {
            _pq_right.push(num);
        }

        // make sure balance.
        int left_size = _pq_left.size();
        int right_size = _pq_right.size();
        if (left_size > right_size + 1) {
            _pq_right.push(_pq_left.top());
            _pq_left.pop();
        }
        if (right_size > left_size + 1) {
            _pq_left.push(_pq_right.top());
            _pq_right.pop();
        }
    }

    double findMedian() {
        int left_size = _pq_left.size();
        int right_size = _pq_right.size();
        if (left_size == right_size) {
            return left_size == 0 ? 0 : static_cast<double>(_pq_left.top() + _pq_right.top()) / 2.0;
        } else {
            return left_size > right_size ? _pq_left.top() : _pq_right.top();
        }
    }

private:
    priority_queue<int> _pq_left;
    priority_queue<int, vector<int>, greater<int>> _pq_right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */