#ifndef _LISTNODE_INSERTASPRED_H_
#define _LISTNODE_INSERTASPRED_H_

template<typename T>
Position(T) ListNode<T>::InsertAsPred(const T &elem)
{
	Position(T) p = new ListNode(elem,pred_,this);
	pred_ -> succ_ = p;
	pred_ = p;

	return p;	
}

#endif
