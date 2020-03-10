#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include "baseoutput.h"

class ConsoleOutput : public BaseOutput
{
public:
	ConsoleOutput();
	virtual ~ConsoleOutput();

	virtual void BeginTable(STR title);
	virtual void PutHeader(string headers[], int number);
	virtual void PutRecord(string record[]);
	virtual void EndTable();
	virtual void Write(STR text);

protected:
	virtual ostream& StdOut();

protected:
	int columns;
};

#endif
