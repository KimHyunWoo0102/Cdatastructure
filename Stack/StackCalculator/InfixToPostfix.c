#include "InfixToPostfix.h"
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
#include "../LinkedStack/ListStack.h"

int GetOpPrec(char op)
{
    switch (op) {
    case '*':
    case '/':
        return 5;

    case '+':
    case '-':
        return 3;

    case '(':
        return 1;
    }
    return -1;
}

int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[])
{
    Stack stack;
    int len = strlen(exp), idx = 0;
    char* retExp = (char*)malloc(len + 1);

    memset(retExp, 0, sizeof(retExp));

    for (int i = 0; i < len; i++) {
        char tok = exp[i];
        
        if (isdigit(tok)) {
            retExp[idx] = tok;
            idx++;
        }
        else {
            switch (tok)
            {
            case '(':
                SPush(&stack, tok);
                break;
            case ')':
                while (1) {
                    char popOp = SPop(&stack);
                    if (popOp == '(')
                        break;

                    retExp[idx] = popOp;
                    idx++;
                }
            case '+':case'-':
            case'*':case'/':
                while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                {
                    retExp[idx] = SPop(&stack);
                    idx++;
                }
                SPush(&stack, tok);
                break;
            }
        }
    }

    while (!SIsEmpty(&stack)) {
        retExp[idx] = SPop(&stack);
        idx++;
    }

    strcpy(exp, retExp);
    free(retExp);
}
