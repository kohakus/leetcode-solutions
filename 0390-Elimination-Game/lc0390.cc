// C++ solution.

// Josephus-like Problem
// https://en.wikipedia.org/wiki/Josephus_problem
// the core idea is to find: ML(1..n) + MR(1..n) = n+1
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n/2 - lastRemaining(n / 2));
    }
};


// [Additional]
// Josephus problem
// There are n people standing in a circle waiting to be executed.
// The counting out begins at some point in the circle and proceeds
// around the circle in a fixed direction. In each step, a certain
// number of people are skipped and the next person is executed.
// The elimination proceeds around the circle, until only the last person
// remains, who is given freedom. Given the total number of persons n and
// a number k which indicates that k-1 persons are skipped and kth person
// is killed in circle. The task is to choose the place in the initial circle
// so that you are the last one remaining and so survive.
//
// josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
// josephus(1, k) = 1
