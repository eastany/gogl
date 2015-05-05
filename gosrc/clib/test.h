#ifndef TEST_H
#include <stdio.h>

struct TestStruct {
    int x;
    char *y;
};

void test(char *src);
int test_struct(struct TestStruct *ts);

#endif