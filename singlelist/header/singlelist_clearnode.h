#ifndef _SINGLELIST_CLEARALLNODES_H_
#define _SINGLELIST_CLEARALLNODES_H_

template<typename T>
int SingleList<T>::ClearAllNodes()
{
	while(!Empty())
		PopFront();
}

#endif
