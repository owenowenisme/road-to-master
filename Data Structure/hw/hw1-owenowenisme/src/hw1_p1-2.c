#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    char data[1000];
    struct node* prev ;
};
typedef struct node node;
bool isempty(node* top){
    return (top == NULL)?true:false;
}
node* create_stack(){
    node* top = NULL;
    return top;
}
node* pop(node* top){
    node* tmp = top;
    top = top->prev;
    free(tmp);
    return top;
}
node* push(node* top, char* data){
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->prev = top;
    top = new_node;
    return top;
}
node* merge(node* top,char opt){
    char tmp[1000] ={'\0'};
    tmp[0]=opt;
    strcat(tmp,top->prev->data);
    strcat(tmp,top->data);
    top = pop(top);
    top = pop(top);
    top = push(top, tmp);
    return top;
}


int main() {
    char input[1000];
    scanf("%s",input);
    char now[2];
    now[1] = '\0';
    node* top = create_stack();
    for(int i=0;i<strlen(input);i++){
        now[0] = input[i];
        if(input[i] == '+'||input[i] == '-'||input[i] == '*'||input[i] == '/'){
            top = merge(top, now[0]);
        }else{
            top = push(top, now);
        }
    }
    printf("%s",top->data);
    return 0;
}
