#ifndef STUDENTS_H
#define STUDENTS_H

// 링크드 리스트를 사용한다.
#include "list.h"

// 성적 정보를 관리하는 클래스
class Students
{
public:
	// ShowAll()에서 출력 형식을 지정하기 위한 열거체
	enum FORMAT { CONSOLE, TEXTFILE, HTMLFILE };

public:
	Students();
	~Students();

	bool AddStudent(bool general);
	void ShowAll(FORMAT fmt);

	// 이 함수의 주소를 List 객체의
	// 생성자에 넘겨주려면 정적 멤버 함수가 되야 한다.
	static void DeleteData(void* data);

private:
	List students;			// 링크드 리스트
	float TotalAve;			// 전체 평균
	int NumberOfStudent;	// 현재까지 입력된 학생 수
};

#endif