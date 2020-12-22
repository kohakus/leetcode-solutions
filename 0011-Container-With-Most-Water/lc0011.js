// JavaScript solution.

/**
 * @param {number[]} height
 * @return {number}
 */

var maxArea = function(height) {
    let left = 0, right = height.length-1;
    let ret = 0;
    while (left < right) {
        const currArea = (right - left) * height[height[left] < height[right] ? left++ : right--];
        ret = currArea > ret ? currArea : ret;
    }
    return ret;
};
