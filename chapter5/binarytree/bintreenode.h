#ifndef _BINTREENODE_H_
#define _BINTREENODE_H_

#define stature(p) ((p) ? (p) -> height : -1)

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
	BinTreeNode<T>* insertAsLC (const T &e)
	{
		return lChild = new BinTreeNode<T> (e, this);
	}
	BinTreeNode<T>* insertAsRC (const T &e)
	{
		return rChild = new BinTreeNode<T> (e, this);
	}
	BinTreeNode<T>* succ () const //取当前节点的直接后继
	{
		
	}
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

	bool isRoot () const
	{
		return !parent;
	}

	bool isLChild () const
	{
		return *this == parent -> lChild;
	}

	bool isRChild () const
	{
		return *this == parent -> rChild;
	}

	bool hasParent () const
	{
		return parent;
	}

	bool hasLChild () const
	{
		return lChild;
	}

	bool hasRChild () const
	{
		return rChild;
	}

	bool hasChild () const
	{
		return (lChild || rChild);
	}

	bool hasBothChild () const
	{
		return (lChild && rChild);
	}

	bool isLeaf () const
	{
		return !hasChild ();
	}
	
	BinTreeNode<T>* sibling () const
	{
		return isLChild () ? parent -> rChild : parent -> lChild;
	}

	BinTreeNode<T>* uncle () const
	{
		return (parent -> isLChild ()) ? parent -> parent -> rChild : parent -> parent -> lChild;
	}
	
};

#endif
