#include "BaseTest.h"
#include "MainPage.h"
#include <gtest/gtest.h>

class LoginTest : public BaseTest, public ::testing::Test {
protected:
    void SetUp() override {
        BaseTest::SetUp();
    }
    
    void TearDown() override {
        BaseTest::TearDown();
    }
};

TEST_F(LoginTest, TestSuccessfulLogin) {
    MainPage mainPage(driver.get());
    mainPage.open();
    mainPage.clickSignIn();
    
    driver->findElement(By::id("email"))->sendKeys("valid@email.com");
    driver->findElement(By::id("passwd"))->sendKeys("validpassword");
    driver->findElement(By::id("SubmitLogin"))->click();
    
    ASSERT_TRUE(driver->findElement(By::className("account"))->getText().find("Test User") != std::string::npos);
}

TEST_F(LoginTest, TestInvalidLogin) {
    MainPage mainPage(driver.get());
    mainPage.open();
    mainPage.clickSignIn();
    
    driver->findElement(By::id("email"))->sendKeys("invalid@email.com");
    driver->findElement(By::id("passwd"))->sendKeys("wrongpassword");
    driver->findElement(By::id("SubmitLogin"))->click();
    
    ASSERT_TRUE(driver->findElement(By::cssSelector(".alert.alert-danger"))->isDisplayed());
}
