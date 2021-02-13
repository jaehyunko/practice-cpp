#include <cassert>
#include "DoublyLinkedlist.h"

void TestDoublyLinkedList()
{
	jh::DoublyLinkedList<int>* list = new jh::DoublyLinkedList<int>();

	list->AddFirst(5);

	assert(!list->Empty());
	assert(list->Size() == 1);
	assert(list->GetFirst() == 5);
	assert(list->GetLast() == 5);

	list->AddFirst(3);

	assert(!list->Empty());
	assert(list->Size() == 2);
	assert(list->GetFirst() == 3);
	assert(list->GetLast() == 5);

	list->AddLast(6);

	assert(!list->Empty());
	assert(list->Size() == 3);
	assert(list->GetFirst() == 3);
	assert(list->GetLast() == 6);

	list->RemoveFirst();

	assert(!list->Empty());
	assert(list->Size() == 2);
	assert(list->GetFirst() == 5);
	assert(list->GetLast() == 6);

	list->RemoveLast();

	assert(!list->Empty());
	assert(list->Size() == 1);
	assert(list->GetFirst() == 5);
	assert(list->GetLast() == 5);

	list->RemoveLast();

	assert(list->Empty());
	assert(list->Size() == 0);

	list->AddFirst(1);

	assert(!list->Empty());
	assert(list->Size() == 1);
	assert(list->GetFirst() == 1);
	assert(list->GetLast() == 1);

	list->RemoveLast();

	assert(list->Empty());
	assert(list->Size() == 0);

	list->AddLast(9);

	assert(!list->Empty());
	assert(list->Size() == 1);
	assert(list->GetFirst() == 9);
	assert(list->GetLast() == 9);

	list->RemoveFirst();

	assert(list->Empty());
	assert(list->Size() == 0);

	// check mem leak 
	list->AddLast(1);
	list->AddLast(2);
	list->AddLast(3);

	delete list;
}

void TestDoublyLinkedListCopyConstructor()
{
	jh::DoublyLinkedList<int>* list1 = new jh::DoublyLinkedList<int>();

	list1->AddLast(1);
	list1->AddLast(2);

	assert(list1->GetFirst() == 1);
	assert(list1->GetLast() == 2);

	jh::DoublyLinkedList<int>* list2 = new jh::DoublyLinkedList<int>(*list1);

	assert(list2->GetFirst() == 1);
	assert(list2->GetLast() == 2);

	delete list1;
	delete list2;
}

void TestDoublyLinkedListAssignOperator()
{
	jh::DoublyLinkedList<int>* list1 = new jh::DoublyLinkedList<int>();

	list1->AddLast(1);
	list1->AddLast(2);
	list1->AddLast(3);

	jh::DoublyLinkedList<int>* list2 = new jh::DoublyLinkedList<int>();

	// check mem leak
	list2->AddLast(4);
	list2->AddLast(5);
	list2->AddLast(6);

	*list2 = *list1;

	delete list1;
	delete list2;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TestDoublyLinkedList();
	TestDoublyLinkedListCopyConstructor();
	TestDoublyLinkedListAssignOperator();

	return 0;
}