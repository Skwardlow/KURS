#include "mainconst.h"

void welcome()
	{
		printf(TabCaption, message1, Tab, message2, TabCaption, message3);
	}

void mainmenu(char *ru)
	{
		printf(TabCaption, message4,"   %s", ru);
	}
