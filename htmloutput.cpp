#include "htmloutput.h"
#include "myexception.h"
#include <iostream>
#include <iomanip>
using namespace std;


HTMLOutput::HTMLOutput(STR filename)
{
	columns = 0;

	fout.open( filename.c_str() );

	if (false == fout.is_open())
		throw MyException( filename + "을 열 수 없습니다.");

	fout << "<HTML><HEAD><TITLE>IT 백두대간 C++ 프로젝트</TITLE></HEAD><BODY><CENTER>";
}

HTMLOutput::~HTMLOutput()
{
	fout << "</CENTER></BODY></HTML>";
	fout.close();
}

void HTMLOutput::BeginTable(STR title)
{
	fout << "<H3>" << title << "</H3>";

	fout << "<TABLE bgcolor='slategray' cellspacing='1' cellpadding='4' border='0'>";
}

void HTMLOutput::PutHeader(string headers[], int number)
{
	columns = number;

	fout << "<TR bgcolor='#e0e0ff' align='center'>";
	for (int i = 0; i < number; ++i)
		fout << "<TD>" << headers[i] << "</TD>";
	fout << "</TR>";
}

void HTMLOutput::PutRecord(string record[])
{
	fout << "<TR bgcolor='white' align='right'>";
	for (int i = 0; i < columns; ++i)
		fout << "<TD>" << record[i] << "</TD>";
	fout << "</TR>";
}

void HTMLOutput::EndTable()
{
	fout << "</TABLE>";
}

void HTMLOutput::Write(STR text)
{
	fout << "<P>" << text << "</P>";
}
