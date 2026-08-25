#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

string toLower(string text)
{
    for (char& c : text)
        c = tolower(c);

    return text;
}

class Movie
{
private:
    string title;
    string genre;
    int year;
    double rating;

public:
    Movie()
    {
        title = "";
        genre = "";
        year = 0;
        rating = 0.0;
    }

    Movie(string t, string g, int y, double r)
    {
        title = t;
        genre = g;
        year = y;
        rating = r;
    }

    string getTitle() const
    {
        return title;
    }

    string getGenre() const
    {
        return genre;
    }

    int getYear() const
    {
        return year;
    }

    double getRating() const
    {
        return rating;
    }

    void display() const
    {
        cout << left
             << setw(30) << title
             << setw(15) << genre
             << setw(8) << year
             << fixed << setprecision(1)
             << rating << endl;
    }
};

class MovieCollection
{
private:
    vector<Movie> movies;

public:
    void addMovie(const Movie& movie)
    {
        movies.push_back(movie);
    }

    void displayAllMovies() const
    {
        if (movies.empty())
        {
            cout << "No movies found." << endl;
            return;
        }

        cout << left
             << setw(30) << "Title"
             << setw(15) << "Genre"
             << setw(8) << "Year"
             << "Rating" << endl;

        for (const Movie& movie : movies)
            movie.display();
    }

    void searchByTitle(string title) const
    {
        for (const Movie& movie : movies)
        {
            if (toLower(movie.getTitle()) == toLower(title))
            {
                movie.display();
                return;
            }
        }

        cout << "Movie not found." << endl;
    }

    void displayByGenre(string genre) const
    {
        bool found = false;

        for (const Movie& movie : movies)
        {
            if (toLower(movie.getGenre()) == toLower(genre))
            {
                movie.display();
                found = true;
            }
        }

        if (!found)
            cout << "No movies found." << endl;
    }

    double calculateAverageRating() const
    {
        if (movies.empty())
            return 0.0;

        double total = 0.0;

        for (const Movie& movie : movies)
            total += movie.getRating();

        return total / movies.size();
    }

    int getNumberOfMovies() const
    {
        return movies.size();
    }
};

class FileManager
{
public:
    static bool loadMovies(string filename, MovieCollection& collection)
    {
        ifstream inputFile(filename);

        if (!inputFile)
            return false;

        string line;

        while (getline(inputFile, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);

            string title;
            string genre;
            string yearString;
            string ratingString;

            getline(ss, title, ',');
            getline(ss, genre, ',');
            getline(ss, yearString, ',');
            getline(ss, ratingString);

            int year = stoi(yearString);
            double rating = stod(ratingString);

            Movie movie(title, genre, year, rating);
            collection.addMovie(movie);
        }

        inputFile.close();
        return true;
    }
};

void displayMenu()
{
    cout << "\n1. Display all movies" << endl;
    cout << "2. Search by title" << endl;
    cout << "3. Search by genre" << endl;
    cout << "4. Average rating" << endl;
    cout << "5. Number of movies" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";
}

int main()
{
    MovieCollection collection;

    if (!FileManager::loadMovies("movies.txt", collection))
    {
        cout << "Could not open movies.txt" << endl;
        return 1;
    }

    cout << collection.getNumberOfMovies()
         << " movies loaded." << endl;

    int choice;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            collection.displayAllMovies();
        }
        else if (choice == 2)
        {
            string title;

            cout << "Enter title: ";
            getline(cin, title);

            collection.searchByTitle(title);
        }
        else if (choice == 3)
        {
            string genre;

            cout << "Enter genre: ";
            getline(cin, genre);

            collection.displayByGenre(genre);
        }
        else if (choice == 4)
        {
            cout << "Average rating: "
                 << fixed << setprecision(2)
                 << collection.calculateAverageRating()
                 << endl;
        }
        else if (choice == 5)
        {
            cout << "Number of movies: "
                 << collection.getNumberOfMovies()
                 << endl;
        }
        else if (choice == 0)
        {
            cout << "Goodbye." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
