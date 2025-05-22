#include <iostream>
#include <vector>
using namespace std;

class Solution { /* time complexity : o(n^3)*/
    public:
    bool isPossible(int row, int col, int n, vector<string> &board) {
        int r = row, c = col;

        // Check upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        // Check same row on the left
        r = row;
        c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            c--;
        }

        // Check lower-left diagonal
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r++;
            c--;
        }

        return true;
    }

    public:
    void backtrack(vector<vector<string>> &ans, int n, vector<string> &board, int col) {
        if (col == n) {  //base case when column reched last position
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isPossible(row, col, n, board)) {
                board[row][col] = 'Q';  // Place queen
                backtrack(ans, n, board, col + 1);
                board[row][col] = '.';  // Backtrack
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        backtrack(ans, n, board, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string &row : solutions[i]) {
            cout << row << '\n';
        }
        cout << '\n';
    }

    return 0;
}
/* using hash : Time complexity : o(n^2) - optimised
class Solution {
    public:
    void backtrack(vector<vector<string>>&ans, int n, vector<string>&board, int col, vector<int>&leftCol, vector<int>&lowerDiagonal,vector<int>&upperDiagonal){
        if(col == n){   //base case when column reched last position
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(leftCol[row] == 0 && upperDiagonal[row + col] == 0  && lowerDiagonal[(n-1) + (col - row)]==0){
                board[row][col] = 'Q';  // Queen placed
                leftCol[row] = 1;  //mark
                upperDiagonal[row+col] = 1;
                lowerDiagonal[(n-1) + (col - row)] = 1;
                backtrack(ans, n, board, col+1, leftCol, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';  // backtrack
                leftCol[row] = 0;   //remove mark
                upperDiagonal[row+col] = 0;
                lowerDiagonal[(n-1) + (col - row)] = 0;
            }

        }

    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

        vector<string>board(n); // datastructure
        string s(n,'.');
        for(int i = 0; i<n; i++){ //creating board
            board[i] = s;
        }
        //using hashing 
        vector<int> leftCol(n,0), lowerDiagonal(2*n-1), upperDiagonal(2*n-1);

        backtrack(ans, n, board, 0, leftCol, lowerDiagonal, upperDiagonal); // function call

        return ans;
    }
};
*/
/*Enter value of N: 4

Total solutions: 2

Solution 1:
..Q.
Q...
...Q
.Q..

Solution 2:
.Q..
...Q
Q...
..Q.
*/