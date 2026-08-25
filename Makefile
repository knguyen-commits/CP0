movies: main.cpp Movie.cpp MovieCollection.cpp FileManager.cpp Utilities.cpp
	g++ -std=c++17 -Wall -Wextra main.cpp Movie.cpp MovieCollection.cpp FileManager.cpp Utilities.cpp -o movies

clean:
	rm -f movies