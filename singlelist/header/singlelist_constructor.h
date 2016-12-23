#ifndef _SINGLELIST_CONSTRUCTOR_H_
#define _SINGLELIST_CONSTRUCTOR_H_

template<typename T>
SingleList<T>::SingleList()
{
	Init();
}

template<typename T>
SingleList<T>::SingleList(const SingleList &l)
{
}

template<typename T>
SingleList<T>::SingleList(const SingleList &l,Position(T) p,int n)
{
}
#endif

