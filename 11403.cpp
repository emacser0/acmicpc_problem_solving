#include <iostream>
#include <array>
#include <tuple>
using std::cin;
using std::cout;
using std::array;
array<array<int,100>,100> matrix;
array<array<int,100>,100> visited;
array<array<int,100>,100> result;
int n;
void
dfs(int top, int a, int b) {
    visited[a][b]=1;
    result[top][b]=1;
    for(int i=0;i<n;i++) {
        if(matrix[b][i]&&!visited[b][i]) {
            dfs(top,b,i);
        }
    }
}
int
main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(matrix[i][j]&&!visited[i][j]) {
                dfs(i,i,j);
            }
        }
        visited={};
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}
