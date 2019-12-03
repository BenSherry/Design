#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "ProductFilterTest.hpp"

using namespace testing;

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
