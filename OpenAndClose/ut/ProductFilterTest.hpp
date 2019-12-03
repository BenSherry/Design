#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include"../src/ProductFilter.hpp"

using namespace testing;
class TestProductFilterShould : public testing::Test
{
public:
    void SetUp()
    {
        Product iphone1("iphone1", Color::BLUE, Size::SMALL);
        Product iphone4s("iphone4s", Color::RED, Size::MAX);
        Product iphoneX("iphoneX", Color::RED, Size::MAX);
        products_.push_back(std::make_shared<Product>(iphone1));
        products_.push_back(std::make_shared<Product>(iphone4s));
        products_.push_back(std::make_shared<Product>(iphoneX));
    };
    void TearDown()
    {
        products_.clear();
    };
    Products products_;

};

TEST_F(TestProductFilterShould, FilterbyColorRed)
{
    ColorSpecification<std::shared_ptr<Product>> redSpec{Color::RED};
    BetterFilter<std::shared_ptr<Product>> filter;
    auto filterByColorBetter = filter.filter(products_, redSpec);
    EXPECT_EQ(filterByColorBetter.size(), 2);
}

