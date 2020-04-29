#ifndef TEST_SHOW_H
#define TEST_SHOW_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fcntl.h>

extern "C++" {
#include "showtrimmedfromstart.h"
#include "load.h"
}

TEST(showtrimmedfromstart, standart){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    char *output_copy = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input_show.txt",INPUTDIRFILESHOW);
    snprintf(output_copy, 1024, "%s/output_copy.txt", INPUTDIRFILESHOW);
    load (txt, filename);

    int newStdout = open(output_copy, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    ASSERT_NE(newStdout, -1);
    int oldStdout = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    dup2(newStdout, STDOUT_FILENO);

    showfromstart(txt);

    fflush(stdout);
    close(newStdout);
    dup2(oldStdout, STDOUT_FILENO);

    char *originalOutput = (char *)malloc(sizeof(char)*2048);
    snprintf(originalOutput, 2048, "%s/output_show.txt", INPUTDIRFILESHOW);

    int testFD = open(output_copy, O_RDONLY);
    int originalFD = open(originalOutput, O_RDONLY);
    char *outBuf = (char *)malloc(sizeof(char)*1024);
    char *testBuf = (char *)malloc(sizeof(char)*1024);
    int testCount, outputCount;
    free(originalOutput);

    testCount = read(testFD, testBuf, 256);
    outputCount = read(originalFD, outBuf, 256);
    close(testFD);
    close(originalFD);

    ASSERT_EQ(testCount, outputCount);
    for(int i = 0; i < testCount; i++)
        ASSERT_EQ(outBuf[i], testBuf[i]);

    remove_all(txt);


}

TEST(showtrimmedfromstart, empty_file){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    char *output_copy = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILESHOW);
    snprintf(output_copy, 1024, "%s/output_copy.txt", INPUTDIRFILESHOW);
    load (txt, filename);

    int newStdout = open(output_copy, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    ASSERT_NE(newStdout, -1);
    int oldStdout = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    dup2(newStdout, STDOUT_FILENO);

    showfromstart(txt);

    fflush(stdout);
    close(newStdout);
    dup2(oldStdout, STDOUT_FILENO);

    char *originalOutput = (char *)malloc(sizeof(char)*2048);
    snprintf(originalOutput, 2048, "%s/output.txt", INPUTDIRFILESHOW);

    int testFD = open(output_copy, O_RDONLY);
    int originalFD = open(originalOutput, O_RDONLY);
    char *outBuf = (char *)malloc(sizeof(char)*1024);
    char *testBuf = (char *)malloc(sizeof(char)*1024);
    int testCount, outputCount;
    free(originalOutput);

    testCount = read(testFD, testBuf, 256);
    outputCount = read(originalFD, outBuf, 256);
    close(testFD);
    close(originalFD);

    ASSERT_EQ(testCount, outputCount);
    for(int i = 0; i < testCount; i++)
        ASSERT_EQ(outBuf[i], testBuf[i]);

    remove_all(txt);


}


#endif // TEST_SHOW_H
