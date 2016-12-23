#ifndef _SINGLELIST_PUSH_H_
#define _SINGLELIST_PUSH_H_

template<typename T>
void SingleList<T>::PushFront(const T &elem)
{
	Position(T) front = Front();
	Position(T) p = new ListNode<T>(elem,front);
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

	Position(T) back = Back();
	back -> succ_ = p;
	++size_;
}

#endif
