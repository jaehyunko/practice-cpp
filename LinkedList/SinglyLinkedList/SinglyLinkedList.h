#pragma once

#include <vector>

namespace jh
{
	typedef struct Node
	{
		int data;
		struct Node* next;
	} Node_t;

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
		Node_t* mHead;
		size_t mSize;
	};
}
