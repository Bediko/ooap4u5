#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//********************************************************************
template <typename T>
struct Pair {
	int key;
	T value;
	
};

//********************************************************************
template <typename T>
class Dictionary {
private:
	int _size;
	int _last;
	int _pos;
	Pair<T> *_items;
	bool isFull() const;
	void increase();
	
public:
	Dictionary();
	
	Dictionary(const Dictionary<T> &other);
	Dictionary<T> & operator=(const Dictionary<T> &other);
	
	~Dictionary();
	void insert(int key, T value);
	bool contains(int key) const;
	T get(int key) const;
	void remove(int key);
	void erase();
	
	
	Pair<T> first();
	Pair<T> next();
};

template <typename T>
Dictionary<T>::Dictionary(const Dictionary<T> &other) {
	_size = other._size;
	_last = other._last;
	_pos = 0;
	_items = new Pair<T>[_size];
	for (int i=0; i<_last; i++) {
		_items[i] = other._items[i];
	}
}

template <typename T>
Dictionary<T> & Dictionary<T>::operator=(const Dictionary<T> &other) {
	if (this != &other) {
		delete[] _items;
		
		_size = other._size;
		_last = other._last;
		_pos = 0;
		_items = new Pair<T>[_size];
		for (int i=0; i<_last; i++) {
			_items[i] = other._items[i];
		}
	}
	return *this;
}


//********************************************************************
template <typename T>
Dictionary<T>::Dictionary() {
	_size = 8;
	_last = 0;
	_pos = 0;
	_items = new Pair<T>[_size];
}

//********************************************************************
template <typename T>
Dictionary<T>::~Dictionary() {
	delete[] _items;
}

//********************************************************************
template <typename T>
void Dictionary<T>::increase() {
	Pair<T> *tmp = new Pair<T>[_size * 2];
	
	for (int i = 0; i < _size; i++)
		tmp[i] = _items[i];
	
	delete[] _items;
	_items = tmp;
	_size *= 2;
}

//********************************************************************
template <typename T>
bool Dictionary<T>::contains(int key) const {
	for (int i = 0; i < _last; i++)
		if (_items[i].key == key)
			return true;
	return false;
}

//********************************************************************
template <typename T>
bool Dictionary<T>::isFull() const {
	return _size == _last;
}

//********************************************************************
template <typename T>
void Dictionary<T>::insert(int key, T value) {
	Pair<T> p;
	
	if (contains(key))
		throw "Dictionary: DuplicateKeyException";
	
	if (isFull())
		increase();
	
	p.key = key;
	p.value = value;
	
	_items[_last] = p;
	_last += 1;
}

//********************************************************************
template <typename T>
T Dictionary<T>::get(int key) const {
	for (int i = 0; i < _last; i++)
		if (_items[i].key == key)
			return _items[i].value;
	
	throw "Dictionary: NoSuchKeyException";
}

//********************************************************************
template <typename T>
void Dictionary<T>::remove(int key) {
	int i;
	
	for (i = 0; i < _last && _items[i].key != key; i++)
		;
	
	if (i < _last) {
		_items[i] = _items[_last - 1];
		_last -= 1;
	} else throw "Dictionary: NoSuchKeyException";
}

//********************************************************************
template <typename T>
void Dictionary<T>::erase() {
	_last = 0;

}

//********************************************************************
template <typename T>
Pair<T> Dictionary<T>::first() {
	_pos = 0;
	if (_pos >= _last)
		throw "Dictionary: IsEmptyException";
	
	return _items[_pos++];
}

//********************************************************************
template <typename T>
Pair<T> Dictionary<T>::next() {
	if (_pos >= _last)
		throw "Dictionary: NoMoreElementsException";
	
	return _items[_pos++];
}


#endif
