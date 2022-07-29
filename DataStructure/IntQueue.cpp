#include "IntQueue.h"

const int INIT_SIZE = 1<<6;
const int ERROR = -99999999;
void IntQueueTest() {
	IntQueue int_queue;

	printf("PUSH TEST :\n");
	for (int i = 0; i < 10; i++) {
		printf("push into queue %d\n", i);
		int_queue.push(i);
		int_queue.printObj();
		printf("\n");
	}

	printf("\nPOP TEST :\n");
	int t;
	for (int i = 0; i < 10; i++) {
		t = int_queue.top();
		int_queue.pop();
		printf("top : %d\n", t);
		int_queue.printObj();
		printf("\n");
	}
	
	printf("\nreLocate Test :\n");
	for (int i = 10; i < 64; i++) {
		int_queue.push(i);
		int_queue.pop();
	}
	int_queue.printStatus();
	printf("\npush into queue 0\n");
	int_queue.push(0);
	int_queue.printStatus();
	int_queue.printObj();

	printf("\nupSizing TEST :\n");
	for (int i = 1; i < 64; i++) {
		int_queue.push(i);
	}
	int_queue.printStatus();
	printf("\npush into queue 64\n");
	int_queue.push(64);
	int_queue.printStatus();
	int_queue.printObj();
}

IntQueue::IntQueue() {
	_max = INIT_SIZE;
	_head = _tail = 0;
	_queue = new (std::nothrow) int[_max];

	if (_queue == nullptr) {
		printf("Fail to new in initialize queue");
	}
}

IntQueue::~IntQueue() {
	delete[] _queue;
}

void IntQueue::reLocate() {
	memcpy(_queue, _queue + _tail, sizeof(int) * (_head - _tail));
	_head = _head - _tail;
	_tail = 0;
}

void IntQueue::upSizing() {
	_max <<= 1;
	int* tmp = new (std::nothrow) int[_max];
	if (tmp == nullptr) {
		printf("Fail to new in upSizing(IntQueue Class)");
	}
	memcpy(tmp, _queue + _tail, sizeof(int) * (_head - _tail));
	delete[] _queue;
	_queue = tmp;
}

void IntQueue::clear() {
	_head = _tail = 0;
}

int IntQueue::size() {
	return (_head - _tail);
}

int IntQueue::max() {
	return _max;
}

bool IntQueue::isEmpty() {
	return (_head == _tail);
}

bool IntQueue::isFull() {
	return (_head == _max);
}

void IntQueue::push(int obj) {
	if (isFull() == true) {
		if (size() << 1 >= max()) upSizing();
		else reLocate();
	}
	_queue[_head] = obj;
	_head++;
}

void IntQueue::pop() {
	if (isEmpty() == true) {
		printf("Queue is empty");
		return;
	}
	_tail++;
}

int IntQueue::top() {
	if (isEmpty() == true) {
		printf("Queue is empty");
		return ERROR;
	}
	return _queue[_tail];
}

void IntQueue::printObj() {
	printf("Objects in Queue :\n");
	for (int i = _tail; i < _head; i++) {
		printf("%d ", _queue[i]);
	}
	printf("\n");
}

void IntQueue::printStatus() {
	printf("_head : %d\n", _head);
	printf("_tail : %d\n", _tail);
	printf("_max : %d\n", _max);
}