#include "test_cp.h"
#include "test_move.h"
#include "test_rle.h"
#include "test_save.h"
#include "test_showtrimmedfromstart.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
