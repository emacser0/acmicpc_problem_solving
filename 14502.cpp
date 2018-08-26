#include <cstdio>
#include <vector>
#define pb push_back
typedef std::vector<std::vector<int>> vec;
vec map,tmap,virusp,emptyp;
int ys,xs,t,max,cnt;
int table[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
void
virus(int x, int y) {
    if(tmap[y][x]==0) {
        tmap[y][x]=2;
        for(int i=0;i<4;i++) {
            int nx=x+table[i][0],ny=y+table[i][1];
            if(nx+1 and nx<xs and ny+1 and ny<ys) {
                virus(x+table[i][0],y+table[i][1]);
            }
        }
    }
}
void wall(int cur,vec wallp) {
    if(cur<emptyp.size()) {
        wall(cur+1,wallp);
        wallp.pb(emptyp[cur]);
        if(wallp.size()<3) {
            wall(cur+1,wallp);
        }
        else {
            tmap=map;
            for(auto i : wallp) {
                tmap[i[1]][i[0]]=1;
            }
            for(auto i : virusp) {
                virus(i[0],i[1]);
            }
            for(int i=0;i<ys;i++) {
                for(int j=0;j<xs;j++) {
                    if(tmap[i][j]==0) {
                        cnt++;
                    }
                }
            }
            max=max>cnt?max:cnt;
            cnt=0;
        }
    }
}
int
main() {
    scanf("%d%d",&ys,&xs);
    for(int i=0;i<ys;i++) {
        map.pb({});
        for(int j=0;j<xs;j++) {
            scanf("%d",&t);
            if(t==0) {
                emptyp.pb({j,i});
            }
            else if(t==2) {
                virusp.pb({j,i});
                t=0;
            }
            map[i].pb(t);
        }
    }
    wall(0,{});
    printf("%d\n",max);
}
