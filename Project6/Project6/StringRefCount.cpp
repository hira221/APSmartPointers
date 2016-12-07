#include "StringBufferRefCount.h"
#include "StringRefCount.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

StringRefCount::StringRefCount() {
	this->_str = new StringBufferRefCount();
	//because circular link list
	this->next = this;
	this->prev = this;

}
//destructor

StringRefCount::~StringRefCount() {

	//check if this is the only reference, delete the buffer.
	if (this->prev == this->next && this->next == this->prev) {
		cout << this->_str;
		this->_str->~StringBufferRefCount();
		delete[] this->_str;
	}

}

//copy a String into this string

StringRefCount::StringRefCount(StringRefCount& oldString) {
	StringRefCount* find;
	StringRefCount* findprev;
	
	find = &oldString;
	findprev = oldString.prev;
	this->_str = oldString._str;
	//if only one reference

	if (oldString.Counter()==1){
		this->prev = &oldString;
		this->next = &oldString;
		oldString.next = this;
		oldString.prev = this;
	}
	else{
		//add another reference link in more than 1 existing links
		this->next = find;
		this->prev = findprev;
		findprev->next = this;
		find->prev = this;

	}
}

//copy a char* into your string

StringRefCount::StringRefCount(char* newString, int length) {
	this->_str = new StringBufferRefCount(newString, length);
	//because circular link list
	this->next = this;
	this->prev = this;
	

}

void StringRefCount::append(char c) {

	//    char* tempbuf = new char[this->_str->length()+1];
	//    this->_str->revSmartCopy(tempbuf);
	if (this->next==this->prev&& this->prev==this->next) {
		this->_str->reserve(this->_str->length() + 1);
	}
	else {
		//more than 1 reference to this string
		auto_ptr<StringBufferRefCount> newdata(new StringBufferRefCount);
		newdata.get()->reserve(this->_str->length() + 1);
		newdata.get()->smartCopy(this->_str);

		//new copy with no refernence to it except itself
		this->next = this;
		this->prev = this;

		//cout<<"length at newdata"<<newdata.get()->length()<<endl;
		//now split the object instances
		this->_str = newdata.release();
	}

	//copy the new character at the end of this string
	this->_str->append(c);

}

//get length of the string

int StringRefCount::length() const {
	return this->_str->length();
}

int StringRefCount::Counter(){
	int counter=1;
	StringRefCount* checker;
	StringRefCount* start;
	start = this;
	checker = this->next;
	//cout << "start "<< start << "checker "<<checker;
	while (checker != start){
		checker = checker->next;
		counter++;
	}
	return counter;

}
//get character at index if it is less than length

char StringRefCount::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		return 0;
	}
}






