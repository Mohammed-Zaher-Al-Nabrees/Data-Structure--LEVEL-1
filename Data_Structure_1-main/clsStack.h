#pragma once
#include "clsQueue.h"
template<typename T> class clsStack : public clsQueue <T>
{
public:
	T Top() {
		return clsQueue<T>::Front();
	}
	T Bottom() {
		return clsQueue<T>::Back();
	}
	void Push(T Value) {
		clsQueue<T>::_MyList.InsertAtFirst(Value);
	}


};
