#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 200000

int N;
char str[MAX_LEN];

void find_orz(int orz_position[], int *orz_num);
void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position);
int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position);

int main()
{
    scanf("%d", &N);
    scanf("%s", str);

    int orz_position[MAX_LEN] = {0}, worship_amount[MAX_LEN] = {0}, orz_num = 0;
    find_orz(orz_position, &orz_num);

    for (int i = 1; i < orz_num; i++)
    {
        calculate_worship(worship_amount, i - 1, orz_position[i - 1], orz_position[i]);
    }   
    // for(int i=0;i<orz_num;i++){
    //     printf("%d ",worship_amount[i]);
    // }
    //printf("\n");
    int max_worship, range_L, range_R;
    for (int i = 0; i < orz_num - 1; i++)
    {
        max_worship = find_max_worship_range(worship_amount[i], &range_L, &range_R, orz_position[i], orz_position[i + 1]);
    }
   printf("%d %d %d\n", max_worship, range_L, range_R);
}
void find_orz(int orz_position[], int *orz_num){
    for(int i=0;i<=N-3;i++){
        if(str[i]=='o'&&str[i+1]=='r'&&str[i+2]=='z'){
            orz_position[*orz_num]=i;
            (*orz_num)++;
        }
    }
}

void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position){
    int letter[26]={0};
    int kind=0,cnt=0;
    for(int i=left_orz_position+3;i<right_orz_position;i++){
        if(letter[str[i]-97]==0){
            kind++;
            letter[str[i]-97]=1;
        }
        cnt++;
    }
    worship_amount[range_index]=cnt*kind;
}

int max=0;
int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position){
    if(value>max){
        //printf("%d %d\n",max,value);
        max=value;
        *range_L=left_orz_position+1;
        *range_R=right_orz_position+1;
        return max;
    }
    return max;
}
