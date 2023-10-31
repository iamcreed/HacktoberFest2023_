#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Character {
public:
    Character(const std::string& name, int health, int attack) : name(name), health(health), attack(attack) {}

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getAttack() const {
        return attack;
    }

    void displayStatus() const {
        std::cout << name << " - Health: " << health << " Attack: " << attack << std::endl;
    }

private:
    std::string name;
    int health;
    int attack;
};

class Monster {
public:
    Monster(const std::string& name, int health, int attack) : name(name), health(health), attack(attack) {}

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getAttack() const {
        return attack;
    }

    void displayStatus() const {
        std::cout << name << " - Health: " << health << " Attack: " << attack << std::endl;
    }

private:
    std::string name;
    int health;
    int attack;
};

void battle(Character& player, Monster& monster) {
    while (player.isAlive() && monster.isAlive()) {
        std::cout << "\n" << player.displayStatus();
        std::cout << monster.displayStatus();
        std::cout << "\nChoose your action:" << std::endl;
        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Run away" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int playerDamage = player.getAttack();
            int monsterDamage = monster.getAttack();

            monster.takeDamage(playerDamage);
            std::cout << "You hit " << monster.displayStatus() << " for " << playerDamage << " damage!" << std::endl;

            if (monster.isAlive()) {
                player.takeDamage(monsterDamage);
                std::cout << monster.displayStatus() << " hits you for " << monsterDamage << " damage!" << std::endl;
            }
        } else if (choice == 2) {
            std::cout << "You run away from the battle!" << std::endl;
            return;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    if (player.isAlive()) {
        std::cout << "You defeated " << monster.displayStatus() << "!" << std::endl;
    } else {
        std::cout << "Oh no, " << monster.displayStatus() << " defeated you! Game over." << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr));

    Character player("Hero", 100, 20);
    Monster monster("Dragon", 150, 25);

    std::cout << "Welcome to the Text-based RPG Battle!" << std::endl;
    std::cout << "You are facing a " << monster.displayStatus() << ". Can you defeat it?" << std::endl;

    battle(player, monster);

    return 0;
}
