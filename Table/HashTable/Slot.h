#pragma once

#include "Person.h"

typedef int Key;
typedef Person* Value;

enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot {
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;