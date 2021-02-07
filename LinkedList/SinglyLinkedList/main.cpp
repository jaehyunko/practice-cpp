#include <cassert>>
#include "SinglyLinkedList.h"

int main()
{
	jh::SinglyLinkedList list;

	assert(list.Size() == 0);

	list.Append(5);
	assert(list.Size() == 1);
	assert(list.ToVector()[0] == 5);

	list.Append(3);
	assert(list.Size() == 2);
	assert(list.ToVector()[0] == 5);
	assert(list.ToVector()[1] == 3);

	list.Append(1);
	list.Remove(3);
	assert(list.Size() == 2);
	assert(list.ToVector()[0] == 5);
	assert(list.ToVector()[1] == 1);

	list.Remove(5);
	assert(list.Size() == 1);
	assert(list.ToVector()[0] == 1);

	list.Remove(9);
	assert(list.Size() == 1);
	assert(list.ToVector()[0] == 1);

	list.Remove(1);
	assert(list.Size() == 0);
	assert(list.ToVector().size() == 0);

	for (int i = 0; i < 5; ++i)
	{
		list.Append(i);
		assert(list.Size() == (i + 1));
	}

	for (int i = 0; i < 5; ++i)
	{
		list.Remove(i);
		assert(list.Size() == (5 - i - 1));
	}

	return 0;
}
