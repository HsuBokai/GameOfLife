#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector< vector<int> >& board) {
        int m = board.size();
        if(m <= 0) return;
        int n = board[0].size();
        if(n <= 0) return;
        bool more_up = false, more_down = false, more_left = false, more_right = false;
        vector<int> up(n,0);
        vector<int> down(n,0);
        for(int j=1; j+1<n; ++j){
            if(board[0][j] == 1 && board[0][j-1] == 1 && board[0][j+1] == 1 ) {
                up[j]=1;
                more_up = true;
            }
            if(board[m-1][j] == 1 && board[m-1][j-1] == 1 && board[m-1][j+1] == 1 ) {
                down[j]=1;
                more_down = true;
            }
        }
        vector<int> left(m,0);
        vector<int> right(m,0);
        for(int i=1; i+1<m; ++i){
            if(board[i][0] == 1 && board[i-1][0] == 1 && board[i+1][0] == 1 ) {
                left[i]=1;
                more_left = true;
            }
            if(board[i][n-1] == 1 && board[i-1][n-1] == 1 && board[i+1][n-1] == 1 ) {
                right[i]=1;
                more_right = true;
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                board[i][j] |= ( count_neighbors(board,i,j) <<1);
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                update(board,i,j);
            }
        }
        
        if(more_up) board.insert(board.begin(), up);
        if(more_down) board.push_back(down);
        
        if(more_left){
            for(int i=0; i<m; ++i){
                board[i].insert(board[i].begin(), left[i]);
            }
        }
        if(more_right){
            for(int i=0; i<m; ++i){
                board[i].push_back(right[i]);
            }
        }
    }
private:
    int count_neighbors(vector< vector<int> >& board, int i, int j){
        int start_i = (i==0) ? 0:-1;
        int start_j = (j==0) ? 0:-1;
        int m = board.size();
        int n = board[0].size();
        int end_i = (i==m-1) ? 0:1;
        int end_j = (j==n-1) ? 0:1;
        int sum = 0;
        for(int ii=start_i; ii<=end_i; ++ii) {
            for(int jj=start_j; jj<=end_j; ++jj) {
                sum += board[i+ii][j+jj]%2;
            }
        }
        sum -= board[i][j]%2;
        return sum;
    }
    void update(vector< vector<int> >& board, int i, int j){
        int sum = board[i][j]>>1;
        if(sum < 2) board[i][j]=0;
        else if(sum==2) board[i][j] = board[i][j]%2;
        else if(sum==3) board[i][j] = 1;
        else board[i][j] = 0;
    }
};

int main() {
    Solution s;
    int a1_str[] = {1,0,1,1,1,1,1,1};
    vector<int> a1(a1_str, a1_str + 8);
    vector< vector<int> > board;
    board.push_back(a1);
    board.push_back(a1);
    int time = 2;
    while(time--){
    	s.gameOfLife(board);
        for(int i=0; i<28; ++i) cout << '\n';
        cout << "===\n";
	int m = board.size();
	int n = board[0].size();
        for(int i=0; i<28; ++i) {
            for(int j=0; j<10; ++j) {
                cout << ' ' << ((i<m && j<n && board[i][j]==1) ? 'a' : ' ') ;
            }
            cout << '\n';
        }
        cout << "===\n";
    }
}
