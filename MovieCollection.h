#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H


#include <vector>
#include "Movie.h" 

using namespace std; 

class MovieCollection
{
  private:
	vector<Movie> movies;

  public:
	void addMovie(const Movie& movie); 
	void displayAllMovies() const; 
	void SearchByTitle(string title) const; 
	void displayByGenre(string genre) const; 
	double calculateAverageRating() const; 
	int getNumberofMobies() const; 
};

#endif

