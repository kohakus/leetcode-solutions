// JavaScript solution.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */

var fourSum = function(nums, target) {
    nums = nums.sort((a,b) => a-b);
    let ans = [];
    if (nums.length < 4) { return ans; }

    for (let a = 0; a < nums.length-3; a++) {
        if (a > 0 && nums[a] === nums[a-1]) continue;
        for (let b = a+1; b < nums.length-2; b++) {
            if (b > a+1 && nums[b] === nums[b-1]) continue;
            let _target = target - nums[a] - nums[b];
            let left = b+1, right = nums.length-1;
            while (left < right) {
                let sum = nums[left] + nums[right];
                if (sum === _target) {
                    ans.push([nums[a], nums[b], nums[left], nums[right]]);
                    while (left < right && nums[left] === nums[left+1]) left++;
                    while( left < right && nums[right] === nums[right-1]) right--;
                    left++; right--;
                } else if (sum < _target) {
                    left++;
                } else { right--; }
            }
        }
    }
    return ans;
};
