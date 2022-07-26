#pragma once
#include <cstring>
#include <stdio.h>

void IntStackTest();

class IntStack {
private :
	int* _stack;
	int _max;
	int _head;

	void upSizing();

public:
	IntStack();
	~IntStack();

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