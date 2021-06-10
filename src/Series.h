#ifndef SERIES_H_INCLUDED
#define SERIES_H_INCLUDED
#include <vector>
#include <iostream>
#include "Season.h"

using namespace std;

class Series {
    private:
        vector <Season> seasons;
        string name;
        bool onAir;

    public:
        Series();
        Series(string name, vector<Season> seasons, bool onAir);

        double getScore();
        string getName();
        int getNumSeasons();
        void print();
};

#endif