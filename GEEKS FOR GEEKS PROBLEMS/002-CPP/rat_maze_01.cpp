//GFG : Rat in a Maze : Backtracking
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public :
    //check next move is safe or not if it is safe move forword ,it can also be checked in if statement
    bool isSafe(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &visited) {
        if(i>=0 && i<n && j>=0 && j<n && maze[i][j] == 1 && visited[i][j] == 0) 
            return true;
        return false;
    }
  public :
    void findPath(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>>&visited ,vector<string>&ans,string move) {
        if(i == n-1 && j == n-1){
            ans.push_back(move); //store the ans
            return;
        }
        
        visited[i][j] = 1; // mark visited
        //next direction 
        //down 
        if(isSafe(i+1, j, n, maze, visited)){
            findPath(i+1 ,j ,n, maze, visited, ans, move +"D");
        }
        
        //left 
        if(isSafe(i, j-1, n, maze, visited)){
            findPath(i ,j-1 ,n, maze, visited, ans, move +"L");
        }
        
        //up
        if(isSafe(i-1, j, n, maze, visited)){
            findPath(i-1 ,j ,n, maze, visited, ans, move +"U");
        }
        
        //right
        if(isSafe(i, j+1, n, maze, visited)){
            findPath(i ,j+1 ,n, maze, visited, ans, move +"R");
        }
        //backtrack
        visited[i][j] = 0; // mark removed
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        
        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<string>ans;
        
        if (maze[0][0] == 1) //maze start from (0,0)
            findPath(0, 0, n, maze, visited, ans, "");

        sort(ans.begin(), ans.end()); // 
        
        return ans;
    }
};

int main() {
    // Sample maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    if (paths.empty()) {
        cout << "No path found." << endl;
    } else {
        cout << "Paths found:" << endl;
        for (string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}

/*OUTPUT : Paths found:
["DDRDRR",
"DRDDRR"]*/