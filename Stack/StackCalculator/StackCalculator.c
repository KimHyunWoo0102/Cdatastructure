#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "InfixToPostfix.h"
#include "StackCalculator.h"
#include "../LinkedStack/ListStack.h"

int calculate(char exp[])
{
    Stack stack;
    StackInit(&stack);
    int len;
    ConvToRPNExp(exp);
    
    len = strlen(exp);

    for (int i = 0; i < len; i++) {
        char tok = exp[i];
        
        if (isdigit(tok))
            SPush(&stack, tok - '0');
        else {
            int op2 = SPop(&stack);
            int op1 = SPop(&stack);
            switch (tok)
            {
            case '*':
                SPush(&stack, op1 * op2);
                break;
            case '/':
                SPush(&stack, op1 / op2);
                break;
            case '+':
                SPush(&stack, op1 + op2);
                break;
            case '-':
                SPush(&stack, op1 - op2);
                break;
            }
        }
    }

    return SPop(&stack);
}
