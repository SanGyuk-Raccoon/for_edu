#include "IntStack.h"

const int INIT_SIZE = 1<<6;
const int ERROR = -9999999;

void IntStackTest() {
	IntStack int_stack;

	printf("PUSH TEST :\n");
	for (int i = 0; i < 10; i++) {
		printf("push into stack %d\n", i);
		int_stack.push(i);
		int_stack.printObj();
		printf("\n");
	}

	printf("\nPOP TEST :\n");
	int t;
	for (int i = 0; i < 10; i++) {
		t = int_stack.top();
		int_stack.pop();
		printf("top : %d\n", t);
		int_stack.printObj();
		printf("\n");
	}

	printf("\nreLocate Test :\n");
	for (int i = 10; i < 64; i++) {
		int_stack.push(i);
		int_stack.pop();
	}
	int_stack.printStatus();
	printf("\npush into stack 0\n");
	int_stack.push(0);
	int_stack.printStatus();
	int_stack.printObj();

	printf("\nupSizing TEST :\n");
	for (int i = 1; i < 64; i++) {
		int_stack.push(i);
	}
	int_stack.printStatus();
	printf("\npush into stack 64\n");
	int_stack.push(64);
	int_stack.printStatus();
	int_stack.printObj();
}

IntStack::IntStack() {
	_head = 0;
	_max = INIT_SIZE;
	_stack = new (std::nothrow) int[_max]();
	if (_stack == nullptr) {
		printf("Fail to new in initialize queue");
	}
}

IntStack::~IntStack() {
	delete[] _stack;
}

void IntStack::upSizing() {
	_max <<= 1;
	int *tmp = new (std::nothrow) int[_max];
	if (tmp == nullptr) {
		printf("Fail to new in upSizing(IntStack Class)");
	}
	memcpy(tmp, _stack, sizeof(int) * _head);
	delete[] _stack;
	_stack = tmp;
}
void IntStack::clear() {
	_head = 0;
}

int IntStack::size() {
	return _head;
}
int IntStack::max() {
	return _max;
}
bool IntStack::isEmpty() {
	return _head == 0;
}
bool IntStack::isFull() {
	return _head == _max;
}
void IntStack::push(int obj) {
	if (isFull() == true) {
		upSizing();
	}
	_stack[_head] = obj;
	_head++;
}
void IntStack::pop() {
	if (isEmpty() == true) {
		printf("Stack is empty");
		return;
	}
	_head--;
}
int IntStack::top() {
	if (isEmpty() == true) {
		printf("Stack is empty");
		return ERROR;
	}
	return _stack[_head - 1];
}

void IntStack:: printObj() {
	printf("Objects in Stack :\n");
	for (int i = 0; i < _head; i++) {
		printf("%d ", _stack[i]);
	}
	printf("\n");
}
void IntStack::printStatus() {
	printf("_head : %d\n", _head);
	printf("_max : %d\n", _max);
}