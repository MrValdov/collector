#include <iostream>
#include <map>
#include <ctime>
#include <string>

using namespace std;

void printDayOfWeek(int dayOfWeek) {
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "Today is " << daysOfWeek[dayOfWeek] << endl;
}

void cmd_up() {
    std::cout << "printName1" << std::endl;
}

void cmd_down() {
    std::cout << "printName2" << std::endl;
}

void cmd_left() {
    std::cout << "printName3" << std::endl;
}

void cmd_right() {
    std::cout << "printName3" << std::endl;
}

int main() {
    string command;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int dayOfWeek= ltm->tm_wday;
    char* dt = ctime(&now);
    map<string, void(*)()> function_map = {{"up", &cmd_up}, {"down", &cmd_down},
        {"left", &cmd_left}, {"right", &cmd_right},
        //{"day", &printDayOfWeek},
        };
    string matrix[3][3] = {{"up", "down", "right"},
                           {"left", "print", "fig"},
                           {"grape", "honeydew", "kiwi"}};    
    cout << "Welcome to collector-1, we recommend to keep documentation handy \n or to know the main commands from the 9999 different commands \nfrom this system: " << dt << endl;
    while (true) {
        a:
        bool found = false;
        cout << "Enter a command: ";
        cin >> command;
        if (command == "exit") {
            break;
        } 
        for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == command) {
                found = true;
                auto it = function_map.find(command);
                if (it != function_map.end()) {
                    it->second();
                }else {
                    goto a;
                }
            }
        }
        }
        if (!found) {
        std::cout <<"'"<< command << "' is not a known command, you idiot." << std::endl;
        goto a;
        }
           
    }
    return 0;
}