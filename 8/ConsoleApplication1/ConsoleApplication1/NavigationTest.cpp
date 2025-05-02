#include "BaseTest.h"
#include "MainPage.h"
#include <gtest/gtest.h>

class NavigationTest : public BaseTest, public ::testing::Test {
protected:
    void SetUp() override {
        BaseTest::SetUp();
    }
    
    void TearDown() override {
        BaseTest::TearDown();
    }
};

TEST_F(NavigationTest, TestMainNavigation) {
    MainPage mainPage(driver.get());
    mainPage.open();
    
    ASSERT_EQ(mainPage.getTitle(), "My Store");
    
    mainPage.navigateToWomenSection();
    ASSERT_TRUE(driver->getCurrentUrl().find("id_category=3") != std::string::npos);
}
