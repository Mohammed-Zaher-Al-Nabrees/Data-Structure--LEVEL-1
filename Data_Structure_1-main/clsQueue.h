#pragma once
#include "clsDblLinkedList.h"
template<typename T> class clsQueue 
{
protected:
	clsDblLinkedList <T> _MyList;
public:
	T Front() {
		return _MyList.GetItem(0);
	}
	T Back() {
		return _MyList.GetItem(_MyList.Size()-1);
	}
	T GetItem(short Index) {
		return _MyList.GetItem(Index);
	}
	bool UpdateItem(short Index, T NewValue) {
		return _MyList.UpdateItem(Index,NewValue);
	}
	bool InsertAfter(short Index, T NewValue) {
		return _MyList.InsertAfter(Index,NewValue);
	}
	void Push(T Value) {
		_MyList.InsertAtEnd(Value);
	}
	void Pop() {
		_MyList.DeleteFirstNode();
	}
	void Reverse() {
		_MyList.Reverse();
	}
	void InsertAtFront(int Value) {
		_MyList.InsertAtFirst(Value);
	}
	void InsertAtBack(int Value) {
		_MyList.InsertAtEnd(Value);
	}
	void Clear() {
		_MyList.Clear();
	}
	void Print() {
		_MyList.PrintList();
	}
};
