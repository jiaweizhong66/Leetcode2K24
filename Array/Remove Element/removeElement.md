# Removing Element Introduction

Question: Give you an array nums, and a int val. Remove all elements equal to the val and return the length of the new array.
Do not use extra space for array, you must only use extra O(1)

Element sequence can change, you dont need to worry about elements exceeding the length of the new array.

If nums = [3,2,2,3], val = 3, then 2 should be returned and first two elements of the array should be 2 as 3 are "removed"

Two methods: Brute force and two pointers.

## Brute Force:

For loop in a for loop, with one for loop iterate through the array and the inner for loop update the array.

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--;
            }
        }
        return size;

    }
};
```

Time Complexity: O(n^2) this is easy to understand
Space Complexity: O(1)

## Double Pointers:

Utilizing slow fast pointer in one for loop to finish the job of double for loop.

Slow pointer: point to the index of updated array element
Fast pointer: find element of new array which is the array that does not contain the target element

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
```

Time Complexity: O(n)
Space Complexity: O(1)
