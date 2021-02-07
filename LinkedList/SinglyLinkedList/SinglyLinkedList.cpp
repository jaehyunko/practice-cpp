#include "SinglyLinkedList.h"

namespace jh
{
	SinglyLinkedList::SinglyLinkedList()
		: mHead(nullptr)
		, mSize(0)
	{
	}

	SinglyLinkedList::~SinglyLinkedList()
	{
		SinglyLinkedListNode* node = mHead;

		while (node)
		{
			mHead = node->next;
			delete node;
			node = mHead;
		}
	}

	void SinglyLinkedList::Append(int data)
	{
		SinglyLinkedListNode** it = &mHead;

		while (*it)
		{
			it = &(*it)->next;
		}

		*it = new SinglyLinkedListNode;
		(*it)->data = data;
		(*it)->next = nullptr;

		mSize++;
	}

	void SinglyLinkedList::Remove(int data)
	{
		SinglyLinkedListNode** it = &mHead;

		while (*it && (*it)->data != data)
		{
			it = &(*it)->next;
		}

		if (*it == nullptr)
		{
			return;
		}

		SinglyLinkedListNode* node = *it;

		*it = node->next;

		if (node == mHead)
		{
			mHead = node->next;
		}

		delete node;

		mSize--;
	}

	size_t SinglyLinkedList::Size() const
	{
		return mSize;
	}

	std::vector<int> SinglyLinkedList::ToVector() const
	{
		std::vector<int> res;
		SinglyLinkedListNode* node = mHead;

		res.reserve(mSize);

		while (node)
		{
			res.push_back(node->data);
			node = node->next;
		}

		return res;
	}
}