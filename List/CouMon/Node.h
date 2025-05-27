#pragma once

typedef int Element;
typedef char Group;

typedef struct _node {
	Element e;
	Group g;

	struct _node *nextElement;
	struct _node* nextGroup;
}Node;

Node* makeNode(Element e, Group g);