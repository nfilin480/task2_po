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
    
    int oldStdout = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    dup2(newStdout, STDOUT_FILENO);

    showfromstart(txt);

    fflush(stdout);
    close(newStdout);
    dup2(oldStdout, STDOUT_FILENO);

    char *output = (char *)malloc(sizeof(char)*1024);
    snprintf(output, 1024, "%s/output_show.txt", INPUTDIRFILESHOW);

    int copy_file = open(output_copy, O_RDONLY);
    int output_file = open(output, O_RDONLY);
    char *outBuf = (char *)malloc(sizeof(char)*1024);
    char *copyBuf = (char *)malloc(sizeof(char)*1024);
    int copyCount, outputCount;
    free(output);

    copyCount = read(copy_file, copyBuf, 256);
    outputCount = read(output_file, outBuf, 256);
    close(copy_file);
    close(output_file);

    ASSERT_EQ(copyCount, outputCount);
    for(int i = 0; i < copyCount; i++)
        ASSERT_EQ(outBuf[i], copyBuf[i]);

    remove_all(txt);


}

TEST(showtrimmedfromstart, no_standart_file){
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char*) * 1024);
    char *output_copy = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/input.txt",INPUTDIRFILESHOW);
    snprintf(output_copy, 1024, "%s/output_copy.txt", INPUTDIRFILESHOW);
    load (txt, filename);

    int newStdout = open(output_copy, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    
    int oldStdout = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    dup2(newStdout, STDOUT_FILENO);

    showfromstart(txt);

    fflush(stdout);
    close(newStdout);
    dup2(oldStdout, STDOUT_FILENO);

    char *output = (char *)malloc(sizeof(char)*1024);
    snprintf(output, 1024, "%s/output.txt", INPUTDIRFILESHOW);

    int copy_file = open(output_copy, O_RDONLY);
    int output_file = open(output, O_RDONLY);
    char *outBuf = (char *)malloc(sizeof(char)*1024);
    char *copyBuf = (char *)malloc(sizeof(char)*1024);
    int copyCount, outputCount;
    free(output);

    copyCount = read(copy_file, copyBuf, 256);
    outputCount = read(output_file, outBuf, 256);
    close(copy_file);
    close(output_file);

    ASSERT_EQ(copyCount, outputCount);
    for(int i = 0; i < copyCount; i++)
        ASSERT_EQ(outBuf[i], copyBuf[i]);

    remove_all(txt);


}


#endif // TEST_SHOW_H
