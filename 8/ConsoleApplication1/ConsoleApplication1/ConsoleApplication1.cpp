#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PrintedEdition {
protected:
    int pages;
    string title;
public:
    PrintedEdition() : pages(0), title("") {}
    PrintedEdition(int p, const string& t) : pages(p), title(t) {}
    virtual void print() const {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
    bool operator==(const PrintedEdition& other) const {
        return pages == other.pages && title == other.title;
    }
    PrintedEdition operator+(const PrintedEdition& other) const {
        return PrintedEdition(pages + other.pages, title + " & " + other.title);
    }
    PrintedEdition& operator++() {
        ++pages;
        return *this;
    }
};

class Magazine : public PrintedEdition {
public:
    Magazine() : PrintedEdition() {}
    Magazine(int p, const string& t) : PrintedEdition(p, t) {}
    void print() const override {
        cout << "Magazine: " << title << ", Pages: " << pages << endl;
    }
};

class Book : public PrintedEdition {
public:
    Book() : PrintedEdition() {}
    Book(int p, const string& t) : PrintedEdition(p, t) {}
    void print() const override {
        cout << "Book: " << title << ", Pages: " << pages << endl;
    }
};

class Textbook : public PrintedEdition {
public:
    Textbook() : PrintedEdition() {}
    Textbook(int p, const string& t) : PrintedEdition(p, t) {}
    void print() const override {
        cout << "Textbook: " << title << ", Pages: " << pages << endl;
    }
};

int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            break;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
    }
    return value;
}

string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    cin >> value;
    return value;
}

int main() {
    vector<PrintedEdition*> editions;
    int choice;

    while (true) {
        cout << "1. Add new element\n2. Delete element by index\n3. Print all elements\n4. Compare two elements\n5. Exit\n";
        choice = getIntInput("Enter your choice: ");

        if (choice == 1) {
            int type = getIntInput("Enter type (1 - Magazine, 2 - Book, 3 - Textbook): ");
            int pages = getIntInput("Enter number of pages: ");
            string title = getStringInput("Enter title: ");

            if (type == 1) {
                editions.push_back(new Magazine(pages, title));
            } else if (type == 2) {
                editions.push_back(new Book(pages, title));
            } else if (type == 3) {
                editions.push_back(new Textbook(pages, title));
            }
        } else if (choice == 2) {
            int index = getIntInput("Enter index to delete: ");
            if (index >= 0 && index < editions.size()) {
                delete editions[index];
                editions.erase(editions.begin() + index);
            } else {
                cout << "Invalid index." << endl;
            }
        } else if (choice == 3) {
            for (size_t i = 0; i < editions.size(); ++i) {
                editions[i]->print();
            }
        } else if (choice == 4) {
            int index1 = getIntInput("Enter first index: ");
            int index2 = getIntInput("Enter second index: ");
            if (index1 >= 0 && index1 < editions.size() && index2 >= 0 && index2 < editions.size()) {
                if (*editions[index1] == *editions[index2]) {
                    cout << "Elements are equal." << endl;
                } else {
                    cout << "Elements are not equal." << endl;
                }
            } else {
                cout << "Invalid indices." << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    for (auto& edition : editions) {
        delete edition;
    }

    return 0;
}
