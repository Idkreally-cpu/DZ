#include <iostream>

class BaseEnemy {
public:
    virtual void DoDamage() = 0;
    virtual void Die() = 0;
    virtual void ChasePlayer() = 0;
    virtual ~BaseEnemy() {}
};

class Zombie : public BaseEnemy {
public:
    void DoDamage() override {
        std::cout << "Zombie bites player!" << std::endl;
    }

    void Die() override {
        std::cout << "Zombie falls to the ground!" << std::endl;
    }

    void ChasePlayer() override {
        std::cout << "Zombie slowly follows the player!" << std::endl;
    }
};

class Skeleton : public BaseEnemy {
public:
    void DoDamage() override {
        std::cout << "Skeleton shoots an arrow!" << std::endl;
    }

    void Die() override {
        std::cout << "Skeleton crumbles into bones!" << std::endl;
    }

    void ChasePlayer() override {
        std::cout << "Skeleton runs after the player!" << std::endl;
    }
};

int main() {
    BaseEnemy* enemy1 = new Zombie();
    BaseEnemy* enemy2 = new Skeleton();

    enemy1->ChasePlayer();
    enemy1->DoDamage();
    enemy1->Die();

    enemy2->ChasePlayer();
    enemy2->DoDamage();
    enemy2->Die();

    delete enemy1;
    delete enemy2;

    return 0;
}