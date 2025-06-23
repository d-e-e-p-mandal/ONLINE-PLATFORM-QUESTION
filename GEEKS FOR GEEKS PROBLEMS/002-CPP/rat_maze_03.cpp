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
 public:
    void findPath(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &visited, vector<string> &ans, string move, int di[], int dj[]){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        
        //mark visited
        visited[i][j] = 1;
        //check using loop
        string s = "DLUR";
        for(int ind = 0; ind < 4; ind++){
            if(isSafe(i+di[ind], j+dj[ind], n, maze, visited))
                findPath(i+di[ind], j+dj[ind], n, maze, visited, ans, move + s[ind], di, dj);
        }
        
        //backtrack removed mark
        visited[i][j] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        // Direction = "Down-Left-Up-Right"
        int di[] = {1, 0, -1, 0}; 
        int dj[] = {0, -1, 0, 1};
        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<string>ans;
        //function call
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        findPath(0, 0, n, maze, visited, ans,"", di, dj);
        
        sort(ans.begin(), ans.end());
        
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