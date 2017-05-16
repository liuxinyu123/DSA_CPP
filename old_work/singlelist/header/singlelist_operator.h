#ifndef _SINGLELIST_OPERATOR_H_
#define _SINGLELIST_OPERATOR_H_

template<typename T>
T SingleList<T>::operator[](Rank r) const
{
	if(r < size_)
	{
		Position(T) p = Begin();
		while(r--)
			p = p -> succ_;

		return p -> data_;
	}
}

template<typename T>
SingleList<T>& SingleList<T>::operator= (const SingleList &l)
{
	CopyList(l);
	
	return *this;
}

#endif
