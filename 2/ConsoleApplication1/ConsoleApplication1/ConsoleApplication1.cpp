#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Task {
private:
    std::string description;
    bool completed;

public:
    Task(const std::string& desc) : description(desc), completed(false) {}

    void complete() { completed = true; }
    bool isCompleted() const { return completed; }
    std::string getDescription() const { return description; }
};

class TaskRepository {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task) { tasks.push_back(task); }
    const std::vector<Task>& getAllTasks() const { return tasks; }
};

class TaskPrinter {
public:
    virtual void print(const std::vector<Task>& tasks) const = 0;
    virtual ~TaskPrinter() = default;
};

class ConsoleTaskPrinter : public TaskPrinter {
public:
    void print(const std::vector<Task>& tasks) const override {
        std::cout << "Tasks List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << (i + 1) << ". " << tasks[i].getDescription() 
                      << " [" << (tasks[i].isCompleted() ? "X" : " ") << "]\n";
        }
    }
};

class SimpleTaskPrinter : public TaskPrinter {
public:
    void print(const std::vector<Task>& tasks) const override {
        for (const auto& task : tasks) {
            std::cout << "- " << task.getDescription() << "\n";
        }
    }
};

class TaskManager {
private:
    TaskRepository repository;
    std::unique_ptr<TaskPrinter> printer;

public:
    TaskManager(std::unique_ptr<TaskPrinter> printer) 
        : printer(std::move(printer)) {}

    void addTask(const std::string& description) {
        repository.addTask(Task(description));
    }

    void completeTask(size_t index) {
        auto& tasks = const_cast<std::vector<Task>&>(repository.getAllTasks());
        if (index < tasks.size()) {
            tasks[index].complete();
        }
    }

    void printTasks() const {
        printer->print(repository.getAllTasks());
    }
};

int main() {
    auto consolePrinter = std::make_unique<ConsoleTaskPrinter>();
    TaskManager manager(std::move(consolePrinter));

    manager.addTask("Learn C++");
    manager.addTask("Understand SOLID principles");
    manager.addTask("Write clean code");

    manager.completeTask(1);
    manager.printTasks();

    auto simplePrinter = std::make_unique<SimpleTaskPrinter>();
    TaskManager simpleManager(std::move(simplePrinter));
    
    simpleManager.addTask("Simple task 1");
    simpleManager.addTask("Simple task 2");
    simpleManager.printTasks();

    return 0;
}
