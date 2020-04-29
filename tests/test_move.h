#ifndef TEST_MOVE_H
#define TEST_MOVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "move.h"
#include "load.h"
#include "text/_text.h"
}

TEST(move, last_place_in_line){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move(txt, 0, 5), 1);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    int pos = txt->cursor->pos;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ(pos, 5);
    EXPECT_EQ(result, 0);
    remove_all(txt);

}

TEST(move, random_place_in_text){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move(txt, 2, 3), 1);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    int pos = txt->cursor->pos;
    while (it != txt->cursor->line){
        it++;
        result++;
    }
    EXPECT_EQ(pos, 3);
    EXPECT_EQ(result, 2);
    remove_all(txt);


}

TEST(move, negative){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move(txt, -1, -1), 0);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    int pos = txt->cursor->pos;
    while (it != txt->cursor->line){
        it++;
        result++;
    }

    EXPECT_EQ(pos, 13);
    EXPECT_EQ(result, 3);
    remove_all(txt);
}

TEST(move, negative2){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    EXPECT_EQ(move(txt, 't', 'g'), 0);

    list <string> :: iterator it = txt->lines.begin();
    int result = 0;
    int pos = txt->cursor->pos;
    while (it != txt->cursor->line){
        it++;
        result++;
    }

    EXPECT_EQ(pos, 13);
    EXPECT_EQ(result, 3);
    remove_all(txt);
}


#endif // TEST_MOVE_H
