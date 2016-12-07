#include "StringBufferRefCount.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

StringBufferRefCount::StringBufferRefCount() {
	this->_strbuf = 0;
	this->_length = 0;
	this->_refcount = 1;
}
//destructor

StringBufferRefCount::~StringBufferRefCount() {
	delete[] this->_strbuf;
}

//copy a const StringBuffer into this string

StringBufferRefCount::StringBufferRefCount(const StringBufferRefCount& newString) {
	this->_strbuf = new char[newString.length()];
	this->_length = newString.length();
	//copy the passed string into internal buffer
	this->smartCopy(newString._strbuf, _length);
}

//copy a char* into your string

StringBufferRefCount::StringBufferRefCount(char* newString, int length) {
	_length = length;
	delete[] _strbuf;
	_strbuf = new char[length];
	_strbuf = newString;

	//Should I delete the string passed by the user?
	//delete[] newString;

}

//make a smart copy of the StringBuffer into the callee StringBuffer

void StringBufferRefCount::smartCopy(StringBufferRefCount* newString) {
	int shorterLength = 0;
	(this->_length < newString->_length) ? shorterLength = this->_length : shorterLength = newString->_length;
	int it = 0;
	while (it < shorterLength) {
		*_strbuf++ = *(newString->_strbuf)++;
		it++;
	}
}

//make a smart copy of the char* into this string

void StringBufferRefCount::smartCopy(char* newString, int length) {
	//(this->_length == length)?:this->_length=length;
	this->_length = length;
	int it = 0;
	while (it < length) {
		*_strbuf++ = *newString++;
		it++;
	}
}
//make a smart copy of this string into the passed string

void StringBufferRefCount::revSmartCopy(char* newString) {
	int it = 0;
	while (it < _length) {
		newString[it] = _strbuf[it];
		it++;
	}
}

void StringBufferRefCount::reserve(int n) {
	if (_length < n) {

		int newlength = n; //max(_length*2,n);
		char* newbuf = new char[newlength];

		//copy contents of the stored string in the new buffer
		this->revSmartCopy(newbuf);

		//return stuff from the new buffer to the stored buffer
		//delete[] this->_strbuf;

		this->_strbuf = newbuf;
		this->_length = newlength;


	}
}


//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void StringBufferRefCount::append(char c) {
	this->_strbuf[this->_length - 1] = c;

}
//get length of the string

int StringBufferRefCount::length() const {
	return this->_length;
}

//get character at index if it is less than length

char StringBufferRefCount::charAt(int index) const {
	if (index < _length) {
		return _strbuf[index];
	}
	else {
		//throw new IndexOutOfBoundException();
		return 0;
	}
}


