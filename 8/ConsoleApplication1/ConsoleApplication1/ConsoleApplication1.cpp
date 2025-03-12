#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PrintEdition {
protected:
    string title;
    int pageCount;

public:
    PrintEdition() : title(""), pageCount(0) {}

    PrintEdition(const string& title, int pageCount) :
        title(title), pageCount(pageCount < 0 ? 0 : pageCount) {}

    virtual ~PrintEdition() {}

    virtual void display() const {
        cout << "Печатное издание: " << title << ", Страниц: " << pageCount;
    }

    virtual PrintEdition* clone() const {
        return new PrintEdition(*this);
    }

    virtual bool operator==(const PrintEdition& other) const {
        return title == other.title && pageCount == other.pageCount;
    }
};

class Magazine : public PrintEdition {
private:
    string periodicity;
    int issueNumber;

public:
    Magazine() : PrintEdition(), periodicity(""), issueNumber(0) {}

    Magazine(const string& title, int pageCount, const string& periodicity, int issueNumber)
        : PrintEdition(title, pageCount), periodicity(periodicity),
        issueNumber(issueNumber < 0 ? 0 : issueNumber) {}

    void display() const override {
        PrintEdition::display();
        cout << ", Периодичность: " << periodicity << ", Номер выпуска: " << issueNumber;
    }

    PrintEdition* clone() const override {
        return new Magazine(*this);
    }

    bool operator==(const PrintEdition& other) const override {
        const Magazine* p = dynamic_cast<const Magazine*>(&other);
        if (!p) return false;

        return PrintEdition::operator==(other) &&
            periodicity == p->periodicity &&
            issueNumber == p->issueNumber;
    }
};

class Book : public PrintEdition {
private:
    string author;
    int yearPublished;

public:
    Book() : PrintEdition(), author(""), yearPublished(0) {}

    Book(const string& title, int pageCount, const string& author, int yearPublished)
        : PrintEdition(title, pageCount), author(author),
        yearPublished((yearPublished < 0 || yearPublished > 2025) ? 0 : yearPublished) {}

    void display() const override {
        PrintEdition::display();
        cout << ", Автор: " << author << ", Год издания: " << yearPublished;
    }

    PrintEdition* clone() const override {
        return new Book(*this);
    }

    bool operator==(const PrintEdition& other) const override {
        const Book* p = dynamic_cast<const Book*>(&other);
        if (!p) return false;

        return PrintEdition::operator==(other) &&
            author == p->author &&
            yearPublished == p->yearPublished;
    }
};

class Textbook : public PrintEdition {
private:
    string subject;
    int gradeLevel;

public:
    Textbook() : PrintEdition(), subject(""), gradeLevel(0) {}

    Textbook(const string& title, int pageCount, const string& subject, int gradeLevel)
        : PrintEdition(title, pageCount), subject(subject),
        gradeLevel((gradeLevel < 1 || gradeLevel > 11) ? 0 : gradeLevel) {}

    void display() const override {
        PrintEdition::display();
        cout << ", Предмет: " << subject << ", Класс: " << gradeLevel;
    }

    PrintEdition* clone() const override {
        return new Textbook(*this);
    }

    bool operator==(const PrintEdition& other) const override {
        const Textbook* p = dynamic_cast<const Textbook*>(&other);
        if (!p) return false;

        return PrintEdition::operator==(other) &&
            subject == p->subject &&
            gradeLevel == p->gradeLevel;
    }
};

template <typename T>
T getNumberInput(const string& prompt, T minVal, T maxVal) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Ошибка: Введите корректное число.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (value < minVal || value > maxVal) {
            cout << "Ошибка: Введите число в диапазоне от " << minVal << " до " << maxVal << ".\n";
        }
        else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

class PrintEditionCollection {
private:
    vector<PrintEdition*> editions;

public:
    PrintEditionCollection() {}

    ~PrintEditionCollection() {
        for (auto edition : editions) {
            delete edition;
        }
    }

    PrintEditionCollection(const PrintEditionCollection& other) {
        for (const auto& edition : other.editions) {
            editions.push_back(edition->clone());
        }
    }

    PrintEditionCollection& operator=(const PrintEditionCollection& other) {
        if (this != &other) {
            for (auto edition : editions) {
                delete edition;
            }
            editions.clear();

            for (const auto& edition : other.editions) {
                editions.push_back(edition->clone());
            }
        }
        return *this;
    }

    void addEdition(PrintEdition* edition) {
        editions.push_back(edition);
    }

    bool removeEdition(size_t index) {
        if (index < editions.size()) {
            delete editions[index];
            editions.erase(editions.begin() + index);
            return true;
        }
        return false;
    }

