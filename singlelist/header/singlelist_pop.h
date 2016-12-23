#ifndef _SINGLELIST_POP_H_
#define _SINGLELIST_POP_H_

template<typename T>
T SingleList<T>::PopFront()
{
	if(!Empty())
	{
		Position(T) front = Front();
		T tmp = front -> data_;
		header_ -> succ_ = front -> succ_;
		delete front;
		--size_;

		return tmp;
	}

}

template<typename T>
T SingleList<T>::PopBack()
{
	if(!Empty())
	{
		Position(T) back = Back();
		T tmp = back -> data_;
		Position(T) beforeBack = NodeBefore(back);
		beforeBack -> succ_ = back -> succ_;
		delete back;
		--size_;

		return tmp;
	}
}

#endif
