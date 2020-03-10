#include "textoutput.h"
#include "myexception.h"

TextOutput::TextOutput(STR filename)
{
	fout.open(filename.c_str());

	if (false == fout.is_open())
		throw MyException( filename + "�� �� �� �����ϴ�.");
}

TextOutput::~TextOutput()
{
	fout.close();
}

ostream& TextOutput::StdOut()
{
	return fout;
}

