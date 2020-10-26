#include "apAllocator.h"
#if 0
template<typename T>
void apAllocator_<T>::allocate()
{
	if (size_ == 0)
	{
		// Eliminate possibility of null pointer by allocating one item.		
		pRaw_ = 0;
		pData_ = new T[1];
		return;
	}

	if (align_ < 2)
	{
		// Let the compiler worry about alignment
		pRaw_ = 0;
		pData_ = new T[size_];
	}
	else
	{
		pRaw_ = new char[sizeof(T) * size_ + (align_ - 1)];
		pData_ = alignPointer(pRaw_);
	}
}

template<typename T>
void apAllocator_<T>::deallocate()
{
	if (pRaw_)
	{
		delete[] pRaw_;
	}
	else
	{
		delete[] pData_;
	}
	pRaw_ = 0;
	pData_ = 0;
}
#endif