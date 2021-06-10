#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

class Video {
    private:
    // Attributes
    string ID, name, genre;
    int duration;
    vector <double> scores;

    double averageScore();
    
    public:
    // Constructors
    Video();
    Video(string ID, string name, string genre, int duration, vector <double> scores);

    // Accessors
    string getID();
    string getName();
    string getGenre();
    int getDuration();
    double getScore();

    // Modifiers
    void setID(string ID);
    void setName(string name);
    void setGenre(string genre);
    void setDuration(int duration);
    void setScores(vector <double> scores);
    
    void addScore(double score);
    void addScores(vector <double> scores);

    virtual void print();
};

#endif