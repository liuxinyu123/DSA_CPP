#ifndef _SINGLELIST_POP_H_
#define _SINGLELIST_POP_H_

template<typename T>
T SingleList<T>::PopFront()
{
	if(!Empty())
	{
		Position(T) b = Begin();
		T tmp = b -> data_;
		header_ -> succ_ = b -> succ_;
		delete b;
		--size_;

		return tmp;
	}

}

template<typename T>
T SingleList<T>::PopBack()
{
	if(!Empty())
	{
		Position(T) e = End();
		T tmp = e -> data_;
		Position(T) beforeBack = NodeBefore(e);
		beforeBack -> succ_ = e -> succ_;
		delete e;
		--size_;

		return tmp;
	}
}

#endif
