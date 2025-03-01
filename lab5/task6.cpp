#include <iostream>
using namespace std;

class levels {
    string name;
    int difficulty;
public:
    levels() {}  
    levels(string name, int difficulty) {
        this->name = name;
        this->difficulty = difficulty;
    }
    void display() {
        cout << "   Level Name: " << name << endl;
        cout << "   Difficulty: " << difficulty << endl;
    }
};

class Game {
    string title, genre;
    levels** in_levels;
    int levels_count, max_levels;
public:
    Game(string title, string genre, int nol) {
        this->title = title;
        this->genre = genre;
        max_levels = nol;
        levels_count = 0;
        in_levels = new levels*[max_levels];
    }
    void set_levels(string name, int difficulty) {
        if (levels_count < max_levels) {
            in_levels[levels_count] = new levels(name, difficulty);
            levels_count++;
        } else cout << "Max levels reached!" << endl;
    }
    void display() {
        cout << "Game Title: " << title << endl << "Genre: " << genre << endl << "Levels:" << endl;
        for (int i = 0; i < levels_count; i++) in_levels[i]->display();
    }
    ~Game() {
        for (int i = 0; i < levels_count; i++) delete in_levels[i];
        delete[] in_levels;
    }
};

int main() {
    Game g1("GTA V", "Action", 5);
    g1.set_levels("Level 1", 1);
    g1.set_levels("Level 2", 2);
    g1.set_levels("Level 3", 3);
    g1.set_levels("Level 4", 4);
    g1.set_levels("Level 5", 5);
    g1.display();
    return 0;
}
