#ifndef _SINGLELIST_COPYNODES_H_
#define _SINGLELIST_COPYNODES_H_

template<typename T>
void SingleList<T>::CopyNodes(Position(T) p,int n)
{
	Init();

	while(n--)
	{
		PushBack(p -> data_);
		p = p -> succ_;
	}
}

#endif
