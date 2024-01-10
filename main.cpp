#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void printDayOfWeek(int dayOfWeek) {
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "Today is " << daysOfWeek[dayOfWeek] << endl;
    return 1;
}

int cmd_up() {
    std::cout << "printName1" << std::endl;
    return 1;
}

int cmd_down() {
    std::cout << "printName2" << std::endl;
    return 2;
}

int cmd_left() {
    std::cout << "printName3" << std::endl;
    return 3;
}

int cmd_right() {
    std::cout << "printName3" << std::endl;
    return 4;
}

int main() {
    string command;
    tm *ltm = localtime(&now);
    int dayOfWeek= ltm->tm_wday;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Welcome to collector-1, we recommend to keep documentation handy \n
    or to know the main commands from the 9999 different commands \nfrom this system: " << dt << endl;
    while (true) {
        cout << "Enter a command: ";
        cin >> command;
        if (command == "exit") {
            break;
        } else {
            for (char& c : command) {
                switch (c) {
                    case 'up':
                        cmd_up();
                    break;
                    case 'down':
                        cmd_down();
                    break;
                    case 'left':
                        cmd_left();
                    break;
                    case 'right':
                        cmd_right();
                    break;
                    case 'day':
                        printDayOfWeek(dayOfWeek);
                    break;
                    default:
                        std::cout <<"'"<< command << "' is not a known command, you idiot." << std::endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}