#include "test.h"

void test(char *src){
    printf("TEST %s\n",src);
}

int test_struct(struct TestStruct *ts) {
    printf("Struct %s\n",ts->y);
    return ts->x*50;
}