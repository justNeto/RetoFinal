#include "Movie.h"

Movie::Movie() {
    director = "default";
    year = 2000;
}

Movie::Movie(string director, string ID, string name, string genre, int duration, int year, vector <double> scores): Video(ID, name, genre, duration, scores) {
    this->director = director;
    this->year = year;
}

void Movie::print() {
    cout << "ID: " << this->getID();
    cout << "\nName: " << this->getName();
    cout << "\nDirected by: " << director;
    cout << "\nGenre: " << this->getGenre();
    cout << "\nYear: " << year;
    cout << "\nDuration: " << this->getDuration();
    cout << "\nScore: " << this->getScore() << endl;
}