#ifndef _LISTE_H
#define _LISTE_H


#include <iostream>

using namespace std;

template <class T>
class Liste {
private:
	T *_values;
	int _last, _size;
	bool isFull();
	int find(T val);
	void increase();
	void decrease();

public:
	Liste();

	Liste(const Liste<T> &other);
	Liste<T> & operator=(const Liste<T> &other);

	~Liste();
	void append(T value);
	T getValueAt(int pos) const;
	void erase(T value);
	void toScreen() const;
	int getCount() const;
};

template <class T>
Liste<T>::Liste(const Liste<T> &other) {
	_size = other._size;
	_last = other._last;
	_values = new T[_last];
	for (int i=0; i<_last; i++) {
		_values[i] = other._values[i];
	}
}

template <class T>
Liste<T> & Liste<T>::operator=(const Liste<T> &other) {
	if (this != &other) {
		delete[] _values;

		_size = other._size;
		_last = other._last;
		_values = new T[_last];
		for (int i=0; i<_last; i++) {
			_values[i] = other._values[i];
		}
	}
	return *this;
}

template <class T>
bool Liste<T>::isFull() {
	return _last == _size;
}

template <class T>
int Liste<T>::find(T value) {
	for (int i=0; i<_last; i++) {
		if (_values[i] == value) {
			return i;
		}
	}
	return -1;
}

template <class T>
void Liste<T>::increase() {
	T *tmp = new T[_size*2];
	for (int i=0; i<_last; i++) {
		tmp[i] = _values[i];
	}
	delete[] _values;
	_values = tmp;
	_size *= 2;
}

template <class T>
void Liste<T>::decrease() {
	_size /= 2;
	T *tmp = new T[_size];
	for (int i=0; i<_size; i++) {
		tmp[i] = _values[i];
	}
	delete[] _values;
	_values = tmp;
}

template <class T>
Liste<T>::Liste() {
	_size = 10;
	_last = 0;
	_values = new T[_size];
}

template <class T>
Liste<T>::~Liste() {
	delete[] _values;
}

template <class T>
void Liste<T>::append(T value) {
	if (isFull()) {
		increase();
	}
	_values[_last] = value;
	_last++;
}

template <class T>
T Liste<T>::getValueAt(int pos) const {
	if (pos < 0 || pos > _last) {
		throw "Out of bounds";
	}
	return _values[pos];
}

template <class T>
void Liste<T>::erase(T value) {
	int pos = find(value);
	if (pos == -1) {
		"Value not found";
	}
	for (; pos < _last-1; pos++) {
		_values[pos] = _values[pos+1];
	}
	_last--;
	if (_last < _size/4) {
		decrease();
	}
}

template <class T>
void Liste<T>::toScreen() const {
	for (int i=0; i<_last; i++) {
		cout << i << ": " << _values[i] << endl;
	}
}

template <class T>
int Liste<T>::getCount() const {
	return _last;
}



#endif
