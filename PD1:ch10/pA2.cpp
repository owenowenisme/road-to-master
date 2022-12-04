#include<stdio.h>
#include<string.h>

int main() {
    int dis, hp, valid=0,counter=0;
    char str[50000];
    char cmd[3][50000] = {"PATA PATA PATA PON", "PON PON PATA PON", "CHAKA CHAKA PATA PON"};
    scanf("%d %d", &dis, &hp);
    getchar();
    fgets(str, 50000, stdin);
    
    char tmp[500];
    int now=0,prev=0;
    int leng=strlen(str);
    for(int i=0;i<leng;i++){
        if(str[i]==','||str[i]=='.'||str[i]=='\n'){
            now=i;
            strncpy(tmp,str+prev,now-prev);
            
            tmp[now-prev]='\0';
            //printf("%d %d\n",strlen(tmp),now-prev);
            prev=now+1;

            int flag=0;
            counter++;
            if(strcmp(tmp,cmd[0])==0){
                dis--;
                valid++;
            }
            else if(strcmp(tmp,cmd[1])==0){
                if(dis<=3) 
                    hp--;
                valid++;
            }
            else if(strcmp(tmp,cmd[2])==0){
            dis++;
            valid++; 
            flag=1;
            }
            if((counter%10==0&&flag==0)||dis==0||hp<=0){
                break;
            }
        }
        
        
       
    }
    
    if(hp>0)
        printf("NO %d",hp);
    else
        printf("YES %d",valid);
}