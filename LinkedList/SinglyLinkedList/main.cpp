#include <cassert>
#include "SinglyLinkedlist.h"

void test1()
{
	jh::SinglyLinkedList<int>* list = new jh::SinglyLinkedList<int>();

	assert(list->Size() == 0);

	list->Append(5);
	assert(list->Size() == 1);
	assert(list->ToVector()[0] == 5);

	list->Append(3);
	assert(list->Size() == 2);
	assert(list->ToVector()[0] == 5);
	assert(list->ToVector()[1] == 3);

	list->Append(1);
	list->Remove(3);
	assert(list->Size() == 2);
	assert(list->ToVector()[0] == 5);
	assert(list->ToVector()[1] == 1);

	list->Remove(5);
	assert(list->Size() == 1);
	assert(list->ToVector()[0] == 1);

	list->Remove(9);
	assert(list->Size() == 1);
	assert(list->ToVector()[0] == 1);

	list->Remove(1);
	assert(list->Size() == 0);
	assert(list->ToVector().size() == 0);

	for (int i = 0; i < 5; ++i)
	{
		list->Append(i);
		assert(list->Size() == (i + 1));
	}

	for (int i = 0; i < 5; ++i)
	{
		list->Remove(i);
		assert(list->Size() == (5 - i - 1));
	}

	list->Append(0);
	list->Append(1);

	delete list;
}

void test_copy_constructor()
{
	jh::SinglyLinkedList<int>* list1 = new jh::SinglyLinkedList<int>();

	list1->Append(1);
	list1->Append(2);

	jh::SinglyLinkedList<int>* list2 = new jh::SinglyLinkedList<int>(*list1);

	delete list1;
	delete list2;
}

void test_assign_operator()
{
	jh::SinglyLinkedList<int>* list1 = new jh::SinglyLinkedList<int>();

	list1->Append(1);
	list1->Append(2);
	list1->Append(3);

	jh::SinglyLinkedList<int>* list2 = new jh::SinglyLinkedList<int>();

	list2->Append(4);
	list2->Append(5);
	list2->Append(6);

	list2->Remove(5);

	*list2 = *list1;

	delete list1;
	delete list2;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	test1();
	test_copy_constructor();	
	test_assign_operator();

	return 0;
}
