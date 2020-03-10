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
					cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
				else
					cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";

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

				cout << "\n�ؽ�Ʈ ������ ����Ǿ����ϴ�.\n";
				break;
			}
		case MENU_SAVE_HTML:
			{
				s.ShowAll( Students::HTMLFILE);

				cout << "\nHTML ������ ����Ǿ����ϴ�.\n";
				break;
			}
		case MENU_QUIT:
			{
				cout << "\n���α׷��� �����մϴ�.\n";
			}
			return 0;
		} 

		} 
		catch(exception& e)
		{
			cout << "\n[ ������ ���� ������ �߻��߽��ϴ� ]\n";
			cout << "=> " << e.what() << "\n\n";
		}

	}

	return 0;
}