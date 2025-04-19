#include <iostream>
#include <string>

class Blacksmith {
public:
    virtual void forgeWeapon() = 0;
    virtual ~Blacksmith() {}
};

class ElfBlacksmith : public Blacksmith {
public:
    void forgeWeapon() override {
        std::cout << "Elven sword forged\n";
    }
};

class OrcBlacksmith : public Blacksmith {
public:
    void forgeWeapon() override {
        std::cout << "Orcish axe forged\n";
    }
};

class BlacksmithFactory {
public:
    static Blacksmith* createBlacksmith(const std::string& type) {
        if (type == "elf") return new ElfBlacksmith();
        if (type == "orc") return new OrcBlacksmith();
        return nullptr;
    }
};

int main() {
    Blacksmith* elfSmith = BlacksmithFactory::createBlacksmith("elf");
    Blacksmith* orcSmith = BlacksmithFactory::createBlacksmith("orc");
    
    elfSmith->forgeWeapon();
    orcSmith->forgeWeapon();
    
    delete elfSmith;
    delete orcSmith;
}

#include <iostream>
#include <string>

class Government {
private:
    static Government* instance;
    Government() {}
    
public:
    static Government* getInstance() {
        if (!instance) {
            instance = new Government();
        }
        return instance;
    }
    
    void govern() {
        std::cout << "Governing the country\n";
    }
    
    Government(const Government&) = delete;
    void operator=(const Government&) = delete;
};

Government* Government::instance = nullptr;

int main() {
    Government* gov = Government::getInstance();
    gov->govern();
}
