#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <selenium/webdriver.h>
#include <string>

class MainPage {
private:
    WebDriver* driver;
    
public:
    MainPage(WebDriver* driver) : driver(driver) {}
    
    void open() {
        driver->get("http://automationpractice.com/");
    }
    
    void clickSignIn() {
        driver->findElement(By::className("login"))->click();
    }
    
    std::string getTitle() {
        return driver->getTitle();
    }
    
    void navigateToWomenSection() {
        driver->findElement(By::linkText("Women"))->click();
    }
    
    void searchForProduct(const std::string& query) {
        auto searchBox = driver->findElement(By::id("search_query_top"));
        searchBox->sendKeys(query);
        driver->findElement(By::name("submit_search"))->click();
    }
};

#endif // MAINPAGE_H
