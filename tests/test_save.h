#ifndef TEST_SAVE_H
#define TEST_SAVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fcntl.h>

extern "C++" {
#include "save.h"
#include "load.h"
#include "text/_text.h"
}

TEST(save, standart_file){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);

    int output = open(filename, O_RDONLY);
    char *outBuf = (char *)malloc(sizeof(char)*256);
    int outCount;
    outCount = read(output, outBuf, 256);
    close(output);
    EXPECT_EQ(save(txt, filename), 1);


    int input = open(filename, O_RDONLY);

    char *inpBuf = (char *)malloc(sizeof(char)*256);

    int inpCount;

    inpCount = read(input, inpBuf, 256);

    close(input);


    ASSERT_EQ(outCount, inpCount);

    for (int i = 0;i < outCount; i++)
          ASSERT_EQ(outBuf[i], inpBuf[i]);


}

TEST(save, other_file){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);

    char *file_name = (char*) malloc (sizeof(char) * 2048);
    snprintf(file_name, 1024, "%s/output.txt",INPUTDIRFILE);
    EXPECT_EQ(save(txt, file_name), 1);


    int input = open(filename, O_RDONLY);
    int output = open(file_name, O_RDONLY);

    char *inpBuf = (char *)malloc(sizeof(char)*256);
    char *outBuf = (char *)malloc(sizeof(char)*256);
    int inpCount, outCount;

    inpCount = read(input, inpBuf, 256);
    outCount = read(output, outBuf, 256);
    close(input);
    close(output);

    ASSERT_EQ(outCount, inpCount);
    for (int i = 0;i < outCount; i++)
          ASSERT_EQ(outBuf[i], inpBuf[i]);

}


TEST(save, negative){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILE);
    load (txt, filename);
    free(filename);
    char *file_name = (char*) malloc (sizeof(char) * 2048);
    snprintf(file_name, 1024, "%s/input.bmp",INPUTDIRFILE);
    EXPECT_EQ(save(txt, file_name), 1);

    int input = open(filename, O_RDONLY);
    int output = open(file_name, O_RDONLY);

    char *inpBuf = (char *)malloc(sizeof(char)*256);
    char *outBuf = (char *)malloc(sizeof(char)*256);
    int inpCount, outCount;

    inpCount = read(input, inpBuf, 256);
    outCount = read(output, outBuf, 256);
    close(input);
    close(output);

    ASSERT_EQ(outCount, inpCount);

    for (int i = 0;i < outCount; i++)
          ASSERT_EQ(outBuf[i], inpBuf[i]);

}
#endif // TEST_SAVE_H
