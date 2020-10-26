
#include "apAlloc.h"

#if 0
template<typename T, typename A>
apAlloc<T, A>& apAlloc<T, A>::gNull()
{
	if (!sNull_)
	{
		sNull_ = new apAlloc(0);
	}
	return sNull_;
}

template<typename T, typename A>
apAlloc<T, A>::apAlloc() : pMem_(0)
{
	// pMem_ = gNull().pMem_;
	// pMem_->addRef();
	*this = gNull();
}

template<typename T, typename A>
apAlloc<T, A>::apAlloc(unsigned int size, unsigned int align = 0) : pMem_(0)
{
	pMem_ = new A(size, align);
}
template<typename T, typename A>
apAlloc<T, A>::~apAlloc()
{
	pMem_->subRef();
}
template<typename T, typename A>
apAlloc<T, A>::apAlloc(const apAlloc& src)
{
	pMem_ = src.pMem_;
	pMem_->addRef();
}

template<typename T, typename A>
apAlloc<T, A>& apAlloc<T, A>::operator= (const apAlloc<T, A>& src)
{
	// Make sure we don't copy yourself.
	if (pMem_ == src.pMem_) { return *this; }

	pMem_->subRef();
	pMem_ = src.pMem_;
	pMem_->addRef();

	return *this;
}

template<typename T, typename A>
T& apAlloc<T, A>::operator[] (unsigned int index)
{
	if (index > size())
		throw std::range_error("Index out of range");

	return *(data() + index);
}

template<typename T, typename A>
const T& apAlloc<T, A>::operator[] (unsigned int index) const
{
	if (index > size())
		throw std::range_error("Index out of range");

	return *(data() + index);
}

template<typename T, typename A>
void apAlloc<T, A>::duplicate()
{
	if (ref() == 1) { return; }
	A* copy = clone();
	pMem_.subRef();
	pMem_ = copy;
}

template<typename T, typename A>
A* apAlloc<T, A>::clone()
{
	A* copy = new A(pMem_->size(), pMem_->align());

	// Shallow copy
	T* src = *pMem_;
	T* dst = *copy;
	std::copy(src, &(src[pMem_->size()]), dst);
	return copy;
}

#endif