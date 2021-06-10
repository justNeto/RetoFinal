#include "Series.h"

Series::Series() {
    seasons = vector <Season> {};
    onAir = false;
}

Series::Series(string name, vector<Season> seasons, bool onAir) {
    this->name = name;
    this->seasons = seasons;
    this->onAir = onAir;
}

double Series::getScore() {
    double sum = 0;
    int num = 0;
    for (Season i : seasons) {
        sum += i.getScore();
        num++;
    }
    return sum/num;
}

int Series::getNumSeasons() {
    return seasons.size();
}

string Series::getName() {
    return name;
}

void Series::print() {
    cout << "Name: " << this->name;
    cout << "\nSeasons: " << this->getNumSeasons();
    cout << "\nScore: " << this->getScore() << endl;
}