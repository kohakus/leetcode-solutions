// JavaScript solution.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let size = nums.length;
    if (size === 0) { return [-1, -1]; }

    var insert_pos = function(val) {
        let low = 0, high = size;
        while (low < high) {
            let mid = low + ((high-low) >> 1);
            if (nums[mid] >= val) { high = mid; }
            else { low = mid + 1; }
        }
        return low;
    };

    let pos = insert_pos(target);
    if (pos < size && nums[pos] === target) {
        return [pos, insert_pos(target+1)-1];
    } else {
        return [-1, -1];
    }
};