    void displayAll() const {
        if (editions.empty()) {
            cout << "Коллекция пуста." << endl;
            return;
        }

        for (size_t i = 0; i < editions.size(); ++i) {
            cout << i << ": ";
            editions[i]->display();
            cout << endl;
        }
    }

    bool compareEditions(size_t index1, size_t index2) const {
        if (index1 >= editions.size() || index2 >= editions.size()) {
            return false;
        }

        bool result = *editions[index1] == *editions[index2];
        cout << "Издания " << (result ? "одинаковые" : "разные") << endl;
        return result;
    }

    size_t size() const {
        return editions.size();
    }
};

PrintEdition* createPrintEdition() {
    string title;
    cin.ignore();
    cout << "Введите название: ";
    getline(cin, title);

    int pageCount = getNumberInput<int>("Введите количество страниц: ", 0, 10000);

    return new PrintEdition(title, pageCount);
}

PrintEdition* createMagazine() {
    string title, periodicity;
    cin.ignore();
    cout << "Введите название журнала: ";
    getline(cin, title);

    int pageCount = getNumberInput<int>("Введите количество страниц: ", 0, 500);

    cout << "Введите периодичность (например, 'ежемесячный'): ";
    getline(cin, periodicity);

    int issueNumber = getNumberInput<int>("Введите номер выпуска: ", 1, 1000);

    return new Magazine(title, pageCount, periodicity, issueNumber);
}

PrintEdition* createBook() {
    string title, author;
    cin.ignore();
    cout << "Введите название книги: ";
    getline(cin, title);

    int pageCount = getNumberInput<int>("Введите количество страниц: ", 0, 2000);

    cout << "Введите автора: ";
    getline(cin, author);

    int yearPublished = getNumberInput<int>("Введите год издания: ", 0, 2025);

    return new Book(title, pageCount, author, yearPublished);
}

PrintEdition* createTextbook() {
    string title, subject;
    cin.ignore();
    cout << "Введите название учебника: ";
    getline(cin, title);

    int pageCount = getNumberInput<int>("Введите количество страниц: ", 0, 1000);

    cout << "Введите предмет: ";
    getline(cin, subject);

    int gradeLevel = getNumberInput<int>("Введите класс (1-11): ", 1, 11);

    return new Textbook(title, pageCount, subject, gradeLevel);
}

int main() {
    PrintEditionCollection collection;
    int choice;

    do {
        cout << "\n=== Меню ===\n";
        cout << "1. Добавить новый элемент\n";
        cout << "2. Удалить элемент по индексу\n";
        cout << "3. Вывести все элементы\n";
        cout << "4. Сравнить два элемента\n";
        cout << "5. Завершить работу\n";

        choice = getNumberInput<int>("Выберите действие: ", 1, 5);

        switch (choice) {
        case 1: {
            cout << "\nВыберите тип издания:\n";
            cout << "1. Печатное издание\n";
            cout << "2. Журнал\n";
            cout << "3. Книга\n";
            cout << "4. Учебник\n";

            int editionType = getNumberInput<int>("", 1, 4);
            PrintEdition* newEdition = nullptr;

            switch (editionType) {
            case 1: newEdition = createPrintEdition(); break;
            case 2: newEdition = createMagazine(); break;
            case 3: newEdition = createBook(); break;
            case 4: newEdition = createTextbook(); break;
            }

            if (newEdition) {
                collection.addEdition(newEdition);
                cout << "Элемент добавлен успешно!" << endl;
            }
            break;
        }
        case 2: {
            if (collection.size() == 0) {
                cout << "Коллекция пуста!" << endl;
                break;
            }

            collection.displayAll();
            int index = getNumberInput<int>("Введите индекс элемента для удаления: ", 0, collection.size() - 1);

            if (collection.removeEdition(index)) {
                cout << "Элемент удален успешно!" << endl;
            }
            else {
                cout << "Не удалось удалить элемент. Проверьте индекс." << endl;
            }
            break;
        }
        case 3: {
            collection.displayAll();
            break;
        }
        case 4: {
            if (collection.size() < 2) {
                cout << "Для сравнения нужно минимум два элемента!" << endl;
                break;
            }

            collection.displayAll();
            int index1 = getNumberInput<int>("Введите индекс первого элемента: ", 0, collection.size() - 1);
            int index2 = getNumberInput<int>("Введите индекс второго элемента: ", 0, collection.size() - 1);

            collection.compareEditions(index1, index2);
            break;
        }
        case 5:
            cout << "Выход из программы..." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}