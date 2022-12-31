#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}
void recovering_order(char *order, char **result) {
    char const *s=":";
    char *token=strtok(order,":");
    
    *result=malloc(sizeof(char)*10000);
    while(token!=NULL){
        int idx=99999;int ans=0;
        for(int i=0;i<GOODS_SIZE;i++){
            char *tmp=strstr(names[i],token);
            if(strstr(names[i],token)!=NULL){
                if(tmp-names[i]==idx){
                    if(strlen(names[i])==strlen(names[ans])){
                        if(strcmp(names[i],names[ans])<0)
                            ans=i;
                    }
                    else if(strlen(names[i])<strlen(names[ans])){
                        ans=i;
                    }
                }
                else if(tmp-names[i]<idx){
                    ans=i;
                    idx=tmp-names[i];
                }
            }
        }
        strcat(*result,names[ans]);
        strcat(*result,"+");
        token=strtok(NULL,":");
    }
    (*result)[strlen(*result)-1]='\0';
    return;
}
