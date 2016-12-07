

#ifndef STRINGREFCOUNT_H
#define	STRINGREFCOUNT_H

class StringRefCount{
private:
	StringBufferRefCount* _str;

		StringRefCount *next;
		StringRefCount *prev;
public:

	StringRefCount();
	~StringRefCount();
	StringRefCount( StringRefCount&);
	StringRefCount(char*, int);
	void append(char);
	int Counter();
	int length() const;
	char charAt(int) const;
};


#endif	/* STRING_H */

