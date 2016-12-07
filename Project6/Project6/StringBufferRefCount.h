#include <memory>

#ifndef STRINGBUFFERREFCOUNT_H
#define	STRINGBUFFERREFCOUNT_H


class StringBufferRefCount{
public:
	StringBufferRefCount();
	~StringBufferRefCount();
	StringBufferRefCount(const StringBufferRefCount&);
	StringBufferRefCount(char*, int);
	char charAt(int) const;
	int length() const;
	void smartCopy(char*, int);
	void smartCopy(StringBufferRefCount*);
	void revSmartCopy(char* newString);
	void reserve(int);
	void append(char);

	int _refcount;

private:
	char* _strbuf;
	int _length;





};

#endif	/* STRINGBUFFER_H */

