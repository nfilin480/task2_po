#ifndef TEST_RLE_H
#define TEST_RLE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "rle.h"
#include "load.h"
#include "move.h"
#include "text/_text.h"
}


TEST(rle, last_place){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    move (txt, 0, 6);
    ASSERT_EQ(rle(txt), 0);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ((int)(*(txt->cursor->line)).size(), 7);
    remove_all(txt);
}

TEST(rle, standart_random_place){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    move (txt, 2, 3);
    ASSERT_EQ(rle(txt), 1);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ((int)(*(txt->cursor->line)).size(), 4);
    remove_all(txt);
}

TEST(rle, negative){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    move (txt, 't', 'g');
    ASSERT_EQ(rle(txt), 0);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ((int)(*(txt->cursor->line)).size(), 13);
    remove_all(txt);
}
TEST(rle, negative2){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    move (txt, 101, 78);
    ASSERT_EQ(rle(txt), 0);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ((int)(*(txt->cursor->line)).size(), 13);
    remove_all(txt);
}

#endif // TEST_RLE_H
