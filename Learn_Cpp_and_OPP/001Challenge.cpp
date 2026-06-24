#include <iostream>
#include <string>
#include <vector>

#define G		1
#define PG		2
#define PG_13	3
#define R		4

using namespace std;

class Movie
{
private:
	string name;
	int rating;
	int watched;
public:
	Movie(string movName, int movRating, int movWatch = 0) :name{ movName }, rating{ movRating }, watched{ movWatch } {}
	string getNameMovie() { return name; }
	int getRating() { return rating; }
	int getWatched() { return watched; }
	void incrementWatch() {
		watched++;
	}
};

class Movies
{
private:
	vector<Movie> collection;
public:
	Movies(vector<Movie>& vec) {
		int n = vec.size();
		for (size_t i = 0; i < n; i++)
		{
			collection.push_back(vec[i]);
		}
	}
	int checkMovie(Movie& m) {
		for (size_t i = 0; i < collection.size(); i++)
		{
			if (m.getNameMovie() == collection[i].getNameMovie())
			{
				return i;
			}
		}
		return -1;
	}

	void addMovie(Movie& m) {
		if (checkMovie(m)==-1)
		{
			collection.push_back(m);
		}
		else
		{
			cout << "Movie's name have been added already!" << endl;
		}
	}

	void updateWatch(Movie& m) {
		if (checkMovie(m)==-1)
		{
			cout << "Eror! Movie is not found" << endl; 
		}
		else
		{
			m.incrementWatch();
			collection.at(checkMovie(m)).incrementWatch();
		}
	}

	void displayRoPhim() {
		for (auto n : collection) {
			cout << n.getNameMovie() << "       |      " << n.getRating() << "      |      " << n.getWatched() << endl;
		}
		cout << endl;
	}
};

int main() {
	vector<Movie> SystemMovies;
	Movie f1("See you again 1", G, 10);
	Movie f2("See you again 2", R, 0);
	Movie f3("See you again 3", PG, 5);
	Movie f4("See you again 4", PG_13, 56);
	SystemMovies.push_back(f1);
	SystemMovies.push_back(f2);
	SystemMovies.push_back(f3);
	SystemMovies.push_back(f4);

	Movies RoPhim(SystemMovies);

	Movie f5("See you again 5", PG_13, 100);
	RoPhim.addMovie(f5);

	Movie f6("See you again 3", PG_13, 100);
	//RoPhim.addMovie(f6);
	RoPhim.updateWatch(f1);
	RoPhim.displayRoPhim();

	return 0;
}