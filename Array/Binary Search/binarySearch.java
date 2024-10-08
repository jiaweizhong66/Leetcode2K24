class Solution {
    public int search(int[] nums, int target) {
        if (target < nums[0] || target > nums[nums.length - 1]) {
            return -1;
        }
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            // >> 1 is the bit wise shift operator, shifts the bits of number to the right
            // by 1 which is equal to divide by 2
            // Similarly >> 2 will be equal to be divided by 4
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else { // nums[mid] > target
                right = mid - 1;
            }
        }
        // 未找到目标值
        return -1;
    }
}