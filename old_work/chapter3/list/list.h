#ifndef _LIST_H_
#define _LIST_H_

#include <string>
#include <stdexcept>
#include "listnode.h"

using Rank = int;

template<typename T>
class List
{

public:
		List ()
		{
			init ();
		}		
		List (const List<T> &l);
		List& operator= (const List<T> &l);
		~List ()
		{
			destroy ();
		}
		T& operator[] (Rank r);
		const T& operator[] (Rank r) const;
		int size () const
		{
			return _size;
		}
		ListNode<T>* first () const
		{
			check (0, "passed the max size");
			return _header -> succ;
		}
		ListNode<T>* last () const
		{
			check (0, "passed the max size");
			return _trailer -> prev;	
		}
		bool isEmpty () const
		{
			return _size == 0;
		}
		ListNode<T>* find (const T &e, ListNode<T>* p, int n) const;
		ListNode<T>* find (const T &e) const;
		ListNode<T>* insertAsFirst (const T &e);
		ListNode<T>* insertAsLast (const T &e);
		ListNode<T>* insertBefore (ListNode<T> *p, const T &e);
		ListNode<T>* insertAfter (ListNode<T> *p, const T &e);
		

private:
		void init ();
		void check (Rank r, const std::string &msg) const;
		void copyNodes (ListNode<T> *p, int n);
		void destroy ();
private:
		int _size;
		ListNode<T> *_header;
		ListNode<T> *_trailer;

};


#include "list_impl.h"
#endif
