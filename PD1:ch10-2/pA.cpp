#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}
char chart[][8] = {"0",   "0",   "abc",  "def", "ghi",
                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
void convert(char *arr[], int count) {
    char str[10000];
    for (int i = 0; i < count; i++) {
        char s[1000];
        strcpy(s, arr[i]);
        strcpy(str, "");
        for (int q = 0; q < strlen(s); q++) {
            char c = s[q];
            if (c == ' ')
                strcat(str, " ");
            else if (c == '\n')
                strcat(str, "\n");
            else {
                char tmp[9];
                for (int j = 2; j <= 9; j++) {
                    for (int o = 0; o < strlen(chart[j]); o++) {
                        if (chart[j][o] == c) {
                            tmp[0] = '(';
                            tmp[1] = j + 48;
                            tmp[2] = ')';
                            tmp[3] = o + 49;
                            strcat(str, tmp);
                        }
                    }
                }
            }
        }
        strcpy(arr[i], str);
    }
}