class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if (matrix.empty()) return {};   // FIX: check before accessing matrix[0]

        int m = matrix.size();//rows
        int n = matrix[0].size();//columns
        int dir = 0;

        /*
            dir=0 left to right
            dir=1 top to bottom
            dir=2 right to left
            dir=3 down to top
        */

        vector<int> result;
        int top = 0, down = m - 1;
        int left = 0, right = n - 1;

        while (top <= down && left <= right) {
            if (dir == 0) {
                //left to right
                //contant row(top)
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if (dir == 1) {
                //top to down
                //constant col(right)
                for (int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (dir == 2) {
                //right to left
                //constant row(down)
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            else if (dir == 3) {
                //bottom to top
                //constant col(left)
                for (int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            dir++;
            if (dir == 4) {
                dir = 0;
            }
        }

        return result;
    }
};
