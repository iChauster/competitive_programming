//#include <bits/stdc++.h>
#include "./config/bits/stdc++.h"

using namespace std;

int r; 
int c;
int matrix[21][21];
vector<pair<int,int> > moves;

void solve() {
    
    cin >> r >> c;
    if (r == 2 && c == 2) {
        printf("IMPOSSIBLE\n");
    } else if ((r == 2 || c == 2) && (r == 3 || c == 3)){
        printf("IMPOSSIBLE\n");
    } else if ((r == 2 || c == 2) && (r == 4 || c == 4)){
        printf("IMPOSSIBLE\n");
    } else if (r == 3 && c == 3) {
        printf("IMPOSSIBLE\n");
    } else {
        int found = 0;
        int row;
        int col;
        int totalMoves = 0;
        while (!found) {
            // generate initial position
            totalMoves = 1;
            memset(matrix, 0, sizeof(matrix));
            moves.clear();
            row = rand() % r + 1;
            col = rand() % c + 1;

            matrix[row][col] = 1;
            moves.push_back(make_pair(row,col));
            // generate possible moves that have not been taken
            vector<pair<int, int> > possibleMoves;

            while (totalMoves < r * c) {
                matrix[row][col] = 1;
                for (int i = 1; i <= r; i ++) {
                    for (int j = 1; j <= c; j ++) {
                        if (i != row && j != col && i + j != row + col && i - j != row - col) {
                            if (matrix[i][j] == 0){
                                pair<int,int> move = make_pair(i, j);
                                possibleMoves.push_back(move);
                            }
                        }
                    }
                }
                
                if (possibleMoves.size() > 0) {
                    pair<int, int> choice;
                    if (possibleMoves.size() == 1){
                        choice = possibleMoves[0];
                    }else {
                        choice = possibleMoves[rand() % (possibleMoves.size() - 1)];
                    }
                    row = choice.first;
                    col = choice.second;
                    moves.push_back(make_pair(row,col));
                    possibleMoves.clear();
                    totalMoves += 1;
                } else {
                    possibleMoves.clear();
                    break;
                }
            }
            if (totalMoves == r * c) {
                found = 1;
                printf("POSSIBLE\n");
                for (pair<int, int> coords : moves){
                    printf("%d %d\n", coords.first, coords.second);
                }
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
