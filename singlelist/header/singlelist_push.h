#ifndef _SINGLELIST_PUSH_H_
#define _SINGLELIST_PUSH_H_

template<typename T>
void SingleList<T>::PushFront(const T &elem)
{
	if(Empty())
	{
		Position(T) p = new ListNode<T>(elem,nullptr);
		header_ -> succ_ = p;
		++size_;
		return;
	}

	Position(T) b = Begin();
	Position(T) p = new ListNode<T>(elem,b);
	header_ -> succ_ = p;
	++size_;
}
		
template<typename T>
void SingleList<T>::PushBack(const T &elem)
{
	Position(T) p = new ListNode<T>(elem,nullptr);
	if(Empty())
	{
		header_ -> succ_ = p;
		++size_;
		return;
	}

	Position(T) e = End();
	e -> succ_ = p;
	++size_;
}

#endif
