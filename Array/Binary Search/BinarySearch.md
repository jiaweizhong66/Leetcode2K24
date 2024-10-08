# Introduction

For binary search, it has to be an array in order with no duplicates. If there is duplicates,
the result returned by this algorithm may not be the only one.

There are two ways of coding binary search, [left, right] or [left, right)

Lets start with first one:

- while (left <= right)
  here left == right is meaningful
- if (nums[middle] > target) right will be middle - 1, because here nums[middle] is not the target number

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};
```

Now we can move on to the second way of this algorithm, [left, right)
This is slightly different:

- while loop will be while (left < right)
- if (nums[middle] > target) then right index will be middle

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};
```

# Complexity Analysis

## Time Complexity:

- the algorithm uses while loop, in each iteration, the search space is reduced by half. Suppose initial search space is n
- After first iteration, search space is n/2
- Then n/4 and so on.

The process continues until space is reduced to 1 element, takes about log2(n) iteration
Hence complexity of this algorithm is O(log(n)) where n is the size of num array.

## Space Complexity:

- It uses constant amount of extra memory for a few integer variable like left, right and middle.
- No recursion meaning no additional space for a call stack.

Memory does not depend on input size n and hence it is O(1)
