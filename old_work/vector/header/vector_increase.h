#ifndef _VECTOR_INCREASE_H_
#define _VECTOR_INCREASE_H_

template<typename T>
void Vector<T>::VectorIncrease(Vector<T> &v)
{
	v.Traverse(Increase<T>());
}

#endif
