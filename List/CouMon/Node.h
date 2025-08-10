#pragma once

typedef int Element;
typedef char Group;

typedef struct _nodeStack {
	Element e;
	Group g;

	struct _nodeStack *nextElement;
	struct _nodeStack* nextGroup;
}Node;

Node* makeNode(Element e, Group g);