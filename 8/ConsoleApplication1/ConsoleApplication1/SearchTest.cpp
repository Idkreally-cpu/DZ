#include "BaseTest.h"
#include "MainPage.h"
#include <gtest/gtest.h>

class SearchTest : public BaseTest, public ::testing::Test {
protected:
    void SetUp() override {
        BaseTest::SetUp();
    }
    
    void TearDown() override {
        BaseTest::TearDown();
    }
};

TEST_F(SearchTest, TestProductSearch) {
    MainPage mainPage(driver.get());
    mainPage.open();
    
    mainPage.searchForProduct("dress");
    
    auto products = driver->findElements(By::cssSelector(".product-container"));
    ASSERT_GT(products.size(), 0);
}
