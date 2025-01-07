#include <iostream>
#include <string>
#include <map>

class Harl {
private:
    void debug() {
        std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    }

    void info() {
        std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    }

    void warning() {
        std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    }

    void error() {
        std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
    }

public:
    void complain(const std::string& level) {
        // Map of function pointers
        std::map<std::string, void (Harl::*)()> actions;
        actions["DEBUG"] = &Harl::debug;
        actions["INFO"] = &Harl::info;
        actions["WARNING"] = &Harl::warning;
        actions["ERROR"] = &Harl::error;

        std::map<std::string, void (Harl::*)()>::iterator it = actions.find(level);
        if (it != actions.end()) {
            (this->*(it->second))();
        } else {
            std::cout << "[UNKNOWN] Level not recognized." << std::endl;
        }
    }
};

int main() {
    Harl harl;

    std::cout << "Testing Harl's complaints at different levels:" << std::endl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "Testing with an unknown level:" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
