#include "Episode.h"

Episode::Episode() {
}

Episode::Episode(string rate, string ID, string name, string genre, int duration, vector <double> scores): Video(ID, name, genre, duration, scores) {
    this->rate = rate;
}

void Episode::print() {
    cout << "ID: " << this->getID();
    cout << "\nName: " << this->getName();
    cout << "\nGenre: " << this->getGenre();
    cout << "\nDuration: " << this->getDuration();
    cout << "\nScore: " << this->getScore();
    cout << "\nRate: " << rate << endl;
}
