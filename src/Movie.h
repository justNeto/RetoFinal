#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <iostream>
#include <vector>
#include "Video.h"
using namespace std;

class Movie: public Video {
    private:
        string director;
        int year;

    public:
        Movie();
        Movie(string director, string ID, string name, string genre, int duration, int year, vector <double> scores);

        void print();
};

#endif