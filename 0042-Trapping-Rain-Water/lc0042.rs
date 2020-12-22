// Rust solutions.

// O(n) space.
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.is_empty() { return 0; }
        let sz = height.len();
        let mut leftmax: Vec<i32> = vec![height[0]; sz];
        let mut rightmax: Vec<i32> = vec![height[sz-1]; sz];

        for i in 1..sz {
            leftmax[i] = std::cmp::max(height[i], leftmax[i-1]);
        }
        for i in (0..sz-1).rev() {
            rightmax[i] = std::cmp::max(height[i], rightmax[i+1]);
        }

        let mut ans = 0;
        for i in 0..sz {
            ans += std::cmp::min(leftmax[i], rightmax[i]) - height[i];
        }
        ans
    }
}

// O(1) space.
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.is_empty() { return 0; }
        let (mut left, mut right) = (0_usize, height.len()-1);
        let (mut leftmax, mut rightmax) = (0_i32, 0_i32);
        let mut ans = 0;
        while left < right {
            if height[left] < height[right] {
                leftmax = std::cmp::max(leftmax, height[left]);
                ans += leftmax - height[left];
                left += 1;
            } else {
                rightmax = std::cmp::max(rightmax, height[right]);
                ans += rightmax - height[right];
                right -= 1;
            }
        }
        ans
    }
}
