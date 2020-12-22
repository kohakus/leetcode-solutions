// JavaScript solution.

/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    let ret = [];
    if (nums.length < 3) { return ret; }
    else { nums.sort((a,b) => a-b); }

    for (var i = 0; i < nums.length-2; i++) {
        if (i > 0 && nums[i] === nums[i-1]) continue;
        let left = i+1, right = nums.length-1;
        while (left < right) {
            if (nums[left]+nums[right] === -nums[i]) {
                ret.push([nums[i], nums[left], nums[right]]);
                while (left < right && nums[left] === nums[left+1]) left++;
                while( left < right && nums[right] === nums[right-1]) right--;
                left++; right--;
            } else if (nums[left]+nums[right] < -nums[i]) {
                left++;
            } else { right--; }
        }
    }
    return ret;
};
