#ifndef TEST_CP_H
#define TEST_CP_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


extern "C++" {
#include "cp.h"
#include "move.h"
#include "load.h"
#include "text/_text.h"
}



TEST(cp, last_row){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move (txt, 3, 0), 1);
    EXPECT_EQ(cp(txt), 1);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ(result, 2);
    remove_all(txt);
}

TEST(cp, middle_row){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move (txt, 1, 0), 1);
    EXPECT_EQ(cp(txt), 1);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ(result, 0);
    remove_all(txt);
}
TEST(cp, negative_first_row){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move (txt, 0, 0), 1);
    EXPECT_EQ(cp(txt), 0);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ(result, 0);
    remove_all(txt);
}
#endif // TEST_CP_H
