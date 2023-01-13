#include<stdio.h>
int map[20][20]={0},ans=0;
int path[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
void dfs(int x,int y){
    if(map[x][y]==2)ans++;
    map[x][y]=1;
    for(int i=0;i<4;i++){
        int tmpx=x+path[i][0],tmpy=y+path[i][1];
        if(tmpx<5&&tmpy<5&&tmpx>=0&&tmpy>=0&&map[tmpx][tmpy]!=1){
            dfs(tmpx,tmpy);
        }
    }
    return ;
}
int main () {
    int x,y;scanf("%d %d",&x,&y);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            scanf("%d",&map[i][j]);
    }
    dfs(x,y);
    printf("%d",ans);
    return 0;
}
