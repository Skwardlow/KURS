#include "mainconst.h"
#include "data.h"

int main();

int main()
{
	char ch;
	load_dictionary("bin/verbs");
	while (true)
	{
                int flag = 1;
		while (flag==1)
		{
			welcome();
			ch = getchar();
			if (ch==ESC) return 0;
			if (ch=='S')
			{
				flag=2;
				system("clear");
			}
		}
		while (flag==2)
		{
			main_menu();
		}
	}
}
