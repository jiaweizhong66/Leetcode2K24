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

## Double Pointers

Array are given as sorted, but square of negative numbers can be largest. The largest number of squared array then must from either left side of original array or right most side of original array.

We define a new array called result, which is the one we should be returning. We add a pointer to point at the last position. We should have another two pointers A and B pointing at the left and right most of original array. Square the number they are pointer to , if square of left pointer is larger than square of right pointer number, insert that squared number to result array, left pointer move one element to the right. If not, then right pointer move one to the left. Continue until two pointers met, which means we have iterate through the entire array.

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};
```

Time Complexity: O(n)
