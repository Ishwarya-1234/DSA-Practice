class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();

        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == matrix[row][mid]) {
                return true;
            }
            else if (target > matrix[row][mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int stRow = 0;
        int endRow = m - 1;

        while (stRow <= endRow) {
            int midRow = stRow + (endRow - stRow) / 2;

            if (target >= matrix[midRow][0] &&
                target <= matrix[midRow][n - 1]) {

                return searchInRow(matrix, target, midRow);
            }
            else if (target > matrix[midRow][n - 1]) {
                // move down
                stRow = midRow + 1;
            }
            else {
                // move up
                endRow = midRow - 1;
            }
        }

        return false;
    }
};
