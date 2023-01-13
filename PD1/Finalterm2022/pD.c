#include <stdio.h>
#include <stdlib.h>

char *strtok(char *s, const char *sep) {
  printf("strtok banned\n");
  exit(1);
}
char *strtok_r(char *str, const char *sep, char **lasts) {
  printf("strtok_r banned\n");
  exit(1);
}

char *strsep(char **stringp, const char *delim) {
  printf("strsep banned\n");
  exit(1);
}
char *gettoken(char *str, const char *sep);
int main() {
  char buffer[4096];
  char *sep = " \t\n;,.?!";
  char *word;
  int N;
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    fgets(buffer, 4095, stdin);
    for (word = gettoken(buffer, sep); word != NULL;
         word = gettoken(NULL, sep)) {
      printf("%s\n", word);
    }
  }
}

char *head,*strr,*tmp;
char *gettoken(char *str, const char *sep) {
  if (str != NULL) {
    tmp = str;
    head = str;
    strr = str;
    for (tmp = head; tmp != NULL; tmp++) {
    for (int i = 0; i < 8; i++) {
        if (*tmp == sep[i]) {
            *tmp = '\0';
            head = tmp;
            head++;
            return str;
        }
    }
    }
  }
  int flag=0;
    

  head = tmp;
  head++;
  tmp++;
  //printf("OOO%cOOO\n",*head);
  
  if (*head == '\0') return NULL;
  while(1){int flag=0;
    for (int i = 0; i < 8; i++) {
        if (*tmp == sep[i]) {
            tmp++;
            head++;
            flag=1;
        }
    }
    if(flag==0)break;
  }
  if (*head == '\0') return NULL;
  for (; tmp != NULL; tmp++) {
    for (int i = 0; i < 8; i++) {
    if (*tmp == sep[i]) {
        *tmp = '\0';
        return head;
    }
    }
  }
  return head;
}