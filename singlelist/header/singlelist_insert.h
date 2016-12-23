#ifndef _SINGLELIST_INSERT_H_
#define _SINGLELIST_INSERT_H_

template<typename T>
Position(T) SingleList<T>::InsertAfter(Position(T) p,const T &elem)
{
	Position(T) q = new ListNode<T>(elem,p -> succ_);
	p -> succ_ = q;
	++size_;

	return q;
}

template<typename T>
Position(T) SingleList<T>::InsertBefore(Position(T) p,const T &elem)
{
	Position(T) q = new ListNode<T>(elem,p);
	Position(T) beforeP = NodeBefore(p);
	beforeP -> succ_ = q;
	++size_;

	return q;		
}

#endif
