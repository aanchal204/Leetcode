/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
https://leetcode.com/problems/number-of-islands/
*/
void dfs(char ** grid, int row, int col,int maxRow, int maxCol){
    grid[row][col] = '0';
    if(col+1 < maxCol && grid[row][col+1]=='1')
        dfs(grid,row,col+1,maxRow,maxCol);
    if(row+1 < maxRow && grid[row+1][col]=='1')
        dfs(grid,row+1,col,maxRow, maxCol);
    if(col-1 >= 0 && grid[row][col-1]=='1')
        dfs(grid,row,col-1,maxRow,maxCol);
    if(row-1 >= 0 && grid[row-1][col]=='1')
        dfs(grid,row-1,col,maxRow,maxCol);
    return;
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int i,j,count = 0;
    for(i=0;i<gridRowSize;i++)
    {
        for(j=0;j<gridColSize;j++)
        {
            if(grid[i][j]=='1'){
                dfs(grid,i,j,gridRowSize, gridColSize);
                count++;
            }
        }
    }
    return count;
}