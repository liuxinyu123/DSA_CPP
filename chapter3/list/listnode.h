#ifndef _LISTNODE_H_
#define _LISTNODE_H_

template<typename T>
struct ListNode
{
	T data;
	ListNode<T> *prev;
	ListNode<T> *succ;

	ListNode<T> () = default;
	ListNode<T> (const T &d, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr)
		:data (d), prev (p), succ (s) {}
	ListNode<T>* insertAsPrev (const T &d);
	ListNode<T>* insertAsSucc (const T &d);
};

template<typename T>
ListNode<T>* ListNode<T>::insertAsPrev (const T &d)
{
	ListNode<T> *p = new ListNode<T> (d, prev, this);
	prev -> succ = p;
	prev = p;

	return p;
}

template<typename T>
ListNode<T>* ListNode<T>::insertAsSucc (const T &d)
{
	ListNode<T> *p = new ListNode<T> (d, this, succ);
	succ -> prev = p;
	succ = p;

	return p;
}


#endif

