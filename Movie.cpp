#include "Movie.h"
#include <iostream>
#include <iomanip>

using namespace std;

Movie::Movie()
{
    title = "";
    genre = "";
    year = 0;
    rating = 0.0;
}

Movie::Movie(string t, string g, int y, double r)
{
    title = t;
    genre = g;
    year = y;
    rating = r;
}

string Movie::getTitle() const
{
    return title;
}

string Movie::getGenre() const
{
    return genre;
}

int Movie::getYear() const
{
    return year;
}

double Movie::getRating() const
{
    return rating;
}

void Movie::display() const
{
    cout << left
         << setw(30) << title
         << setw(15) << genre
         << setw(8) << year
         << fixed << setprecision(1)
         << rating << endl;
}
