#include "BaseTest.h"
#include "MainPage.h"
#include <gtest/gtest.h>
#include <chrono>
#include <thread>

class CartTest : public BaseTest, public ::testing::Test {
protected:
    void SetUp() override {
        BaseTest::SetUp();
    }
    
    void TearDown() override {
        BaseTest::TearDown();
    }
    
    void waitForElement(By by, int timeout_sec = 10) {
        auto start = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start < std::chrono::seconds(timeout_sec)) {
            try {
                if (driver->findElement(by)->isDisplayed()) {
                    return;
                }
            } catch (...) {}
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        throw std::runtime_error("Element not found within timeout");
    }
};

TEST_F(CartTest, TestAddToCart) {
    MainPage mainPage(driver.get());
    mainPage.open();
    mainPage.searchForProduct("printed dress");
    
    driver->findElement(By::cssSelector(".ajax_add_to_cart_button"))->click();
    
    waitForElement(By::id("layer_cart"));
    
    ASSERT_TRUE(driver->findElement(By::cssSelector(".layer_cart_product h2"))->getText().find("successfully") != std::string::npos);
}

TEST_F(CartTest, TestRemoveFromCart) {
    // Предварительное добавление товара
    MainPage mainPage(driver.get());
    mainPage.open();
    mainPage.searchForProduct("printed dress");
    driver->findElement(By::cssSelector(".ajax_add_to_cart_button"))->click();
    waitForElement(By::id("layer_cart"));
    
    // Переход в корзину и удаление
    driver->findElement(By::cssSelector("a[title='View my shopping cart']"))->click();
    driver->findElement(By::className("cart_quantity_delete"))->click();
    
    waitForElement(By::cssSelector(".alert.alert-warning"));
    
    ASSERT_TRUE(driver->findElement(By::cssSelector(".alert.alert-warning"))->getText().find("empty") != std::string::npos);
}
