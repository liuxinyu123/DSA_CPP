#ifndef _VECTOR_TRAVERSE_H_
#define _VECTOR_TRAVERSE_H_

template<typename T> template<typename VST>
void Vector<T>::Traverse(VST &visit)
{
	for(int i = 0; i < size_; ++i)
		visit(array_[i]);
}

#endif
