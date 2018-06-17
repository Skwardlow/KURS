#include <data.h>
#include <mainconst.h>
#include <cassert>

void test1() {
    int result = is_correct(0, "beat", "beat", "beaten");
    int expected = 1;
    assert(result == expected);
	printf("TEST1-OK\n");
}

void test2() {
    int result = is_correct(0, "Beat", "beat", "beaten");
    int expected = 0;
    assert(result == expected);
	printf("TEST2-OK\n");
}

void test3() {
    randomize_dic();
    int result = is_correct(0, "beat", "beat", "beaten");
    int expected = 0;
    assert(result == expected);
	printf("TEST3-OK\n");
}

void test4() {
    int result = file_exists("/dev/null");
    int expected = 1;
    assert(result == expected);
	printf("TEST4-OK\n");
}

void test5() {
    int result = file_exists("");
    int expected = 0;
    assert(result == expected);
	printf("TEST5-OK\n");
}

int main(int argc, const char** argv) {
    load_dictionary("bin/verbs");
    test1();
    test2();
    test3();
    test4();
    test5();
}
