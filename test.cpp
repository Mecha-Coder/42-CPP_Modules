#include <iostream>
#include <string>

class ClapTrap 
{
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        unsigned int getHit() {return hitPoints;}
        unsigned int getEnergy() {return energyPoints;}
        unsigned int getAttack() {return attackDamage;}
        std::string getName(){ return name;}

        // Constructor
        ClapTrap(const std::string& initName)
            : name(initName), hitPoints(10), energyPoints(10), attackDamage(0) {
            std::cout << "ClapTrap " << name << " constructed!" << std::endl;
        }

        // Destructor
        virtual ~ClapTrap() {
            std::cout << "ClapTrap " << name << " destructed!" << std::endl;
        }

        // Attack function
        virtual void attack(const std::string& target) {
            if (hitPoints == 0 || energyPoints == 0) {
                std::cout << "ClapTrap " << name << " cannot attack. No hit points or energy points left!" << std::endl;
                return;
            }
            energyPoints--;
            std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        }

        // Take damage function
        void takeDamage(unsigned int amount) {
            if (hitPoints <= amount) {
                hitPoints = 0;
                std::cout << "ClapTrap " << name << " took " << amount << " damage and is now destroyed!" << std::endl;
            } else {
                hitPoints -= amount;
                std::cout << "ClapTrap " << name << " took " << amount << " damage and has " << hitPoints << " hit points left!" << std::endl;
            }
        }

        // Repair function
        void beRepaired(unsigned int amount) {
            if (hitPoints == 0 || energyPoints == 0) {
                std::cout << "ClapTrap " << name << " cannot repair. No hit points or energy points left!" << std::endl;
                return;
            }
            energyPoints--;
            hitPoints += amount;
            std::cout << "ClapTrap " << name << " repaired itself, gaining " << amount << " hit points!" << std::endl;
        }
};

class ScavTrap : virtual public ClapTrap 
{
    public:
        // Constructor
        ScavTrap(const std::string& initName)
            : ClapTrap(initName) {
            hitPoints = 100;
            energyPoints = 50;
            attackDamage = 20;
            std::cout << "ScavTrap " << name << " constructed!" << std::endl;
        }

        // Destructor
        ~ScavTrap() {
            std::cout << "ScavTrap " << name << " destructed!" << std::endl;
        }

        // Overridden attack function
        void attack(const std::string& target) {
            if (hitPoints == 0 || energyPoints == 0) {
                std::cout << "ScavTrap " << name << " cannot attack. No hit points or energy points left!" << std::endl;
                return;
            }
            energyPoints--;
            std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        }

        // Special ability
        void guardGate() {
            std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
        }
};

class FragTrap : virtual public ClapTrap 
{
    public:
        // Constructor
        FragTrap(const std::string& initName)
            : ClapTrap(initName) {
            hitPoints = 100;
            energyPoints = 100;
            attackDamage = 30;
            std::cout << "FragTrap " << name << " constructed!" << std::endl;
        }

        // Destructor
        ~FragTrap() {
            std::cout << "FragTrap " << name << " destructed!" << std::endl;
        }

        // Special ability
        void highFivesGuys() {
            std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
        }
};

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;

public:
    // Constructor
    DiamondTrap(const std::string& initName)
        : ClapTrap(initName + "_clap_name"), FragTrap(initName), ScavTrap(initName), name(initName) {
        hitPoints = FragTrap::hitPoints;
        energyPoints = ScavTrap::energyPoints;
        attackDamage = FragTrap::attackDamage;
        std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
    }

    // Destructor
    ~DiamondTrap() {
        std::cout << "DiamondTrap " << name << " destructed!" << std::endl;
    }

    // Special ability
    void whoAmI() {
        std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
    }
};

int main() {

    DiamondTrap diamond("Diamond");

    std::cout << "\n-----------------------------------------------------\n";

    std::cout 
        << "\nHit   : " << diamond.getHit()
        << "\nEnergy: " << diamond.getEnergy()
        << "\nAttack: " << diamond.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";
    diamond.attack("enemy3");
    diamond.takeDamage(60);
    diamond.beRepaired(50);
    diamond.whoAmI();

    return 0;
}