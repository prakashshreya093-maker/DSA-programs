#include <stdio.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[50];
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {

        // If operand → push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');   // convert char to int
        }
        else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
