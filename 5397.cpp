#include <stdio.h>
#include <stdlib.h>

char str[1000001];

typedef struct node {
    char data;
    struct node *llink, *rlink;
} Node;

typedef struct list {
    Node *head, *cur;
} List;

void init(List *plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->llink = NULL;
    plist->head->rlink = NULL;
    plist->cur = plist->head;
}

void moveLeft(List *plist)
{
    if(plist->cur == plist->head) return;
    plist->cur = plist->cur->llink;
}

void moveRight(List *plist)
{
    if(plist->cur->rlink == NULL) return ;
    plist->cur = plist->cur->rlink;
}

void backSpace(List *plist)
{
    Node *tmp = plist->cur;
    if(plist->cur == plist->head) return;
  
    plist->cur->llink->rlink = plist->cur->rlink;
    if(plist->cur->rlink) 
        plist->cur->rlink->llink = plist->cur->llink;
    plist->cur = plist->cur->llink;
    free(tmp);
}

void addPasswd(List *plist, char pw)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = pw;
    newNode->llink = newNode->rlink = NULL;

    if(plist->cur->rlink) plist->cur->rlink->llink = newNode;
    newNode->rlink = plist->cur->rlink;
    newNode->llink = plist->cur;
    plist->cur->rlink = newNode;
    plist->cur = newNode;
}

void display(List *plist)
{
    Node *cur = plist->head->rlink;
    while(cur) {
        printf("%c", cur->data);
        cur = cur->rlink;
    }
    puts(""); 
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        List list;
        init(&list);
        scanf("%s", str);
        
        for(int i=0; str[i]; i++) {
            switch(str[i]) {
                case '<': moveLeft(&list); break;
                case '>': moveRight(&list); break;
                case '-': backSpace(&list); break;
                default: addPasswd(&list, str[i]);
            }
        }
        display(&list);
    }

    return 0;
}
