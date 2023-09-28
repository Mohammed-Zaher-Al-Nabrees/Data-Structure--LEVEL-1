#include <iostream>

using namespace std;

class Node {
public:
	int Value;
	Node* Next;
};
void InsertAtFirst(Node*& Head, int Value) {
	Node* New_Node = new Node();
	New_Node->Next = Head;
	New_Node->Value = Value;
	Head = New_Node;
}
void InsertAfter(Node*& PrevNode, int Value) {
	Node* New_Node = new Node();
	New_Node->Value = Value;
	New_Node->Next = PrevNode->Next;
	PrevNode->Next = New_Node;
}
Node* Find(Node* Head, int Value) {
	while (Head != NULL) {
		if (Head->Value == Value)
			return Head;
		Head = Head->Next;
	}
	return NULL;
}
void PrintList(Node* Head) {
	while (Head != NULL) {
		cout << Head->Value << endl;
		Head = Head->Next;
	}
}

void InsertAtEnd(Node*& Head, int Value) {
	Node* New_Node = new Node();
	New_Node->Value = Value;
	New_Node->Next = NULL;

	Node* LastNode = Head;
	while (LastNode->Next != NULL) {
		LastNode = LastNode->Next;
	}
	LastNode->Next = New_Node;
}
void DeleteNode(Node*& Head, int Value) {
	if (Head == NULL)
		return;

	Node* Prev_Node = Head;
	Node* Current = Head;

	if (Current->Value == Value) {
		if (Current->Next != NULL)
			Head = Head->Next;
		delete Current;
		return;
	}

	while (Current->Next != NULL && Current->Value != Value) {
		Prev_Node = Current;
		Current = Current->Next;
	}
	if (Current == NULL)return;

	Prev_Node->Next = Current->Next;
	delete Current;
}
void DeleteFirstNode(Node*& Head) {
	if (Head == NULL)
		return;

	Node* Current = Head;
	Head = Head->Next;
	delete Current;
}
void DeleteLastNode(Node*& Head) {
	if (Head == NULL)
		return;

	Node* Current = Head;
	Node* Prev = Head;

	if (Current->Next == NULL) {
		Head = NULL;
		delete Current;//free from memory
		return;
	}
	while (Current->Next != NULL && Current != NULL) {
		Prev = Current;
		Current = Current->Next;
	}
	Prev->Next = NULL;
	delete Current;
}
int   main() {
	Node* Head = NULL;
	InsertAtFirst(Head, 100);
	InsertAtFirst(Head, 300);
	InsertAtFirst(Head, 400);
	InsertAtFirst(Head, 500);
	InsertAtFirst(Head, 600);

	PrintList(Head);
	Node* N1 = Find(Head, 300);
	if (N1 != NULL)
		cout << "\n It is Found : " << N1->Value << endl << endl;
	else
		cout << "\n Node is not found \n\n";

	cout << "New Item ::::\n";
	InsertAfter(N1, 200);
	PrintList(Head);

	DeleteNode(Head, 100);
	cout << "__________________________________________\n\n";
	PrintList(Head);

	DeleteNode(Head, 200);
	cout << "__________________________________________\n\n";
	PrintList(Head);

	system("pause>0");
	return 0;
};
