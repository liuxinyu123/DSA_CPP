#ifndef _BINTREENODE_H_
#define _BINTREENODE_H_

template<typename T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *parent;
	BinTreeNode<T> *lChild;
	BinTreeNode<T> *rChild;
	int height;
	
	BinTreeNode ()
		:parent (nullptr), lChild (nullptr), rChild (nullptr), height (0) {}
	BinTreeNode (T d, BinTreeNode<T> *p = nullptr, BinTreeNode<T> *lc = nullptr, BinTreeNode<T> *rc = nullptr,
			   int h = 0)
		:data (d), parent (p), lChild (lc), rChild (rc), height (h) {}
	int size () const;//返回当前节点后代总数
	BinTreeNode<T>* insertAsLC (const T &e);
	BinTreeNode<T>* insertAsRC (const T &e);
	BinTreeNode<T>* succ () const;//取当前节点的直接后继

	bool operator< (const BinTreeNode<T> &btn) const
	{
		return data < btn.data;
	}

	bool operator> (const BinTreeNode<T> &btn) const
	{
		return data > btn.data;
	}

	bool operator== (const BinTreeNode<T> &btn) const
	{
		return data == btn.data;
	}	

	bool operator!= (const BinTreeNode<T> &btn) const
	{
		return !(*this == btn);
	}


};
#endif
