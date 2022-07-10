#pragma once
#include <cstring>
#include <stdio.h>

void IntQueueTest();

class IntQueue {
private:
	int* _queue;
	int _size;
	int _head, _tail;

	void reLocate();
	void upSizing();

public:
	IntQueue();
	~IntQueue();

	void clear();
	int size();
	int max();
	bool isEmpty();
	bool isFull();
	void push(int obj);

	void pop();
	int top();
	void printObj();
	void printStatus();
};