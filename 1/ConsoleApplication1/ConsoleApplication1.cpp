#include <iostream>
#include <string>
#include <unordered_map>

class Book {
private:
    std::string title;
    std::string author;
    int year;
    int id;

public:
    Book(std::string t, std::string a, int y, int i)
        : title(t), author(a), year(y), id(i) {
    }

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }
    int getId() const { return id; }

    void display() const {
        std::cout << "ID: " << id << ", Название: " << title
            << ", Автор: " << author << ", Год: " << year << std::endl;
    }
};

class Library {
private:
    std::unordered_map<int, Book> books;

public:
    void addBook(const Book& book) {
        books[book.getId()] = book;
        std::cout << "Книга добавлена: " << book.getTitle() << std::endl;
    }

    void removeBook(int id) {
        auto it = books.find(id);
        if (it != books.end()) {
            std::cout << "Книга удалена: " << it->second.getTitle() << std::endl;
            books.erase(it);
        }
        else {
            std::cout << "Книга с ID " << id << " не найдена." << std::endl;
        }
    }

    void findBookById(int id) {
        auto it = books.find(id);
        if (it != books.end()) {
            std::cout << "Найдена книга: ";
            it->second.display();
        }
        else {
            std::cout << "Книга с ID " << id << " не найдена." << std::endl;
        }
    }

    void findBooksByTitle(const std::string& title) {
        bool found = false;
        for (const auto& pair : books) {
            if (pair.second.getTitle() == title) {
                pair.second.display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Книги с названием '" << title << "' не найдены." << std::endl;
        }
    }

    void findBooksByAuthor(const std::string& author) {
        bool found = false;
        for (const auto& pair : books) {
            if (pair.second.getAuthor() == author) {
                pair.second.display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Книги автора '" << author << "' не найдены." << std::endl;
        }
    }

    void displayAllBooks() {
        if (books.empty()) {
            std::cout << "Библиотека пуста." << std::endl;
            return;
        }

        std::cout << "Все книги в библиотеке:" << std::endl;
        for (const auto& pair : books) {
            pair.second.display();
        }
    }

    int getBookCount() const {
        return books.size();
    }
};

int main() {
    Library library;

    Book book1("Война и мир", "Лев Толстой", 1869, 1);
    Book book2("Преступление и наказание", "Федор Достоевский", 1866, 2);
    Book book3("Мастер и Маргарита", "Михаил Булгаков", 1967, 3);
    Book book4("1984", "Джордж Оруэлл", 1949, 4);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    std::cout << "\n";

    library.displayAllBooks();

    std::cout << "\n";

    library.findBookById(2);
    library.findBooksByAuthor("Лев Толстой");

    std::cout << "\n";

    library.removeBook(3);

    std::cout << "\n";

    library.displayAllBooks();

    std::cout << "\nОбщее количество книг: " << library.getBookCount() << std::endl;

    return 0;
}
