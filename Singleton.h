#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <stdlib.h>
#include <new>

template<class T>
class Singleton
{
public:
	Singleton(){}
	virtual ~Singleton(){}

	static inline T& Instance() { return *InstancePtr();}
	static inline T* InstancePtr()
	{
		if(!m_ptr)
		{
			m_ptr = (T*)::malloc(sizeof(T));
			if(m_ptr)
			{
				new (m_ptr)T();
			}
		}
		return m_ptr;
	}
	static inline void SetInstance( T* pObj)
	{
		m_ptr = pObj;
	}
private:
	static T* m_ptr;
};

template<class T> T* Singleton<T>::m_ptr = NULL;

#endif