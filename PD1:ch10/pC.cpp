#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}
void recovery(char *homework) {
    //homework[strlen(homework)-1]='\0';
    char *c = strtok(homework," ");
    char str[MAX_LEN + 1];
    while(c!=NULL){
        int flag=0;
        char tmp[500];
        //printf("%s",c);
        strcpy(tmp,c);
        int leng=strlen(tmp);
        if(leng>21) flag=1;
        else{
             flag=0;
            for(int i=0;i<leng-1;i++){
                if(!((tmp[i]>='a'&&tmp[i]<='z')||(tmp[i]>='A'&&tmp[i]<='Z')))
                    flag=1;
            }
            if(!((tmp[leng-1]>='a'&&tmp[leng-1]<='z')||(tmp[leng-1]>='A'&&tmp[leng-1]<='Z')
            ||tmp[leng-1]==','||tmp[leng-1]=='.'||tmp[leng-1]=='!'||tmp[leng-1]=='?'))
            flag=1;
            if(leng==1&&!((tmp[leng-1]>='a'&&tmp[leng-1]<='z')||(tmp[leng-1]>='A'&&tmp[leng-1]<='Z')))
                flag=1;
        }
        strcat(tmp," ");
        if(flag==0)strcat(str,tmp);
        c=strtok(NULL," ");
    }
    strcpy(homework,str);   
}