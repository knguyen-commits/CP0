
movies: main.cpp Movie.cpp
	g++ -std=c++17 -Wall -Wextra main.cpp Movie.cpp -o movies

clean:
	rm -f movies
