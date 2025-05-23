#include "ArrayList.h"

int main() {
	for (int i = 0; i < MAX_SIZE; i++) {
		Add(0, i);
	}

	PrintList();

	Add(0, 100);
}