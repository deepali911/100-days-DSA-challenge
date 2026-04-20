// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push
void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    Node* stack = NULL;

    // INPUT
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int i = 0;
    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit (single digit operand)
        if (isdigit(exp[i])) {
            int num = exp[i] - '0';
            push(&stack, num);
        }
        else {
            // Operator
            int b = pop(&stack);
            int a = pop(&stack);
            int res;

            switch (exp[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(&stack, res);
        }

        i++;
    }

    // OUTPUT
    printf("Result: %d\n", pop(&stack));

    return 0;
}