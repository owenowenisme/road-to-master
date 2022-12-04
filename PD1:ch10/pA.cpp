#include<stdio.h>
#include<string.h>

int main() {
    int dis, hp, valid=0,counter=0;
    char str[50000];
    char cmd[3][50000] = {"PATA PATA PATA PON", "PON PON PATA PON", "CHAKA CHAKA PATA PON"};
    scanf("%d %d", &dis, &hp);
    getchar();
    fgets(str, 50000, stdin);
    //printf("%s",str);
    char d[] = "\,\.";
    //str[strlen(str)]='\0';
    str[strlen(str)-1]='\0';
    char *c = strtok(str, d);
    int checker=0;
    while (c != NULL) {
        int flag=0;
        counter++;
        if(strcmp(c,cmd[0])==0){
            dis--;
            valid++;
        }
        else if(strcmp(c,cmd[1])==0){
            if(dis<=3) 
                hp--;
            valid++;
        }
        else if(strcmp(c,cmd[2])==0){
         dis++;
         valid++; 
         flag=1;
        }
        if(counter%10==0&&flag==0){
            break;
        }
        c = strtok(NULL, d);
    }
    if(hp>0)
        printf("NO %d",hp);
    else
        printf("YES %d",valid);
}