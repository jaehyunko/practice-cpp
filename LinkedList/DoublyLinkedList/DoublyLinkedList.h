#pragma once

#include <cassert>

namespace jh
{
	template <typename T>
	struct DoublyLinkedListNode
	{
		T data;
		DoublyLinkedListNode<T>* prev;
		DoublyLinkedListNode<T>* next;
	};

	template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList<T>& other);
		~DoublyLinkedList();

		DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);

		void AddFirst(T data);
		void AddLast(T data);
		T GetFirst(void) const;
		T GetLast(void) const;
		void RemoveFirst(void);
		void RemoveLast(void);
		size_t Size(void) const;
		bool Empty(void) const;
	private:
		DoublyLinkedListNode<T>* mHead;
		DoublyLinkedListNode<T>* mTail;
		size_t mSize;
	};

	template <typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mHead(nullptr)
		, mTail(nullptr)
		, mSize(0u)
	{
	}

	template <typename T>
	DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
		: mHead(nullptr)
		, mTail(nullptr)
		, mSize(other.mSize)
	{
		if (other.mHead == nullptr)
		{
			return;
		}

		mHead = new DoublyLinkedListNode<T>{ other.mHead->data, nullptr, nullptr };

		DoublyLinkedListNode<T>** nodePtr = &mHead->next;
		DoublyLinkedListNode<T>* prev = mHead;
		DoublyLinkedListNode<T>* otherNode = other.mHead->next;

		while (otherNode)
		{
			*nodePtr = new DoublyLinkedListNode<T>{ otherNode->data, prev, nullptr };

			prev->next = *nodePtr;
			prev = *nodePtr;

			nodePtr = &(*nodePtr)->next;
			otherNode = otherNode->next;
		}

		mTail = prev;
	}

	template <typename T>
	DoublyLinkedList<T>::~DoublyLinkedList()
	{
		DoublyLinkedListNode<T>* node = mHead;

		while (node)
		{
			DoublyLinkedListNode<T>* tmp = node;
			node = node->next;
			delete tmp;
		}
	}

	template <typename T>
	DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		DoublyLinkedListNode<T>* node = mHead;

		while (node)
		{
			DoublyLinkedListNode<T>* tmp = node;
			node = node->next;
			delete tmp;
		}

		mSize = rhs.mSize;

		if (rhs.mHead == nullptr)
		{
			mHead = nullptr;
			mTail = nullptr;

			return *this;
		}

		mHead = new DoublyLinkedListNode<T>{ rhs.mHead->data, nullptr, nullptr };

		DoublyLinkedListNode<T>** nodePtr = &mHead->next;
		DoublyLinkedListNode<T>* prev = mHead;
		DoublyLinkedListNode<T>* rhsNode = rhs.mHead->next;

		while (rhsNode)
		{
			*nodePtr = new DoublyLinkedListNode<T>{ rhsNode->data, prev, nullptr };

			prev->next = *nodePtr;
			prev = *nodePtr;

			nodePtr = &(*nodePtr)->next;
			rhsNode = rhsNode->next;
		}

		mTail = prev;

		return *this;
	}

	template <typename T>
	void DoublyLinkedList<T>::AddFirst(T data)
	{
		DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>{ data, nullptr, mHead };

		if (mHead)
		{
			mHead->prev = newNode;
		}
		else
		{
			mTail = newNode;
		}

		mHead = newNode;

		++mSize;
	}

	template <typename T>
	void DoublyLinkedList<T>::AddLast(T data)
	{
		DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>{ data, mTail, nullptr };

		if (mTail)
		{
			mTail->next = newNode;
		}
		else
		{
			mHead = newNode;
		}

		mTail = newNode;

		++mSize;
	}

	template <typename T>
	T DoublyLinkedList<T>::GetFirst(void) const
	{
		assert(mHead);

		return mHead->data;
	}

	template <typename T>
	T DoublyLinkedList<T>::GetLast(void) const
	{
		assert(mTail);

		return mTail->data;
	}

	template <typename T>
	void DoublyLinkedList<T>::RemoveFirst(void)
	{
		DoublyLinkedListNode<T>* node = mHead;

		if (mHead)
		{
			mHead = mHead->next;
		}

		if (mHead)
		{
			mHead->prev = nullptr;
		}
		else
		{
			mTail = nullptr;

		}

		delete node;

		--mSize;
	}

	template <typename T>
	void DoublyLinkedList<T>::RemoveLast(void)
	{
		DoublyLinkedListNode<T>* node = mTail;

		if (mTail)
		{
			mTail = mTail->prev;
		}

		if (mTail)
		{
			mTail->next = nullptr;
		}
		else
		{
			mHead = nullptr;
		}

		delete node;

		--mSize;
	}

	template <typename T>
	size_t DoublyLinkedList<T>::Size(void) const
	{
		return mSize;
	}

	template <typename T>
	bool DoublyLinkedList<T>::Empty(void) const
	{
		return (mSize == 0u);
	}
}
