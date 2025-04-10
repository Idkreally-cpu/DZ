#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Student {
public:
    virtual ~Student() = default;
    virtual void reactToDismissal() = 0;
    virtual std::string getName() const = 0;
};

class FastStudent : public Student {
public:
    FastStudent(const std::string& name) : name(name) {}
    
    void reactToDismissal() override {
        std::cout << name << ": Быстро собирает вещи и убегает\n";
    }
    
    std::string getName() const override { return name; }

private:
    std::string name;
};

class OrganizedStudent : public Student {
public:
    OrganizedStudent(const std::string& name) : name(name) {}
    
    void reactToDismissal() override {
        std::cout << name << ": Аккуратно складывает тетради, выключает компьютер\n";
    }
    
    std::string getName() const override { return name; }

private:
    std::string name;
};

class LazyStudent : public Student {
public:
    LazyStudent(const std::string& name) : name(name) {}
    
    void reactToDismissal() override {
        std::cout << name << ": 'Уже??' Медленно начинает собираться\n";
    }
    
    std::string getName() const override { return name; }

private:
    std::string name;
};

class Teacher {
public:
    void addStudent(Student* student) {
        students.push_back(student);
    }
    
    void removeStudent(const std::string& name) {
        students.erase(
            std::remove_if(students.begin(), students.end(),
                [&name](Student* s) { return s->getName() == name; }),
            students.end());
    }
    
    void wrapUp() {
        std::cout << "Преподаватель: Можете собираться и идти домой!\n";
        notifyStudents();
    }

private:
    void notifyStudents() {
        for (auto student : students) {
            student->reactToDismissal();
        }
    }

    std::vector<Student*> students;
};

int main() {
    Teacher teacher;
    
    FastStudent fastStudent1("Иван");
    FastStudent fastStudent2("Ольга");
    OrganizedStudent organizedStudent("Алексей");
    LazyStudent lazyStudent("Дмитрий");
    
    teacher.addStudent(&fastStudent1);
    teacher.addStudent(&fastStudent2);
    teacher.addStudent(&organizedStudent);
    teacher.addStudent(&lazyStudent);
    
    teacher.wrapUp();
    
    teacher.removeStudent("Ольга");
    
    std::cout << "\nПосле ухода Ольги:\n";
    teacher.wrapUp();
    
    return 0;
}
