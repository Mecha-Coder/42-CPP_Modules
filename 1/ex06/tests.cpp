#include <iostream>
#include <string>
#include <map>

enum Level { DEBUG, INFO, WARNING, ERROR };

class Harl {
private:
    void debug() {
        std::cout << "[ DEBUG ]" << std::endl;
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
    }

    void info() {
        std::cout << "[ INFO ]" << std::endl;
        std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
    }

    void warning() {
        std::cout << "[ WARNING ]" << std::endl;
        std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
    }

    void error() {
        std::cout << "[ ERROR ]" << std::endl;
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
    }

public:
    std::map<std::string, Level> levelMap = {
        {"DEBUG", DEBUG},
        {"INFO", INFO},
        {"WARNING", WARNING},
        {"ERROR", ERROR}
    };

    void complain(std::string level) {
        Level lvl;
        try {
            lvl = levelMap.at(level); 
        } catch (const std::out_of_range& e) {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            std::cout << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off." << std::endl;
            return;
        }

        switch (lvl) {
            case DEBUG: 
                debug();
                [[fallthrough]]; 
            case INFO: 
                info();
                [[fallthrough]]; 
            case WARNING: 
                warning();
                [[fallthrough]]; 
            case ERROR: 
                error();
                break;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(argv[1]);

    return 0;
}