#include "Node.h"
#include<stdlib.h>
#include<stdio.h>

Node* makeNode(Element e, Group g)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->e = e;
    newNode->g = g;
    newNode->nextElement = NULL;
    newNode->nextGroup = NULL;
    return newNode;
}
