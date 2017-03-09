#ifndef _LIST_IMPL_H_
#define _LIST_IMPL_H_

#include <stdexcept>

template<typename T>
void List<T>::init ()
{
	_header = new ListNode<T> ();
	_trailer = new ListNode<T> ();

	_header -> prev = nullptr;
	_header -> succ = _trailer;

	_trailer -> prev = _header;
	_trailer -> succ = nullptr;
	
	_size = 0;
}

template<typename T>
T& List<T>::operator[] (Rank r)
{
	check (r, "passed the size");
	ListNode<T> *p = first ();
	while (0 < r--)
		p = p -> succ;

	return p -> data;
}

template<typename T>
void List<T>::check (Rank r, const std::string &msg) const
{
	if (r >= _size)
		throw std::out_of_range (msg);	
}

template<typename T>
ListNode<T>* List<T>::find (const T &e, ListNode<T> *p, int n) const
{
	auto q = p;
	while (!q && n--)
	{
		q = q -> prev;
		if (e == q -> data)
			return q;		
	}

	return nullptr;
}

template<typename T>
ListNode<T>* List<T>::find (const T &e) const
{
	return find (e, _trailer, _size);
}

template<typename T>
ListNode<T>* List<T>::insertAsFirst (const T &e)
{
	++_size;
	return _header -> insertAsSucc (e);
}

template<typename T>
ListNode<T>* List<T>::insertAsLast (const T &e)
{
	++_size;
	return _trailer -> insertAsPrev (e);
}

#endif
