#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}


void check_sudoku(int (*grid_p)[NUM]){
    int sudoku[9][9]={0};
    for(int i=0;i<9;i++){
        int checker[10]={0};
        for(int j=0;j<9;j++){
            checker[grid_p[i][j]]++;
        }
        for(int j=0;j<9;j++){
            if(checker[grid_p[i][j]]>1){
                sudoku[i][j]=1;
            }   
        }
    }
    for(int i=0;i<9;i++){
        int checker[10]={0};
        for(int j=0;j<9;j++){
            checker[grid_p[j][i]]++;
        }
        for(int j=0;j<9;j++){
            if(checker[grid_p[j][i]]>1)
                sudoku[j][i]=1;
        }
    }
    for(int o=0;o<9;o+=3){
        for(int k=0;k<9;k+=3){
            int checker[10]={0};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    checker[grid_p[i+o][j+k]]++;
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(checker[grid_p[i+o][j+k]]>1){
                        sudoku[i+o][j+k]=1;
                    }   
                }
            }
           
        }
        
    }
        
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j])
                printf("(%d,%d)\n",i,j);
                
        }
    }
}