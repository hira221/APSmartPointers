/* 
 * File:   String.h
 *
 * Created on February 18, 2016, 6:17 PM
 */

#ifndef STRING_H
#define	STRING_H

class String{
private:
    StringBuffer* _str;
public:
    String();
    ~String();
    String(const String&);
    String(char* ,int);
	String&  operator=(String&);
    void append(char);
    int length() const;
    char charAt(int) const;
};


#endif	/* STRING_H */

