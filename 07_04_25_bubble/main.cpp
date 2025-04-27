#include <iostream>
#include <fstream>
#include <sstream>

struct Player {
    std::string surname;
    int points = 0;
    int balance = 0;
};

void print_players(Player players[], const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << players[i].surname << " " << players[i].points << " " << players[i].balance << std::endl;
    }
}

void bubble_sort(Player players[], const int size) {
    for (int i = 0; i < size; i++) {
        bool flag = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (players[j].points < players[j + 1].points) {
                std::swap(players[j], players[j + 1]);
                flag = true;
            } else if (players[j].points == players[j + 1].points) {
                if (players[j].balance < players[j + 1].balance) {
                    std::swap(players[j], players[j + 1]);
                    flag = true;
                }
            }
        }
        if (flag == false) {
            print_players(players, size);
            return;
        }
    }
}

int main() {
    std::ifstream file("tournament.txt");
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    Player *players;

    std::string line;
    int numPlayers = 0;
    int lineCount = 0;
    while (std::getline(file, line)) {
        if (lineCount == 0) {
            numPlayers = std::stoi(line);
            players = new Player[numPlayers];
            lineCount++;
        }
        else {
            std::istringstream iss(line);
            int arrIndex = lineCount - 1;
            iss >> players[arrIndex].surname >> players[arrIndex].points >> players[arrIndex].balance;
            lineCount++;
        }
    }
    bubble_sort(players, numPlayers);

    file.close();
    return 0;
}