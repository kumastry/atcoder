#include<stdio.h>
#include<stdlib.h>

typedef struct element {
    int value;
    struct element *next;
} element_type;

int main() {
    element_type *cur_p, *root, *pre_p, *p, *temp;
    int i, number, val;
    root = NULL;

    printf("リストの要素数>");
    scanf("%d", &number);
    while(1) {
        cur_p = (element_type*)malloc(sizeof(element_type));
        if(i == 1) {
            root = cur_p;
        } else {
            pre_p->next = cur_p;
        }
        printf("要素値を入力>");
        scanf("%d", &cur_p->value);
        cur_p->next = NULL;
        pre_p = cur_p;
    }

    p = root;
    while(p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    puts("");

    cur_p = (element_type*)malloc(sizeof(element_type));
    printf("挿入する要素の値>");
    scanf("%d", &cur_p->value);

    printf("どの値の後に挿入するか>");
    scanf("%d", &val);

    p = root;
    while(p != NULL) {
        if(p->value == val) {
            temp = p->next;
            p->next = cur_p;
            cur_p->next = temp;
            break;
        }

        p = p->next;
    }


    while (root != NULL) {
        p = root;
        root = p->next;
        printf("%d ", p->value);
        free(p);
    }

    return 0;
    
}