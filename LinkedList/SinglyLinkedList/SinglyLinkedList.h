#pragma once

#include <vector>

namespace jh
{
	template <typename T>
	struct SinglyLinkedListNode
	{
		T data;
		struct SinglyLinkedListNode<T>* next;
	};

	template <typename T>
	class SinglyLinkedList
	{
	public:
		SinglyLinkedList();
		~SinglyLinkedList();

		void Append(T data);
		void Remove(T data);
		size_t Size() const;
		std::vector<T> ToVector() const;
	private:
		SinglyLinkedListNode<T>* mHead;
		size_t mSize;
	};

	template <typename T>
	SinglyLinkedList<T>::SinglyLinkedList()
		: mHead(nullptr)
		, mSize(0)
	{
	}

	template <typename T>
	SinglyLinkedList<T>::~SinglyLinkedList()
	{
		SinglyLinkedListNode<T>* node = mHead;

		while (node)
		{
			mHead = node->next;
			delete node;
			node = mHead;
		}
	}

	template <typename T>
	void SinglyLinkedList<T>::Append(T data)
	{
		SinglyLinkedListNode<T>** it = &mHead;

		while (*it)
		{
			it = &(*it)->next;
		}

		*it = new SinglyLinkedListNode<T>;
		(*it)->data = data;
		(*it)->next = nullptr;

		mSize++;
	}

	template <typename T>
	void SinglyLinkedList<T>::Remove(T data)
	{
		SinglyLinkedListNode<T>** it = &mHead;

		while (*it && (*it)->data != data)
		{
			it = &(*it)->next;
		}

		if (*it == nullptr)
		{
			return;
		}

		SinglyLinkedListNode<T>* node = *it;

		*it = node->next;

		if (node == mHead)
		{
			mHead = node->next;
		}

		delete node;

		mSize--;
	}

	template <typename T>
	size_t SinglyLinkedList<T>::Size() const
	{
		return mSize;
	}

	template <typename T>
	std::vector<T> SinglyLinkedList<T>::ToVector() const
	{
		std::vector<T> res;
		SinglyLinkedListNode<T>* node = mHead;

		res.reserve(mSize);

		while (node)
		{
			res.push_back(node->data);
			node = node->next;
		}

		return res;
	}
}
