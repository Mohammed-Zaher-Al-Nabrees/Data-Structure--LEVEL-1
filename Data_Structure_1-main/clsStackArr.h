#pragma once
#include "clsQueueArr.h"
template<typename T> class clsStackArr : public clsQueueArr <T>
{
public:
	T Top() {
		return clsQueueArr<T>::Front();
	}
	T Bottom() {
		return clsQueueArr<T>::Back();
	}
	void Push(T Value) {
		clsQueueArr<T>::MyQueue.InsertAtFirst(Value);
	}


};