// C++ solution.

/*
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

// binary search method.
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int comp = guess(mid);
            if (comp == -1) {
                right = mid - 1;
            } else  if (comp == 1) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};