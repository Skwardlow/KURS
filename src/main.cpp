#include "mainconst.h"
#include "data.h"

int main();

int main()
{	while (true)
	{
                int flag = 1;
		while (flag==1)
		{
			welcome();
			if (getchar()==ESC) return 0;
			if (getchar()=='S') 
			{
				flag=2;
				system("cls");
			}
		}
		while (flag==2)
		{
			if (main_menu() == 0) flag=1;
		}
	}
}
