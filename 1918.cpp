#include <stdio.h>
#define MAX 100

typedef struct stack {
    char s[MAX];
    int top;
} Stack;    

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX-1;
}

void push(Stack *s, char data)
{
    s->s[++(s->top)] = data;
}

char peek(Stack *s)
{
    return s->s[s->top];
}

void pop(Stack *s)
{
    (s->top)--;
}

int getPriority(char op)
{
    switch(op) {
        case '*': case '/': return 10;
        case '+': case '-': return 1;
    }
    return 0;
}

void infixToPostfix(char *t)
{
    Stack s;
    init(&s);

    for(int i=0; t[i]; i++) {
        char ch = t[i];
        if('A' <= ch && ch <= 'Z') printf("%c", ch);
        else {
            if(ch == '(') push(&s, ch);
            else if(ch == ')') {
                char op = peek(&s);
                while(op != '(') {
                    printf("%c", op);
                    pop(&s);
                    op = peek(&s);
                }
                pop(&s);
            }
            else {
                int curP = getPriority(ch);
                while(curP <= getPriority(peek(&s))) {
                    printf("%c", peek(&s)); 
                    pop(&s);
                }
                push(&s, ch);
            }
        }
    }
    while(!isEmpty(&s)) {
        printf("%c", peek(&s));
        pop(&s);
    }
}

int main()
{
    char s[100];
    scanf("%s", s);
    infixToPostfix(s);
    puts("");
    return 0;
}
