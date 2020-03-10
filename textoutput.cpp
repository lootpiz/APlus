#include "textoutput.h"
#include "myexception.h"

TextOutput::TextOutput(STR filename)
{
	fout.open(filename.c_str());

	if (false == fout.is_open())
		throw MyException( filename + "을 열 수 없습니다.");
}

TextOutput::~TextOutput()
{
	fout.close();
}

ostream& TextOutput::StdOut()
{
	return fout;
}

