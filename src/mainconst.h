#ifndef MAINCONST
#define MAINCONST
#define ESC 'E'

#include <stdio.h>
#include <stdlib.h>

const char *message1 = "Добро пожаловать!";\
const char *message2 = "Данная программа создана, чтобы проверить ваши знания английского языка";
const char *message3 = "Введите S для начала и E для выхода";
const char *message4 = "Текущий глагол - ";
const char *message5 = "Введите три формы глагола через Enter (Inf PS PP соответственно)";
const char *message6 = "Ввод :";
const char *TabCaption ="\n					";
const char *Tab ="\n	"; 


void welcome()
{
	printf(" %s%s%s%s%s%s%s", TabCaption, message1, Tab, message2, TabCaption, message3, Tab);
}

int main_menu()
{
	printf("%s%s  Бить  %s%s", TabCaption ,message4,/*dictionary[i].ru*/ Tab, message5);
}



#endif
