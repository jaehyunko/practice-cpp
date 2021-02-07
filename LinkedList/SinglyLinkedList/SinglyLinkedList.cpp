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
		Node_t* node = mHead;

		while (node)
		{
			mHead = node->next;
			delete node;
			node = mHead;
		}
	}

	void SinglyLinkedList::Append(int data)
	{
		Node_t** it = &mHead;

		while (*it)
		{
			it = &(*it)->next;
		}

		*it = new Node_t;
		(*it)->data = data;
		(*it)->next = nullptr;

		mSize++;
	}

	void SinglyLinkedList::Remove(int data)
	{
		Node_t** it = &mHead;

		while (*it && (*it)->data != data)
		{
			it = &(*it)->next;
		}

		if (*it == nullptr)
		{
			return;
		}

		Node_t* node = *it;

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
		Node_t* node = mHead;

		res.reserve(mSize);

		while (node)
		{
			res.push_back(node->data);
			node = node->next;
		}

		return res;
	}
}