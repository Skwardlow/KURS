#ifndef DATA_H
#define DATA_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <unistd.h>

typedef struct dictionary {
    char *ru;
    char *first_f;
    char *second_f;
    char *third_f;
} dictionary;

dictionary *dic;
int dic_size;

int file_exists(char *name)
{
    struct stat buffer;
    return (stat(name, &buffer) == 0);
}

int randomize_dic()
{
    srand(time(NULL));
    dictionary d;
    for (int i = 0; i < 10; i++) {
        d = dic[i];
        int j = rand() % dic_size;
        dic[i] = dic[j];
        dic[j] = d;
    }
}

void load_dictionary(char *file_path)
{
    if (!file_exists(file_path)) {
        printf("Dictionary file not found\n");
        exit(1);
    }
    char tmp[128];
    FILE *file = fopen(file_path, "r");
    while (!feof(file)) {
        fgets(tmp, 128, file);
        dic_size++;
    }
    fclose(file);
    dic_size--;
    if (dic_size <= 10) {
        printf("Dictionary too small\n");
        exit(1);
    }
    dic = new dictionary[dic_size];
    int i = 0, j = 0, k = 0;
    file = fopen(file_path, "r");
    while (!feof(file) && i < dic_size) {
        j = 0;
        fgets(tmp, 128, file);
        dic[i].ru = new char[32];
        k = 0;
        while (tmp[j] != ' ' && tmp[j] != '\n' && tmp[j] != '\0') {
            dic[i].ru[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].ru[k] = '\0';
        dic[i].first_f = new char[32];
        k = 0;
        j++;
        while (tmp[j] != ' ' && tmp[j] != '\n' && tmp[j] != '\0') {
            dic[i].first_f[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].first_f[k] = '\0';
        dic[i].second_f = new char[32];
        k = 0;
        j++;
        while (tmp[j] != ' ' && tmp[j] != '\n' && tmp[j] != '\0') {
            dic[i].second_f[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].second_f[k] = '\0';
        dic[i].third_f = new char[32];
        k = 0;
        j++;
        while (tmp[j] != ' ' && tmp[j] != '\n' && tmp[j] != '\0') {
            dic[i].third_f[k] = tmp[j];
            k++;
            j++;
        }
        dic[i].third_f[k] = '\0';
        i++;
    }

