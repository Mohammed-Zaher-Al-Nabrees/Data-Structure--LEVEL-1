#pragma once
#include<iostream>
using namespace std;
template<typename T>class clsDblLinkedList
{
protected:
	int _Size = 0;
public:
	class Node {
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};
	Node* Head = NULL;
	Node* Find(T Value) {
		Node* Current = Head;
		while (Current != NULL) {
			if (Current->Value == Value)
			{
				return Current;
			}
			Current = Current->Next;
		}
		return NULL;
	}
	void InsertAtFirst(int Value) {
		Node* New_Node = new Node();
		New_Node->Next = Head;
		New_Node->Prev = NULL;
		New_Node->Value = Value;
		if (Head != NULL)
			Head->Prev = New_Node;
		Head = New_Node;
		_Size++;
	}
	void InsertAfter(Node*& PrevNode, int Value) {
		if (PrevNode == NULL) {
			return;
		}
		Node* New_Node = new Node();
		New_Node->Value = Value;
		New_Node->Next = PrevNode->Next;
		if (PrevNode->Next != NULL)
			PrevNode->Next->Prev = New_Node;
		New_Node->Prev = PrevNode;
		PrevNode->Next = New_Node;
		_Size++;
	}
	void InsertAtEnd(int Value) {
		Node* New_Node = new Node();
		New_Node->Value = Value;
		New_Node->Next = NULL;
		if (Head == NULL) {
			New_Node->Prev = NULL;
			Head = New_Node;
		}
		else {
			Node* LastNode = Head;
			while (LastNode->Next != NULL) {
				LastNode = LastNode->Next;
			}
			New_Node->Prev = LastNode;
			LastNode->Next = New_Node;
		}
		_Size++;
	}
	void DeleteNode(Node* ToDelete) {
		if (Head == NULL || ToDelete == NULL) return;
		if (ToDelete == Head)
			Head = ToDelete->Next;
		if (ToDelete->Prev != NULL)
			ToDelete->Prev->Next = ToDelete->Next;
		if (ToDelete->Next != NULL)
			ToDelete->Next->Prev = ToDelete->Prev;
		delete ToDelete;
		_Size--;
	}
	void DeleteFirstNode() {
		if (Head == NULL) return;
		Node* First = Head;
		Head = First->Next;
		if (Head != NULL)
			Head->Prev = NULL;
		delete First;
		_Size--;
	}
	void DeleteLastNode() {
		if (Head == NULL) return;
		if (Head->Next == NULL) {
			delete Head;
			Head = NULL;
			_Size--;
			return;
		}
		Node* Last = Head;
		while (Last->Next != NULL) {
			Last = Last->Next;
		}
		if (Last->Prev != NULL)
			Last->Prev->Next = NULL;
		delete Last;
		_Size--;
	}
	void PrintNodeDetails()
	{

		if (Head->Prev != NULL)
			cout << Head->Prev->Value;
		else
			cout << "NULL";

		cout << " <--> " << Head->Value << " <--> ";

		if (Head->Next != NULL)
			cout << Head->Next->Value << "\n";
		else
			cout << "NULL";

	}
	void PrintListDetails()
	{
		Node* Current = Head;
		cout << "\n\n";
		while (Current != NULL) {
			PrintNodeDetails(Current);
			Current = Current->Next;
		}
	}
	void PrintList() {
		cout << "NULL <--> ";
		Node* Current = Head;
		while (Current != NULL) {
			cout << Current->Value << " <--> ";
			Current = Current->Next;
		}
		cout << " NULL";
	}
	int Size() {
		return _Size;
	}
	bool IsEmpty() {
		return (_Size == 0);
	}
	void Clear() {
		while (_Size != 0)
			DeleteFirstNode();
	}
	void Reverse() {
		if (Head == NULL || Head->Next == NULL) return;

		Node* Temp = nullptr;
		while (true)
		{
			Temp = Head->Next;
			Head->Next = Head->Prev;
			Head->Prev = Temp;
			if (Temp == NULL)
				break;
			Head = Head->Prev;
		}
	}
	Node* GetNode(short Index) {
		if (Index < 0 || Index > _Size - 1 || IsEmpty())
			return NULL;

		Node* Current = Head;
		short Counter = 0, S = _Size - 1;
		while (Counter < _Size / 2) {
			if (Index == Counter || Index == S) {
				return Current;
			}
			Current = Current->Next;
			Counter++;
			S--;
		}
	}
	T GetItem(short Index) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->Value;
	}
	bool UpdateItem(short Index, T NewValue) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL) {
			ItemNode->Value = NewValue;
			return true;
		}
		return false;
	}
	bool InsertAfter(short Index, T NewValue) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL) {
			InsertAfter(ItemNode, NewValue);
			return true;
		}
		return false;
	}
};
