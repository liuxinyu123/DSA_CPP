#ifndef _SINGLELIST_INIT_H_
#define _SINGLELIST_INIT_H_

template<typename T>
void SingleList<T>::Init()
{
	header_ = new ListNode<T>;
	header_ -> succ_ = nullptr;	
}

#endif
