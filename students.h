#ifndef STUDENTS_H
#define STUDENTS_H

// ��ũ�� ����Ʈ�� ����Ѵ�.
#include "list.h"

// ���� ������ �����ϴ� Ŭ����
class Students
{
public:
	// ShowAll()���� ��� ������ �����ϱ� ���� ����ü
	enum FORMAT { CONSOLE, TEXTFILE, HTMLFILE };

public:
	Students();
	~Students();

	bool AddStudent(bool general);
	void ShowAll(FORMAT fmt);

	// �� �Լ��� �ּҸ� List ��ü��
	// �����ڿ� �Ѱ��ַ��� ���� ��� �Լ��� �Ǿ� �Ѵ�.
	static void DeleteData(void* data);

private:
	List students;			// ��ũ�� ����Ʈ
	float TotalAve;			// ��ü ���
	int NumberOfStudent;	// ������� �Էµ� �л� ��
};

#endif