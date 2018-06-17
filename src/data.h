#ifndef DATA_H
#define DATA_H

#include <cstdlib>
#include <cstdio>
#include <cstring>

typedef struct dictionary
{
	char *ru;
	char *first_f;
	char *second_f;
	char *third_f;
} dictionary;

dictionary *dic;
int dic_size;

void load_dictionary(char *file_path)
{
    char tmp[128];
    FILE *file = fopen(file_path, "r");
    while (!feof(file))
    {
        fgets(tmp, 128, file);
        dic_size++;
    }
    fclose(file);
    dic_size--;
    dic = new dictionary[dic_size];
    printf("Size: %d\n", dic_size);
    int i=0, j=0, k=0;
    file = fopen(file_path, "r");
    while (!feof(file) && i<dic_size)
    {
        printf("%d\n", i);
        j=0;
        fgets(tmp, 128, file);
        dic[i].ru = new char[32];
        k=0;
        while (tmp[j]!=' ' && tmp[j]!='\n' && tmp[j]!='\0')
        {
            dic[i].ru[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].ru[k] = '\0';
        dic[i].first_f = new char[32];
        k=0;
        j++;
        while (tmp[j]!=' ' && tmp[j]!='\n' && tmp[j]!='\0')
        {
            dic[i].first_f[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].first_f[k] = '\0';
        dic[i].second_f = new char[32];
        k=0;
        j++;
        while (tmp[j]!=' ' && tmp[j]!='\n' && tmp[j]!='\0')
        {
            dic[i].second_f[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].second_f[k] = '\0';
        dic[i].third_f = new char[32];
        k=0;
        j++;
        while (tmp[j]!=' ' && tmp[j]!='\n' && tmp[j]!='\0')
        {
            dic[i].third_f[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].third_f[k] = '\0';
        i++;
    }
    fclose(file);
}

#endif

