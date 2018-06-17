#ifndef MAINCONST
#define MAINCONST
#define ESC 'E'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

const char *message1 = "Добро пожаловать!";\
const char *message2 = "Данная программа создана, чтобы проверить ваши знания английского языка";
const char *message3 = "Введите S для начала и E для выхода";
const char *message4 = "Текущий глагол - ";
const char *message5 = "Введите три формы глагола через пробел (Inf PS PP соответственно)";
const char *message6 = "Ввод :";
const char *TabCaption ="\n ";//"\n					";
const char *Tab ="\n ";//"\n	"; 

int is_correct(int i, char *inf, char *ps, char *pp)
{
	return (!strcmp(inf, dic[i].first_f) && !strcmp(ps, dic[i].second_f) && !strcmp(pp, dic[i].third_f));
}

void welcome()
{
	printf(" %s%s%s%s%s%s%s", TabCaption, message1, Tab, message2, TabCaption, message3, Tab);
}

int main_menu()
{
	int i=0, correct=0;
	char *inf = new char[128];
	char *ps = new char[128];
	char *pp = new char[128];
	randomize_dic();
	while(i<10)
	{
	    system("clear");
		printf("%s%d. %s%s%s%s%s", TabCaption, i+1 ,message4,dic[i].ru, Tab, message5, TabCaption);
		scanf("%s", inf);
		scanf("%s", ps);
		scanf("%s", pp);
		if (is_correct(i,inf,ps,pp)) correct++;
		i++;
	}
	system("clear");
	return correct;
}

#endif
