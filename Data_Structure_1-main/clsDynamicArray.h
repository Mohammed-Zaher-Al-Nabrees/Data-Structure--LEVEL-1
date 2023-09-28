#pragma once
#include "clsQueue.h"
using namespace std;
template<typename T> class clsDynamicArray
{
private:
	int _Size;
public:
	T* DynamicArray;
	T* TempArray;
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		return (_Size == 0);
	}
	clsDynamicArray(int Size=0) {
		if (Size < 0)
			Size = 0;
		_Size = Size;
		DynamicArray = new T[Size];
		TempArray = new T[Size];
	}
	~clsDynamicArray() {
		delete[] DynamicArray;
	}
	bool  SetItem(int Index, T Value) {
		if (Index >= _Size || _Size < 0)
			return false;
		DynamicArray[Index] = Value;
		return true;
	}
	T GetItem(int Index) {
		return DynamicArray[Index];
	}
	void Print() {
		if (_Size == 0) {
			cout << "[]\n";
			return;
		}
		cout << "[";
		for (short i = 0; i < _Size;i++) {
			cout << DynamicArray[i];
			if (i == _Size - 1)
				cout << "]\n";
			else
				cout << ",";
		}
	}
	void Resize(int NewSize) {
		if (NewSize < 0)
			NewSize = 0;

		TempArray = new T[NewSize];
		if (NewSize < _Size)
			_Size = NewSize;

		for (short i = 0; i < _Size;i++)
			TempArray[i] = DynamicArray[i];

		delete[]  DynamicArray;
		DynamicArray = TempArray;
		_Size = NewSize;
	}
	void Reverse() {
		T* TempArray = new T[_Size];

		for (short i = (_Size - 1); i >= 0;i--)
			TempArray[i] = DynamicArray[(_Size - 1) - i];

		delete[]DynamicArray;
		DynamicArray = TempArray;
	}
	void Clear() {
		_Size = 0;
		delete[]DynamicArray;
		DynamicArray = new T[0];
	}
	int Find(T Value) {
		for (short index = 0; index < _Size;index++)
		{
			if (DynamicArray[index] == Value)
				return index;
		}
		return -1;//Not Found
	}

	bool DeleteItemAt(int Index) {
		if (Index > _Size - 1 || Index < 0) return false;

		_Size--;
		TempArray = new T[_Size];
		for (short i = 0; i < Index;i++)
		{
			TempArray[i] = DynamicArray[i];
		}
		for (short i = Index + 1; i < _Size + 1;i++)
		{
			TempArray[i - 1] = DynamicArray[i];
		}
		delete[] DynamicArray;
		DynamicArray = TempArray;
		return true;
	}
	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}
	bool DeleteLastItem() {
		return DeleteItemAt(_Size - 1);
	}
	bool DeleteItem(T Value) {
		int Index = Find(Value);
		if (Index < 0)return false;
		return DeleteItemAt(Index);
	}

	bool InsertAt(int Index, T Value) {
		if (Index > _Size || Index < 0) return false;

		_Size++;
		TempArray = new T[_Size];
		for (short i = 0; i < Index;i++)
		{
			TempArray[i] = DynamicArray[i];
		}
		TempArray[Index] = Value;
		for (short i = Index + 1; i < _Size + 1;i++)
		{
			TempArray[i] = DynamicArray[i - 1];
		}
		delete[] DynamicArray;
		DynamicArray = TempArray;
		return true;
	}
	bool InsertAtFirst(T Value) {
		return InsertAt(0, Value);
	}
	bool InsertAtEnd(T Value) {
		return InsertAt(_Size, Value);
	}
	bool InsertAfter(int Index, T Value) {
		if (Index >= _Size)
			return InsertAt(_Size, Value);
		else
			return InsertAt(Index, Value);
	}
	bool InsertBefore(int Index, T Value) {
		if (Index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(Index - 1, Value);
	}
};