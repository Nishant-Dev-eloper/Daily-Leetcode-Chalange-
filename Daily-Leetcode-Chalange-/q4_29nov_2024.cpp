/*
  2577. Minimum Time to Visit a Cell In a Grid
  Solved
  Hard
  Topics
  Companies
  Hint
  You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].
  
  You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.
  
  Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.
  
   
  
  Example 1:
  
  
  
  Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
  Output: 7
  Explanation: One of the paths that we can take is the following:
  - at t = 0, we are on the cell (0,0).
  - at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
  - at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
  - at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
  - at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
  - at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
  - at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
  - at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
  The final time is 7. It can be shown that it is the minimum time possible.
  Example 2:
  
  
  
    Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
    Output: -1
    Explanation: There is no path from the top left to the bottom-right cell.
   
  
    Constraints:
    
    m == grid.length
    n == grid[i].length
    2 <= m, n <= 1000
    4 <= m * n <= 105
    0 <= grid[i][j] <= 105
    grid[0][0] == 0
    
*/

class Solution {
public:
    using p = pair<int, pair<int, int>>;
    vector<vector<int>> direction ={{0,1},{0,-1},{1,0},{-1,0}};

    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][1] >1 && grid[1][0]>1){
            return -1;
        }   
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>> result(n, vector<int>(m, INT_MAX)); 
        result[0][0]=0;// we take vector to store curr time 
        // initially our time is 0

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // initially we can't visit anywhere so mark all spaces with false.

        while(!pq.empty()){
            int time =pq.top().first;
            int row =pq.top().second.first;
            int col =pq.top().second.second;
            pq.pop();

            if(row ==n-1 && col==m-1){
                return result[n-1][m-1];
            }
            if(visited[row][col]==true){
                continue;
            }
            visited[row][col]=true;

            for(auto &dir: direction){
                int i= row + dir[0];
                int j= col + dir[1];
                if(i<0 || i>=n ||j<0 ||j>=m){ // boundary condition 
                    continue;
                }
                if(grid[i][j] <=time+1){
                    pq.push({time+1,{i,j}});
                    result[i][j] =time+1;
                }
                else if((grid[i][j]-time ) %2==0){ // for even
                    pq.push({grid[i][j]+1 ,{i,j}});
                    result[i][j] =grid[i][j]+1;

                }
                else{ // for odd
                    pq.push({grid[i][j] ,{i,j}});
                    result[i][j] =grid[i][j];

                }
            }
        }
        return result[n-1][m-1];

    }
};
