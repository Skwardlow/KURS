#include "data.h"
#include "mainconst.h"

int main();

int main()
{
    char ch;
    load_dictionary("bin/verbs");
    while (true) {
        int flag = 1;
        while (flag == 1) {
            system("clear");
            welcome();
            ch = getchar();
            if (ch == ESC)
                return 0;
            if (ch == 'S') {
                flag = 2;
            }
        }
        while (flag == 2) {
            printf("Тестирование завершено. Правильных ответов: %d/10\n",
                    main_menu());
            scanf("%c", &ch);
            return 0;
        }
    }
}

