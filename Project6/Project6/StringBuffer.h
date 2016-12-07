#include <memory>

#ifndef STRINGBUFFER_H
#define	STRINGBUFFER_H

class StringBuffer{
public :
    StringBuffer();
    ~StringBuffer();
    StringBuffer(const StringBuffer&);
    StringBuffer(char*,int);
	void makeowner(StringBuffer*);
    char charAt(int) const;
    int length() const;
    void smartCopy(char*,int);
    void smartCopy(StringBuffer*);
    void revSmartCopy(char* newString);
    void reserve(int);
    void append(char);
	
    int _refcount;
	
private:
    char* _strbuf;
    int _length;
	
	


    
};

#endif	/* STRINGBUFFER_H */

