#ifndef EPISODE_H_INCLUDED
#define EPISODE_H_INCLUDED

#include <iostream>
#include "Video.h"

using namespace std;

class Episode : public Video {
private:
    string rate;

public:
    Episode();
    Episode(string rate, string ID, string name, string genre, int duration, vector <double> scores);

    void print();
};

#endif
