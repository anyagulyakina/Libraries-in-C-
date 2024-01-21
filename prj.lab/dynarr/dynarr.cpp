#include <dynarr/dynarr.hpp>

DynArr::DynArr(const size_t size, int value) : _size(size), _capacity(size), _data(nullptr) {
	if (size <= 0) {
		throw std::invalid_argument("you can't create an array that size");
	}
	else {
		_data = new int[_capacity];
		for (int i = 0; i < size; i++) {
			_data[i] = value;
		}
	}
}

size_t DynArr::Size() const {
	return _size;
}
size_t DynArr::Capacity() const {
	return _capacity;
}
bool DynArr::Empty() const {
	return _size == 0;
}
void DynArr::remapmemory(size_t new_size) {
	_capacity = new_size;
	int* new_data = new int[_capacity];
	std::copy(_data, _data + _size, new_data);
	delete[] _data;
	_data = new_data;
}

void DynArr::Push_back(int value) {
	if (_size == _capacity) {
		remapmemory(_size * 2);
	}
	_data[_size++] = value;
}
void DynArr::Pop_back() {
	if (_size < 1) {
		throw std::invalid_argument("you can not delete element because size is too small");
	}
	_size--;
}
void DynArr::Clear() {
	_size = 0;
}
void DynArr::Erase(size_t index) {
	for (int i = index; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	_size--;
}
void DynArr::Resize(size_t new_size, int value) {
	if (_size > new_size) {
		_size = new_size;
	}
	else {
		if (new_size > _capacity) {
			remapmemory(new_size);
		}
		for (int i = _size; i < new_size; i++) {
			_data[i] = value;
		}
		_size = new_size;
	}
}
void DynArr::Insert(size_t index, int value) {
	if (_size == _capacity) {
		remapmemory(_size * 2);
	}
	for (int i = _size; i > index; i--) {
		_data[i] = _data[i - 1];
	}
	_data[index] = value;
	_size++;
}

int& DynArr::operator[](size_t i) const {
	if (i >= 0 && i < _size) {
		return _data[i];
	}
	else {
		throw std::invalid_argument("index is outside the array");
	}
}
DynArr& DynArr::operator=(const DynArr& rhs)
{
	Resize(rhs._size);
	std::copy(rhs._data, rhs._data + rhs._size, _data);
	return *this;
}