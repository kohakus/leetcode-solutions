// JavaScript solution.
/**
 * @param  {number[]} nums
 * @param  {number}   target
 * @return {number[]}
 */

var twoSum = function(nums, target) {
    let hash = new Map();
    for (const [k, v] of nums.entries()) {
        if (hash.has(target-v)) return [hash.get(target-v), k];
        else hash.set(v, k);
    }
    return [];
};
