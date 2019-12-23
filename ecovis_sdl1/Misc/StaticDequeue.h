#pragma once
#ifndef NICOLAS_KLENERT_ARRAYLIST
#define NICOLAS_KLENERT_ARRAYLIST

#include <stdlib.h>
#include <stdexcept>

// Just to be able to change size_type however I want (all containers are doing this)
typedef size_t size_type;

//Idea?: initialising is allowed! we can have one free space (such we don't need the full boolean) and can use this to return the default value
//Notice: pop members do not destroy the element! Maybe do this!

template <class T, size_type N>
class StaticDequeue {
protected:
	T arr[N];
	// tail always looks at first element, head always look one further then the last one
	size_type head;
	size_type tail;
	bool overwrite;
	bool fullFlag;
public:
	StaticDequeue(bool overwrite = false);
	StaticDequeue(T arr[]);
	~StaticDequeue();
	//StaticDequeue& operator= (const StaticDequeue& x);
	size_type size() const noexcept { return fullFlag ? N : (head - tail + N) % N; };
	size_type max_size() const noexcept { return N; };
	bool empty() const noexcept { return head == tail && !fullFlag; };
	bool full() const noexcept { return fullFlag; };
	T& operator[] (size_type n);
	const T& operator[] (size_type n) const;
	T& at(size_type n);
	const T& at(size_type n) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	//assign
	bool push_back(const T& val);
	bool push_front(const T& val);
	T& pop_back();
	const T& pop_back() const;
	T& pop_front();
	const T& pop_front() const;
	//insert
	//erase
	//swap
	void clear() noexcept;
};

//no cpp file. See https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

template <class T, size_type N>
StaticDequeue<T,N>::StaticDequeue(bool overwrite) {
	this->overwrite = overwrite;
	fullFlag = false;
	head = 0;
	tail = 0;
}

template <class T, size_type N>
StaticDequeue<T, N>::StaticDequeue(T arr[]) {
	//TODO: copy the one array to the other and change the pointer
}

template <class T, size_type N>
StaticDequeue<T, N>::~StaticDequeue() {
	//TODO: delete array 
}

template <class T, size_type N>
T& StaticDequeue<T, N>::operator[] (size_type n) {
	return arr[(tail + n) % N];
}

template <class T, size_type N>
const T& StaticDequeue<T, N>::operator[] (size_type n) const {
	return arr[(tail + n) % N];
}

template <class T, size_type N>
T& StaticDequeue<T, N>::at(size_type n) {
	if (n >= size()) throw std::out_of_range("Out of bounds");
	return arr[(tail + n) % N];
}

template <class T, size_type N>
const T& StaticDequeue<T, N>::at(size_type n) const{
	if (n >= size()) throw std::out_of_range("Out of bounds");
	return arr[(tail + n) % N];
}

template <class T, size_type N>
T& StaticDequeue<T, N>::front() {
	return arr[(head - 1 + N) % N];
}

template <class T, size_type N>
const T& StaticDequeue<T, N>::front() const {
	return arr[(head - 1 + N) % N];
}

template <class T, size_type N>
T& StaticDequeue<T, N>::back() {
	return arr[tail];
}

template <class T, size_type N>
const T& StaticDequeue<T, N>::back() const {
	return arr[tail];
}

template <class T, size_type N>
bool StaticDequeue<T, N>::push_back(const T& val) {
	if (fullFlag && !overwrite) return false;
	if (fullFlag) head = (head - 1 + N) % N;
	tail = (tail - 1 + N) % N;
	arr[tail] = val;
	if (tail == head) fullFlag = true;
	return true;
}

template <class T, size_type N>
bool StaticDequeue<T, N>::push_front(const T& val) {
	if (fullFlag && !overwrite) return false;
	if (fullFlag) tail = (tail + 1) % N;
	arr[head] = val;
	head = (head + 1) % N;
	if (tail == head) fullFlag = true;
	return true;
}

template <class T, size_type N>
T& StaticDequeue<T, N>::pop_back() {
	fullFlag = false;
	T& ref = arr[tail];
	tail = (tail + 1) % N;
	return ref;
}

template <class T, size_type N>
const T& StaticDequeue<T, N>::pop_back() const{
	fullFlag = false;
	T& ref = arr[tail];
	tail = (tail + 1) % N;
	return ref;
}

template <class T, size_type N>
T& StaticDequeue<T, N>::pop_front() {
	fullFlag = false;
	head = (head - 1 + N) % N;
	return arr[head];
}

template <class T, size_type N>
const T& StaticDequeue<T, N>::pop_front() const{
	fullFlag = false;
	head = (head - 1 + N) % N;
	return arr[head];
}

template <class T, size_type N>
void StaticDequeue<T, N>::clear() noexcept {
	//clear all references, iterators and items
}

#endif // !NICOLAS_KLENERT_ARRAYLIST