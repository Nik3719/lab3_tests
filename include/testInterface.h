#include <gtest/gtest.h>
#include "interface.h"
#include<fstream>


TEST(interfaceTest, M)
{
    int argc = 4;
    char *argv[] = {"--file", "test.json", "--query", "MPUSH 111 111"};
    interface(argc, argv);

    ifstream is("123.json");
}