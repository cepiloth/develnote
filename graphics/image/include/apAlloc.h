#pragma once

#include "apAllocator.h"

#if 0
template<typename T, typename A = apAllocator_<T> >
class apAlloc
{
public:
	// Null allocation. Returns pointer to gNull() memory.
	apAlloc();
	explicit apAlloc(unsigned int n, unsigned int align = 0);

	~apAlloc();

	// We return this object for any null allocations
	// It actually allocates 1 byte to make all the member functions valid.
	static apAlloc& gNull();

	unsigned int size() const { return pMem_->size(); }
	unsigned int ref() const { return pMem_->ref(); }

	bool isNull() const { return (pMem_ == gNull().pMem_); }

	// Access the beginning of the memory region.
	T* data() { return *pMem_; }
	const T* data() const { return *pMem_; }

	// Access a specific element. // Throw STL range error if index is invalid
	T& operator[] (unsigned int index);
	const T& operator[] (unsigned int index) const;

	// Define custom copy-constructor and assignment operator
	apAlloc(const apAlloc& src);
	apAlloc& operator= (const apAlloc& src);

	// Duplicate the memory in the underlying apAllocator.
	virtual A* clone();
	// Breaks any referance counting and forces this object to have its own copy.
	void duplicate();

protected:
	A* pMem_;

	// Our null object
	static apAlloc* sNull_;
};

#endif