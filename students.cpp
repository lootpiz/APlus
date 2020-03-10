#include "students.h"
#include "student.h"
#include "consoleoutput.h"
#include "textoutput.h"
#include "htmloutput.h"
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

// ����Ʈ �����̸�
const char* DEFAULT_TEXT_FILENAME = "report.txt";
const char* DEFAULT_HTML_FILENAME = "report.html";

// ������
// (List�� �����ڵ� ȣ���Ѵ�)
Students::Students()
: students( &Students::DeleteData )
{
	// �ʱ�ȭ
	TotalAve = 0.0f;
	NumberOfStudent = 0;
}

// �Ҹ���
Students::~Students()
{
	// ���� ���� ���� ����.
}

// �л��� �� �� �߰��Ѵ�.
// general : true-�Ϲ��л�, false-��޿����� �л�
// ��ȯ�� : �� �̻� �Է��� �� ���� ��� false ��ȯ
bool Students::AddStudent(bool general)
{
	Student* std = NULL;

	try
	{
		// �л��� ������ ���� ��ü�� �����Ѵ�.
		if (general)
			std = new Student(NumberOfStudent + 1);
		else
			std = new EngStudent(NumberOfStudent + 1);

		// ���� ������ �Է¹޴´�.
		std->Input();

		// �������� ����ؼ� ���ο� ��ü ����� ����Ѵ�.
		const int current = NumberOfStudent + 1;// ������� �Է¹��� �л� ��
		const int prev = NumberOfStudent;		// ���� ������ �Է¹��� �л� ��

		TotalAve = (TotalAve * prev / current) + (std->GetAverage() / current);

		// �Է¹��� �л� ���� ������Ų��.
		NumberOfStudent++;

		// students ����Ʈ�� �� ��带 �߰��Ѵ�.
		students.InsertNodeAfter( students.GetTail(), std);
	}
	catch(...)
	{
		delete std;
		std = NULL;

		throw;
	}

	return true;
}

// ��ü ������ �����ش�.
// fmt : ��� ���� ����
void Students::ShowAll(FORMAT fmt)
{
	// ���ܸ� ����ؼ� ����Ʈ �����͸� ����Ѵ�.
	// (�ҽ��� �����ϱ� ���ؼ� Ÿ���� ���� �����Ѵ�)
	typedef auto_ptr<BaseOutput> POUT;
	POUT out;

	// ��� ���Ŀ� �´� ��ü�� �����Ѵ�.
	if (TEXTFILE == fmt)
		out = (POUT) new TextOutput( DEFAULT_TEXT_FILENAME);	
	else if(HTMLFILE == fmt)
		out = (POUT) new HTMLOutput( DEFAULT_HTML_FILENAME);	
	else
		out = (POUT) new ConsoleOutput;	

	// ����ǥ�� ����� �����Ѵ�..
	out->BeginTable( "< ��ü ���� ���� >" );

	// ��� �κ��� ����Ѵ�.
	string header[7] = {"�й�", "�̸�", "����", "����", "����", "��޿���", "���" };
	out->PutHeader( header, 7);

	// ����Ʈ�� �ִ� ��� �л��� ������ ����Ѵ�.
	Node* current = students.GetHead()->GetNext();
	while( current != students.GetHead())
	{
		// ���� ����� ����Ÿ�� �����´�.
		const Student* std = (Student*)current->GetData();

		// ���� ���� ������ ����Ѵ�.
		// (��� ��ü�� ���ڷ� �ѱ��)
		std->Show(*out);

		// ���� ��带 ����Ų��.
		current = current->GetNext();
	}

	// ����ǥ�� ����� ��ģ��.
	out->EndTable();

	// ��ü ��� ������ �ϳ��� ���ڿ��� �����.
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << "��ü ��� = " << TotalAve;

	// ��� ��ü�� ���ڿ��� ������.
	out->Write( ss.str() );

	// ����Ʈ �����͸� ��������Ƿ�
	// out ��ü�� ���� �������� �ʿ� ����.
}

// ��ũ�� ����Ʈ�� ������ ���ſ� �Լ�
// (��ũ�� ����Ʈ�� ����� ����Ÿ��
// ������ �� �� �Լ��� ȣ���Ѵ�.)
void Students::DeleteData(void* data)
{
	// Student ����ü�� �ٲ㼭 �����Ѵ�.
	delete (Student*)data;
}