#include <stdio.h>
int w,h;
int map[55][55];
int count;
void
visit
(int x, int y)
{
    if(map[y][x]) {
        map[y][x]=0;
        visit(x,y-1);
        visit(x,y+1);
        visit(x-1,y);
        visit(x+1,y);
        visit(x-1,y-1);
        visit(x-1,y+1);
        visit(x+1,y-1);
        visit(x+1,y+1);
    }
}

int
main
()
{
    for(;;) {
        scanf("%d %d",&w,&h);
        if(w==0||h==0) {
            break;
        }
        for(int i=1;i<h;i++) {
            for(int j=1;j<w;j++) {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=1;i<h;i++) {
            for(int j=1;j<w;j++) {
                if(map[i][j]) {
                    visit(j,i);
                    count++;
                }
            }
        }
        printf("%d\n",count);
        count=0;
    }
}
