// JavaScript solution.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var search = function(nums, target) {
    let low = 0, high = nums.length;
    while (low < high) {
        let mid = (low + high) >> 1;
        let num = (target < nums[0]) === (nums[mid] < nums[0]) ? nums[mid] :
            target < nums[0] ? -2147483648 : 2147483647;

        if (num === target) { return mid; }
        else if (num < target) { low = mid + 1; }
        else { high = mid; }
    }
    return -1;
};
