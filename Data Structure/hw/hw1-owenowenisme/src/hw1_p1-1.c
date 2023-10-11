#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    char data;
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
node* push(node* top, char data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = top;
    top = new_node;
    return top;
}




int main(int argc, char* argv[]) {
    node* top = create_stack();
    char input[1000];
    scanf("%s", input);
    for(int i=0;i<strlen(input);i++){
        if(input[i] == '('||input[i] == ')'||input[i] == '+'||input[i] == '-'||input[i] == '*'||input[i] == '/'){
            if (isempty(top)){
                top = push(top, input[i]);
                continue;
            }
            if(input[i]=='('){
                top = push(top, input[i]);
            }else if(input[i]==')'){
                while(!isempty(top)&&top->data != '('){
                    printf("%c",top->data);
                    top = pop(top);
                }
                top = pop(top);
            }else if(input[i]=='+'||input[i]=='-'){
                while(!isempty(top)&&top->data != '('){
                    printf("%c",top->data);
                    top = pop(top);
                }
                top = push(top, input[i]);
            }else{
                if(top->data == '*'||top->data == '/'){
                    printf("%c",top->data);
                    top = pop(top);
                }
                top = push(top, input[i]);
            }
        }else{
            printf("%c",input[i]);
        }
    }
    while(!isempty(top)){
        printf("%c",top->data);
        top = pop(top);
    }
}
