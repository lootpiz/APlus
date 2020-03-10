#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
using namespace std;

class MyException : public exception
{
public:
	MyException(const string& msg)
		:_Str(msg)
	{
	}

	virtual ~MyException()
	{
	}

	virtual const char *what() const
	{
		return _Str.c_str();
	}
protected:
	string _Str;
};

#endif
