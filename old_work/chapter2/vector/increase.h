#ifndef _INCREASE_H_
#define _INCREASE_H_

template<typename T>
class Increase
{
public:
		void operator () (T &e) 
		{
			++e;
		}
};

#endif
