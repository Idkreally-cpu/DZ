#ifndef BASETEST_H
#define BASETEST_H

#include <memory>
#include <stdexcept>
#include <selenium/webdriver.h>
#include <selenium/chrome.h>

using namespace selenium;

class BaseTest {
protected:
    std::unique_ptr<WebDriver> driver;
    
    void SetUp() {
        ChromeDriverService service("/path/to/chromedriver");
        ChromeOptions options;
        options.add_argument("--start-maximized");
        
        try {
            driver = std::make_unique<ChromeDriver>(service, options);
        } catch (const std::exception& e) {
            throw std::runtime_error("Failed to initialize WebDriver: " + std::string(e.what()));
        }
    }
    
    void TearDown() {
        if (driver) {
            driver->quit();
        }
    }
};

#endif // BASETEST_H
