#ifndef _SINGLELIST_DESTRUCTOR_H_
#define _SINGLELIST_DESTRUCTOR_H_

template<typename T>
SingleList<T>::~SingleList()
{
	ClearAllNodes();
	delete header_;
}

#endif
