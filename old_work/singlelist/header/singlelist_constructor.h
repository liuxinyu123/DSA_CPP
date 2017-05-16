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
	CopyNodes(l.Begin(),l.Size());
}

template<typename T>
SingleList<T>::SingleList(Position(T) p,int n)
{
	CopyNodes(p,n);
}

#endif

