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
        Season(int seasonNum, bool onAir);
        Season(vector<Episode> season, bool onAir, int seasonNum);

        void addEpisode(Episode episode);
        double getScore();
        int getSeasonSize();
        void print();
};

#endif
