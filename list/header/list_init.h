#ifndef _LIST_INIT_H_
#define _LIST_INIT_H_

template <typename T>
void List<T>::Init()
{
	Position(T) header_ = new ListNode<T>;
	Position(T) trailer_ = new ListNode<T>;
	header_ -> succ_ = trailer_;
	header_ -> pred_ = nullptr;
	trailer_ -> pred_ = header_;
	trailer_ -> succ_ = nullptr;

	size_ = 0;
}

#endif
