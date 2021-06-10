#ifndef SEASON_H_INCLUDED
#define SEASON_H_INCLUDED

#include <iostream>
#include <vector>
#include "Episode.h"
using namespace std;

class Season {
    private:
      vector<Episode> season;
      int seasonNum;

    public:
        bool onAir;
        Season();
        Season(vector<Episode> season, boolean onAir);

        double getScore();
        int getSeasonSize();
        void print();
};

#endif
