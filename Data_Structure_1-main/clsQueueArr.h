#pragma once
#include "clsDynamicArray.h"
template<typename T> class clsQueueArr
{
protected:
	clsDynamicArray <T> MyQueue;
public:
	T Front() {
		return MyQueue.GetItem(0);
	}
	T Back() {
		return MyQueue.GetItem(MyQueue.Size() - 1);
	}
	T GetItem(short Index) {
		return MyQueue.GetItem(Index);
	}
	int Size() {
		return MyQueue.Size();
	}
	bool UpdateItem(short Index, T NewValue) {
		return MyQueue.UpdateItem(Index, NewValue);
	}
	bool InsertAfter(short Index, T NewValue) {
		return MyQueue.InsertAfter(Index, NewValue);
	}
	void Push(T Value) {
		MyQueue.InsertAtEnd(Value);
	}
	void Pop() {
		MyQueue.DeleteFirstNode();
	}
	void Reverse() {
		MyQueue.Reverse();
	}
	void InsertAtFront(T Value) {
		MyQueue.InsertAtFirst(Value);
	}
	void InsertAtBack(T Value) {
		MyQueue.InsertAtEnd(Value);
	}
	void Clear() {
		MyQueue.Clear();
	}
	void Print() {
		MyQueue.Print();
	}
};