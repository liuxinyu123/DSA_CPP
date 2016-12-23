#ifndef _LIST_INSERTASLAST_H_
#define _LIST_INSERTASLAST_H_

template<typename T>
Position(T) List<T>::InsertAsLast(const T &elem)
{	
	++size_;
	return trailer_ -> InsertAsPred(elem);
}

#endif
