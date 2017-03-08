#ifndef _LIST_H_
#define _LIST_H_

#include <string>
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
		T& operator[] (Rank r);
		int size () const
		{
			return _size;
		}


private:
		void init ();
		void check (Rank r, const std::string &msg) const;
private:
		int _size;
		ListNode<T> *_header;
		ListNode<T> *_trailer;

};


#include "list_impl.h"
#endif
