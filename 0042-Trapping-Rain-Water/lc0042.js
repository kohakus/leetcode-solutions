// JavaScript solution.

/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let left = 0, right = height.length-1;
    let leftmax = 0, rightmax = 0;
    let ans = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            leftmax = Math.max(leftmax, height[left]);
            ans += leftmax - height[left];
            left++;
        } else {
            rightmax = Math.max(rightmax, height[right]);
            ans += rightmax - height[right];
            right--;
        }
    }
    return ans;
};
