#pragma once

#include <iostream>

template <typename T>
class apAllocatorBase_
{
public:
	apAllocatorBase_(unsigned int n, unsigned int align) : size_(0), ref_(0), align_(0), pRaw_(0), pData_(0)
	{}

	virtual ~apAllocatorBase_() {}

	unsigned int size() { return size_; }
	unsigned int ref() { return ref_; }
	unsigned int align() { return align_; }

	void addRef() { ref_++; }
	void subRef()
	{
		ref_--;
		if (!ref_) delete this;
	}

	// Conversion to pointer of allocated memory type
	operator T* () { return pData_; }
	operator const T* () const { return pData_; }

protected:
	virtual void allocate() = 0;
	virtual void deallocate() = 0;

	// Memory alignment
	T* alignPointer(void* raw)
	{
		T* p = reinterpret_cast<T*> (
			(reinterpret_cast<uintptr_t> (raw) + align_ - 1)
			& ~(align_ - 1));
		return p;
	}

	// Disallow copy-constructor and assignment operator
	apAllocatorBase_(const apAllocatorBase_& src);
	apAllocatorBase_& operator= (const apAllocatorBase_& src);

	char* pRaw_;
	T* pData_;
	unsigned int size_;
	unsigned int ref_;
	unsigned int align_;
};