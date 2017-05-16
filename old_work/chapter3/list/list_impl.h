#ifndef _LIST_IMPL_H_
#define _LIST_IMPL_H_

#include <string>
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
	if (!p)
		throw std::runtime_error ("segment fault");
	auto q = p;
	while (0 < n--)
	{
		if (e == q -> data)
			return q;
		q = q -> prev;
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

template<typename T>
ListNode<T>* List<T>::insertBefore (ListNode<T> *p, const T &e)
{
	if (!p)
		throw std::runtime_error ("segment fault");
	++_size;
	return p -> insertAsPrev (e);
}

template<typename T>
ListNode<T>* List<T>::insertAfter (ListNode<T> *p, const T &e)
{
	if (!p)
		throw std::runtime_error ("segment fault");
	++_size;
	return p -> insertAsSucc (e);
}

template<typename T>
void List<T>::copyNodes (ListNode<T> *p, int n)
{
	init ();
	auto q = p;
	while (0 < n--)
	{
		insertAsLast (q -> data);
		q = q -> succ;
	}
}

template<typename T>
List<T>::List (const List<T> &l)
{
	copyNodes (l.first (), l.size ());
}

template<typename T>
List<T>& List<T>::operator= (const List<T> &l)
{
	if (_header != l.first () -> prev)
	{
		destroy ();
		copyNodes (l.first (), l.size ());
	}

	return *this;
}

template<typename T>
void List<T>::destroy ()
{
	auto p = _header -> succ;
	auto q = p;
	if (p != _trailer)
	{
		q = p -> succ;
		delete p;
		p = q;		
	}

	delete _header;
	delete _trailer;
} 

//template<typename T>
//List<T>::List (const List<T> &l, Rank r, int n)
//{
	//init ();
	//copyNodes (&l[r], n);
//}

template<typename T>
const T& List<T>::operator[] (Rank r) const
{
	check (r, "passed the size");
	ListNode<T> *p = first ();
	while (0 < r--)
		p = p -> succ;

	return p -> data;
}
#endif
