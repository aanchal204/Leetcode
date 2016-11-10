/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

https://leetcode.com/problems/spiral-matrix/
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_start,col_start,row_end,col_end;
        vector<int> spiral;
        row_start = col_start = 0;
        row_end = matrix.size()-1;
        if(row_end == -1)
            return spiral;
        if(row_end == 0){
            for(int i=0;i<matrix[0].size();i++)
                spiral.push_back(matrix[0][i]);
                return spiral;
        }
        col_end = matrix[0].size()-1;
        if(col_end == 0){
            for(int i=0;i<matrix.size();i++)
                spiral.push_back(matrix[i][0]);
            return spiral;
        }
        
        while(row_start<=row_end && col_start<=col_end){
            int i,j;
            for(i=row_start,j=col_start; j<=col_end;j++)
                spiral.push_back(matrix[i][j]);
            row_start++;
            for(i++,j=col_end;i<=row_end;i++)
                spiral.push_back(matrix[i][j]);
            col_end--;
            if(row_start <= row_end){
                for(i=row_end,j--;j>=col_start;j--)
                    spiral.push_back(matrix[i][j]);
                row_end--;
            }
            if(col_start <= col_end){
                for(i--,j=col_start;i>=row_start;i--)
                    spiral.push_back(matrix[i][j]);
                col_start++;
            }
            
        }
        return spiral;
    }
};