/* 
 * File:   main.cpp
 *
 * Created on February 16, 2016, 9:51 PM
 */

#include <cstdlib>
#include <iostream>
#include<cstring>
#include "StringBuffer.h"
#include "String.h"
#include "StringBufferRefCount.h"
#include "StringRefCount.h"
using namespace std;


int main(int argc, char** argv) {
    //create a smart string
//    String ss;
    //create a smart string with const char*
    char* hello = "hello";
	//StringRefCount s1();
    
    
    String ss2(hello,5);
    std::cout<<"ss2 length = "<<ss2.length()<<std::endl;
    cout<<hello<<endl;
    //multiple references
    String ss(ss2);
	
	ss2.append('w');
	std::cout << "appended ss2 length = " << ss2.length() << std::endl;

    //cout<<hello<<endl;
    //output statements
    std::cout<<"ss length = "<<ss.length()<<std::endl;
    //std::cout<<"new ss charAt 3 = "<<ss.charAt(3)<<std::endl;

	//------OWNERSHIP TRANSFER------
	cout << endl;
	cout << "Ownership Transfer" << endl;
	String ss3("hii",3);

	//smart pointers made in main because function would limit scope
	shared_ptr<String> owner;	//make a shared owning pointer 
	owner=make_shared <String>(ss3);
	weak_ptr<String> ss4;		//make a weak read only pointer


	cout << "owner old length " << owner->length() << endl;
	owner->append('x');			//owner can append
	cout << "owner new length "<<owner->length()<<endl;


	ss4 = owner;				//ss4 is a readonly weak pointer to owner
	//ss4.append('y');			cannot append read only
		
	//----REFERENCE LINKING-----
	cout << endl;
	cout << "Reference Linking: " << endl;
	StringRefCount ss5(hello, 5);
	//append a character
	//ss5.append('w');
	std::cout << "initial ss5 references = " << ss5.Counter() << std::endl;
	//cout << hello << endl;

	//2 references
	StringRefCount ss6(ss5);
	std::cout << "new ss5 references = " << ss5.Counter() << std::endl;
	std::cout << "ss6 references = " << ss6.Counter() << std::endl;

	//3 references
	StringRefCount ss7(ss5);
	std::cout << "new ss5 references = " << ss5.Counter() << std::endl;
	std::cout << "ss7 references = " << ss7.Counter() << std::endl;

	
    
    //cout<<hello<<endl;
    //hello = "bye";
	cout << endl;
	cout << "Checking reference linking with append: " << endl;
	StringRefCount ss8("hi", 2);
	
    std::cout<<"old ss8 length = "<<ss8.length()<<std::endl;
	//append a character
	ss8.append('w');
    std::cout<<"new ss8 length = "<<ss8.length()<<std::endl;

	cout << endl;
	std::cout << "old ss5 references before append = " << ss5.Counter() << std::endl;
	std::cout << "old ss5 length = " << ss5.length() << std::endl;

	ss5.append('x');
	std::cout << "new ss5 references after append, new copy(COW)= " << ss5.Counter() << std::endl;
	std::cout << "new ss5 length = " << ss5.length() << std::endl;

	system("pause");
    return 0;
}

