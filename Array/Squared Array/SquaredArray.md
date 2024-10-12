# Squared Array

[Leetcode #977](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

You are given a sort array in descend order. nums = [-4,-1,0,3,10], you need to square all elements [16,1,0,9,100] and return the
array in descent order as well, so we need to return [0,1,9,16,100]

For this question, we also have brute force and double pointers.

## Brute Force:

Very Easy to understand, square the array and then sort it.

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // Quick Sort in C++
        return A;
    }
};
```

Time Complexity: O(n + nlogn)
Since we O(n) to iterate and square the array and O(nlogn) to sort
Space Complexity: O(log n)
Since no extra space for the square, but need O(log n) for the sorting
