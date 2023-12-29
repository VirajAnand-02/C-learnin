#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

char infix[MAX];
char postfix[MAX];
int post_tracker = 0;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1) return '\0'; // Handle stack underflow
    return stack[top--];
}

int isOperator(char x) {
    switch (x) {
        case '^': return 5;
        case '/': return 4;
        case '*': return 4;
        case '+': return 2;
        case '-': return 2;
    }
    return 0;
}

int isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
}

int precedence(char x) {
    switch (x) {
        case '^': return 3;
        case '/': 
        case '*': return 2;
        case '+': 
        case '-': return 1;
    }
    return -1;
}

void infixToPostfix() {
    int str_len = strlen(infix);
    for(int i = 0; i < str_len; i++) {
        char scanned = infix[i];
        if(isOperand(scanned)) {
            postfix[post_tracker++] = scanned;
        } else if(scanned == '(') {
            push(scanned);
        } else if(scanned == ')') {
            while(top != -1 && stack[top] != '(') {
                postfix[post_tracker++] = pop();
            }
            pop(); // Pop the '('
        } else if(isOperator(scanned)) {
            while(top != -1 && precedence(scanned) <= precedence(stack[top])) {
                postfix[post_tracker++] = pop();
            }
            push(scanned);
        }
    }

    while(top != -1) {
        if(stack[top] != '(') postfix[post_tracker++] = pop();
        else pop();
    }
    postfix[post_tracker] = '\0'; // Null terminate the postfix expression
}

int main() {
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin); // Safer alternative to gets
    infix[strcspn(infix, "\n")] = 0; // Remove newline character
    infixToPostfix();
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
