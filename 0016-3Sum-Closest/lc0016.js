// JavaScript solution.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var threeSumClosest = function(nums, target) {
    let sz = nums.length;
    if (sz < 3) { return -1; }
    else { nums.sort((a,b) => a-b); }
    let best_match = 0, min_diff = 2147483647;

    for (var i = 0; i < sz-2; i++) {
        if (i > 0 && nums[i] === nums[i-1]) continue;
        let left = i+1, right = sz-1;
        while (left < right) {
            let sum = nums[i] + nums[left] + nums[right];
            let diff = Math.abs(sum-target);
            if (diff === 0) { return target; }
            if (diff < min_diff) {
                min_diff = diff;
                best_match = sum;
            }
            if (sum > target) right--;
            else left++;
        }
    }
    return best_match;
};
