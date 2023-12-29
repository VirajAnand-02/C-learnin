#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

char infix[MAX];
char postfix[MAX];
int post_tracker = 0;

void push(char x){
	stack[++top] = x;
}
char pop(){
	return stack[top--];
}
char top_element(){
	return stack[top];
}

int operator(char x){
	switch (x){
	case '^':
		return 5;
		break;
	case '/':
		return 3;
		break;
	case '*':
		return 4;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 1;
		break;
	default:
		break;
	}
	return 0;
}

int operand(char x){
	if(x == '*'|| x=='/'||x=='+'||x=='-'||x=='('||x==')'){
		return 0;
	}
	return 1;
}

void infixToPostfix(){
	int str_len = strlen(infix);
	for(int i=0;i<str_len;i++){
		char scaned = infix[i];
		if(scaned == '('){
			push(scaned);
		}
		else if(scaned == ')'){
			while (top_element() != '('){
				postfix[post_tracker++] = pop();
			}
		}
		else if(operand(scaned)){
			postfix[post_tracker++] = scaned;
		}
		else if(operator(scaned)){
			if(operator(scaned) >= operator(top_element())){
				push(scaned);
			} else {
				while(operator(scaned) < operator(top_element())){
					postfix[post_tracker++] = pop();
				}
				push(scaned);
			}
		}
		printf("| Scanned: %c | stack: %s | postfix: %s\n", scaned, stack, postfix);
	}
	while (top != -1){
		if(top_element() != '(') postfix[post_tracker++] = pop();
		else pop();
	}
}

int main(){
	printf("Enter infix expression : ");
	gets(infix);
	infixToPostfix();
	printf("%s", postfix);	
return 0;
}