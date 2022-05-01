/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.


*/


class Solution{
    public:
     
    void solution(vector<vector<int>> &m , string cur , int n , int x , int y , vector<string> &res , vector<vector<int>> &v){
        
        if(x == n-1 && y == n-1)
            {res.push_back(cur);
            
                return ;
            }
            
            if(v[x][y] == 1)
                return ;
              if(x> 0 && m[x-1][y] == 1){
                  
              v[x][y] = 1;
                solution(m , cur +"U" , n , x-1 , y,res , v);
                
                v[x][y] = 0;
              }
            if(x <n-1 && m[x+1][y] == 1){
                 v[x][y] = 1;
                solution(m , cur +"D" , n , x+1 , y,res, v);
                v[x][y] = 0;
            }
                
            if(y > 0 && m[x][y-1] == 1){
                 v[x][y] = 1;
                    solution(m, cur+"L" , n , x , y-1 , res,v);
                    v[x][y] = 0;
            }
                
            if(y <n-1 && m[x][y+1] == 1){
                 v[x][y] = 1;
                    solution(m, cur+"R" , n , x , y+1 , res, v);
                    
                     v[x][y] = 0;
        
            }
        
        
        
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> res;
        vector<vector<int>> visited(n,vector<int>(n, 0));
       if(m[0][0] == 1)
        solution(m , "", n ,0 , 0, res, visited   );
        if(res.size() == 0)
            res.push_back("-1");
        return    res;
    }
};

    
