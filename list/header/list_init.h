#ifndef _LIST_INIT_H_
#define _LIST_INIT_H_

template <typename T>
void List<T>::Init()
{
	Position(T) h = new ListNode;
	Position(T) t = new ListNode;
	h -> succ_ = t;
	h -> pred_ = nullptr;
	t -> pred_ = h;
	t -> succ_ = nullptr;

	size_ = 0;
}

#endif
