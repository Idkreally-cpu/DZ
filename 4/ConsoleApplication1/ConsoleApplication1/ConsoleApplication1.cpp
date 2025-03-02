#include <iostream>
#include <string>

class CombatUnit {
private:
    int health;
    int damage;
    std::string unitType;

    static int totalHealth;
    static int totalDamage;

public:
    CombatUnit(int h, int d, const std::string& type)
        : health(h), damage(d), unitType(type) {
        totalHealth += health;
        totalDamage += damage;
    }

    ~CombatUnit() {
        totalHealth -= health;
        totalDamage -= damage;
    }

    void setHealth(int h) {
        totalHealth -= health;
        health = h;
        totalHealth += health;
    }

    void setDamage(int d) {
        totalDamage -= damage;
        damage = d;
        totalDamage += damage;
    }

    int getHealth() const {
        return health;
    }

    int getDamage() const {
        return damage;
    }

    std::string getUnitType() const {
        return unitType;
    }

    static int getTotalHealth() {
        return totalHealth;
    }

    static int getTotalDamage() {
        return totalDamage;
    }
};

int CombatUnit::totalHealth = 0;
int CombatUnit::totalDamage = 0;

int main() {
    CombatUnit unit1(100, 20, "Warrior");
    CombatUnit unit2(150, 30, "Archer");

    std::cout << "Total Health: " << CombatUnit::getTotalHealth() << std::endl;
    std::cout << "Total Damage: " << CombatUnit::getTotalDamage() << std::endl;

    unit1.setHealth(120);
    unit2.setDamage(40);

    std::cout << "Total Health after change: " << CombatUnit::getTotalHealth() << std::endl;
    std::cout << "Total Damage after change: " << CombatUnit::getTotalDamage() << std::endl;

    return 0;
}