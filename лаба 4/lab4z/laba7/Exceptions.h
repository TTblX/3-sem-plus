#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h> 
#include <cstdlib>
#include <vector>
using namespace std;
#define _EXCEPTION_OUTPUT(ex)\
(\
(cout << "Error message: " << ex.what() << endl), \
(cout << "Error code: " << ex.GetErrorCode() << endl) \
)

class Exception : public exception
{
private:
	string _errorCode;
public:
	Exception(string msg) : exception(msg.c_str())
	{
	}

	string GetErrorCode()
	{
		return _errorCode;
	}

	void SetErrorCode(string errorCode)
	{
		_errorCode = errorCode;
	}
};

class ArgumentNullException : public Exception
{
private:
	string _errorCode = "X00CPP";
public:
	ArgumentNullException(string msg) : Exception((msg + " is null.").c_str())
	{
		Exception::SetErrorCode(_errorCode);
	}
};

class ArgumentIsEmptyException : public Exception
{
private:
	string _errorCode = "X__CPP";
public:
	ArgumentIsEmptyException(string msg) : Exception((msg + " is empty.").c_str())
	{
		Exception::SetErrorCode(_errorCode);
	}
};

class ArgumentException : public Exception
{
private:
	string _errorCode = "X10CPP";
public:
	ArgumentException(string msg) : Exception(msg.c_str())
	{
		Exception::SetErrorCode(_errorCode);
	}
};

class FileOpenErrorException : public Exception
{
private:
	string _errorCode = "XF400CPP";
public:
	FileOpenErrorException(string msg) : Exception(("File name " + msg + " is wrong or doesn't exist.").c_str())
	{
		Exception::SetErrorCode(_errorCode);
	}
};

class FileReadErrorException : public Exception
{
private:
	string _errorCode = "XF501CPP";
public:
	FileReadErrorException(string msg) : Exception((msg + ": invalid data type.").c_str())
	{
		Exception::SetErrorCode(_errorCode);
	}
};