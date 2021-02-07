#pragma once

#include <vector>

namespace jh
{
	typedef struct SinglyLinkedListNode
	{
		int data;
		struct SinglyLinkedListNode* next;
	} SinglyLinkedListNode;

	class SinglyLinkedList
	{
	public:
		SinglyLinkedList();
		~SinglyLinkedList();

		void Append(int data);
		void Remove(int data);
		size_t Size() const;
		std::vector<int> ToVector() const;
	private:
		SinglyLinkedListNode* mHead;
		size_t mSize;
	};
}
