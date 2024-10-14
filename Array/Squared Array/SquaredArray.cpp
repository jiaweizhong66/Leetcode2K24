class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // Quick Sort in C++
        return A;
    }
};

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& A) {
//         int k = A.size() - 1;
//         vector<int> result(A.size(), 0);
//         for (int i = 0, j = A.size() - 1; i <= j;) {
//             if (A[i] * A[i] < A[j] * A[j])  {
//                 result[k--] = A[j] * A[j];
//                 j--;
//             }
//             else {
//                 result[k--] = A[i] * A[i];
//                 i++;
//             }
//         }
//         return result;
//     }
// };