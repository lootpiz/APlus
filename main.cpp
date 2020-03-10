#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;


int main()
{
	Students s;

	while(1)
	{

		try
		{

		MENU select;
		select = ShowMenu();

		switch(select)
		{
		case MENU_ADD_STUDENT:
		case MENU_ADD_STDUENT_ENG:
			{
				bool succeeded;
				succeeded = s.AddStudent( (MENU_ADD_STUDENT == select ? true : false) );

				if (succeeded)
					cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
				else
					cout << "\n더 이상 입력할 수 없습니다.\n";

				break;
			}
		case MENU_SHOW_ALL:
			{
				s.ShowAll( Students::CONSOLE);
				break;
			}
		case MENU_SAVE_TEXT:
			{
				s.ShowAll( Students::TEXTFILE);

				cout << "\n텍스트 파일이 저장되었습니다.\n";
				break;
			}
		case MENU_SAVE_HTML:
			{
				s.ShowAll( Students::HTMLFILE);

				cout << "\nHTML 파일이 저장되었습니다.\n";
				break;
			}
		case MENU_QUIT:
			{
				cout << "\n프로그램을 종료합니다.\n";
			}
			return 0;
		} 

		} 
		catch(exception& e)
		{
			cout << "\n[ 다음과 같은 문제가 발생했습니다 ]\n";
			cout << "=> " << e.what() << "\n\n";
		}

	}

	return 0;
}
