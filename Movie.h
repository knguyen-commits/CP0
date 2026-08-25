#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie
{
private:
    string title;
    string genre;
    int year;
    double rating;

public:
    Movie();
    Movie(string t, string g, int y, double r);

    string getTitle() const;
    string getGenre() const;
    int getYear() const;
    double getRating() const;

    void display() const;
};

#endif
