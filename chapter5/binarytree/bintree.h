#include "bintreenode.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

template<typename T>
class BinTree 
{

public:
		BinTree ()
			:_size (0), _root (nullptr) {}
		~BinTree ()
		{
		
		}
		
		int size () const
		{
			return _size;
		}

		bool isEmpty () const
		{
			return !_root;
		}

		BinTreeNode<T>* root () const
		{
			return _root;
		}

		BinTreeNode<T>* insertAsRoot (const T &e)
		{
			_size = 1;
			_root = new BinTreeNode<T> (e);

			return _root;
		}

		BinTreeNode<T>* insertAsLC (BinTreeNode<T> *n, const T &e)
		{
			++_size;
			n -> insertAsLC (e);	 
			updateHeightAbove (n);

			return n -> lChild;
		}

		BinTreeNode<T>* insertAsRC (BinTreeNode<T> *n, const T &e)
		{
			++_size;
			n -> insertAsRC (e);
			updateHeightAbove (n);

			return n -> rChild;
		}
	
		BinTreeNode<T>* attachAsLC (BinTreeNode<T> *n, BinTree<T> &t)
		{

			auto p = t -> root ();
			n -> lChild = p;
			p -> parent = n;
			_size += t -> size ();

			return p;
		}

		BinTreeNode<T>* attachAsRC (BinTreeNode<T> *n, BinTree<T> &t)
		{
			auto p = t -> root ();
			n -> rChild = p;
			p -> parent = n;
			_size += t -> size ();

			return p;
		}

		int updateHeight (BinTreeNode<T> *n)
		{
			return n -> height = 1 + max (stature (n -> lChild), stature (n -> rChild));	
		}

		void updateHeightAbove (BinTreeNode<T> *n)
		{
			auto p = n;
			while (p)
			{
				updateHeight (p);
				p = p -> parent;
			}
		}




private:
		int _size;
		BinTreeNode<T> *_root;

};
