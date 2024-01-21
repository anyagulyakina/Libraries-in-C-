#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>
#include <iostream>

class DynArr {
public:
	explicit DynArr() = default;
	explicit DynArr(const size_t size, int value = 0);
	~DynArr() {
		delete[] _data;
	}

	size_t Size() const;
	size_t Capacity() const;
	bool Empty() const;

	void Push_back(int value);
	void Pop_back();
	void Clear();
	void Erase(size_t index);
	void Resize(size_t new_size, int value = 0);
	void Insert(size_t index, int value);

	int& operator[](size_t i) const;
	DynArr& operator=(const DynArr& rhs);

private:
	void remapmemory(size_t new_size);
	size_t _size = 0;
	size_t _capacity = 0;
	int* _data = nullptr;
};

#endif