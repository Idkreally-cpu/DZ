#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class PrintEdition {
protected:
    string title;
    int pageCount;

public:
    PrintEdition(const string& title = "", int pageCount = 0) : title(title), pageCount(max(pageCount, 0)) {}

    virtual ~PrintEdition() = default;

    virtual void display() const {
        cout << "Название: " << title << ", Страниц: " << pageCount;
    }

    virtual unique_ptr<PrintEdition> clone() const {
        return make_unique<PrintEdition>(*this);
    }

    virtual bool operator==(const PrintEdition& other) const {
        return title == other.title && pageCount == other.pageCount;
    }
};

class Magazine : public PrintEdition {
    string periodicity;
    int issueNumber;

public:
    Magazine(const string& title = "", int pageCount = 0, const string& periodicity = "", int issueNumber = 0)
        : PrintEdition(title, pageCount), periodicity(periodicity), issueNumber(max(issueNumber, 0)) {}

    void display() const override {
        PrintEdition::display();
        cout << ", Периодичность: " << periodicity << ", Номер выпуска: " << issueNumber;
    }

    unique_ptr<PrintEdition> clone() const override {
        return make_unique<Magazine>(*this);
    }

    bool operator==(const PrintEdition& other) const override {
        if (const auto* p = dynamic_cast<const Magazine*>(&other))
            return PrintEdition::operator==(other) && periodicity == p->periodicity && issueNumber == p->issueNumber;
        return false;
    }
};

class Book : public PrintEdition {
    string author;
    int yearPublished;

public:
    Book(const string& title = "", int pageCount = 0, const string& author = "", int yearPublished = 0)
        : PrintEdition(title, pageCount), author(author), yearPublished(yearPublished < 0 || yearPublished > 2025 ? 0 : yearPublished) {}

    void display() const override {
        PrintEdition::display();
        cout << ", Автор: " << author << ", Год издания: " << yearPublished;
    }

    unique_ptr<PrintEdition> clone() const override {
        return make_unique<Book>(*this);
    }

    bool operator==(const PrintEdition& other) const override {
        if (const auto* p = dynamic_cast<const Book*>(&other))
            return PrintEdition::operator==(other) && author == p->author && yearPublished == p->yearPublished;
        return false;
    }
};

class Textbook : public PrintEdition {
    string subject;
    int gradeLevel;

public:
    Textbook(const string& title = "", int pageCount = 0, const string& subject = "", int gradeLevel = 0)
        : PrintEdition(title, pageCount), subject(subject), gradeLevel(gradeLevel < 1 || gradeLevel > 11 ? 0 : gradeLevel) {}

    void display() const override {
        PrintEdition::display();
        cout << ", Предмет: " << subject << ", Класс: " << gradeLevel;
    }

    unique_ptr<PrintEdition> clone() const override {
        return make_unique<Textbook>(*this);
    }

    bool operator==(const PrintEdition& other) const override {
        if (const auto* p = dynamic_cast<const Textbook*>(&other))
            return PrintEdition::operator==(other) && subject == p->subject && gradeLevel == p->gradeLevel;
        return false;
    }
};

template <typename T>
T getNumberInput(const string& prompt, T minVal, T maxVal) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка: введите число от " << minVal << " до " << maxVal << ".\n";
        } else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

class PrintEditionCollection {
    vector<unique_ptr<PrintEdition>> editions;

public:
    void addEdition(unique_ptr<PrintEdition> edition) {
        editions.push_back(move(edition));
    }

    bool removeEdition(size_t index) {
        if (index < editions.size()) {
            editions.erase(editions.begin() + index);
            return true;
        }
        return false;
    }

    void displayAll() const {
        if (editions.empty()) {
            cout << "Коллекция пуста.\n";
            return;
        }
        for (size_t i = 0; i < editions.size(); ++i) {
            cout << i << ": ";
            editions[i]->display();
            cout << '\n';
        }
    }

    bool compareEditions(size_t index1, size_t index2) const {
        if (index1 >= editions.size() || index2 >= editions.size()) return false;
        bool result = *editions[index1] == *editions[index2];
        cout << "Издания " << (result ? "равны" : "не равны") << '\n';
        return result;
    }

    size_t size() const { return editions.size(); }
};

unique_ptr<PrintEdition> createEdition(int type) {
    string title, extra1, extra2;
    int pageCount, extra3;

    cin.ignore();
    cout << "Введите название: ";
    getline(cin, title);
    pageCount = getNumberInput("Введите количество страниц: ", 0, 10000);

    switch (type) {
        case 1: return make_unique<PrintEdition>(title, pageCount);
        case 2:
            cout << "Введите периодичность: ";
            getline(cin, extra1);
            extra3 = getNumberInput("Введите номер выпуска: ", 1, 1000);
            return make_unique<Magazine>(title, pageCount, extra1, extra3);
        case 3:
            cout << "Введите автора: ";
            getline(cin, extra1);
            extra3 = getNumberInput("Введите год издания: ", 0, 2025);
            return make_unique<Book>(title, pageCount, extra1, extra3);
        case 4:
            cout << "Введите предмет: ";
            getline(cin, extra1);
            extra3 = getNumberInput("Введите класс (1-11): ", 1, 11);
            return make_unique<Textbook>(title, pageCount, extra1, extra3);
        default: return nullptr;
    }
}

int main() {
    PrintEditionCollection collection;
    int choice;

    do {
        cout << "\n=== Меню ===\n"
             << "1. Добавить издание\n"
             << "2. Удалить издание\n"
             << "3. Показать все издания\n"
             << "4. Сравнить издания\n"
             << "5. Выйти\n";

        choice = getNumberInput("Выберите опцию: ", 1, 5);

        switch (choice) {
            case 1: {
                int type = getNumberInput("Выберите тип издания (1-4): ", 1, 4);
                collection.addEdition(createEdition(type));
                cout << "Издание добавлено!\n";
                break;
            }
            case 2: {
                if (collection.size() == 0) {
                    cout << "Коллекция пуста!\n";
                    break;
                }
                collection.displayAll();
                int index = getNumberInput("Введите индекс издания для удаления: ", 0, collection.size() - 1);
                if (collection.removeEdition(index)) cout << "Издание удалено!\n";
                else cout << "Ошибка удаления.\n";
                break;
            }
            case 3: collection.displayAll(); break;
            case 4: {
                if (collection.size() < 2) {
                    cout << "Недостаточно изданий для сравнения!\n";
                    break;
                }
                collection.displayAll();
                int index1 = getNumberInput("Введите индекс первого издания: ", 0, collection.size() - 1);
                int index2 = getNumberInput("Введите индекс второго издания: ", 0, collection.size() - 1);
                collection.compareEditions(index1, index2);
                break;
            }
            case 5: cout << "Выход...\n"; break;
        }
    } while (choice != 5);

    return 0;
}
