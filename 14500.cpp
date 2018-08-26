#include <cstdio>
#include <vector>
#include <array>
using std::vector;
using std::array;
int size[2],max;
int table[4][2] ={{0,-1},{1,0},{0,1},{-1,0}};
vector<vector<int>> map;
vector<vector<int>> visited;

int
isnotout(int x, int y) {
    return x>=0&&x<size[0]&&y>=0&&y<size[1];
}

void
dfs(int x, int y, int depth, int sum) {
    if(depth==4) {
        max=max>sum?max:sum;
        return;
    }
    for(int i=0;i<4;i++) {
        int nx=x+table[i][0],ny=y+table[i][1];
        if(isnotout(nx,ny)&&!visited[ny][nx]) {
            visited[ny][nx]=true;
            dfs(nx,ny,depth+1,sum+map[ny][nx]);
            visited[ny][nx]=false;
        }

    }
}

void
tblock(int x, int y) {
    int sum=map[y][x],min=999999999,cnt=0;
    for(int i=0;i<4;i++) {
        int nx=x+table[i][0],ny=y+table[i][1];
        if(isnotout(nx,ny)) {
            sum+=map[ny][nx];
            min=min<map[ny][nx]?min:map[ny][nx];
            cnt++;
        }
    }
    if(cnt==4) {
        sum-=min;
    }
    max=max>sum?max:sum;
}

int
main() {
    scanf("%d%d",&size[1],&size[0]);
    for(int i=0;i<size[1];i++) {
        map.push_back({});
        visited.push_back({});
        for(int j=0;j<size[0];j++) {
            int t;
            scanf("%d",&t);
            map[i].push_back(t);
            visited[i].push_back(0);
        }
    }
    for(int i=0;i<size[1];i++) {
        for(int j=0;j<size[0];j++) {
            dfs(j,i,0,0);
            tblock(j,i);
        }
    }
    printf("%d\n",max);
}
