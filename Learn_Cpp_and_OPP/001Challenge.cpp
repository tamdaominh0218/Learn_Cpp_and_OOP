#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Rating
{
	G, PG, PG_13, R
};

const char* convertRating(Rating ra) {
	switch (ra)
	{
	case Rating::G:
		return "G";
	case Rating::PG:
		return "PG";
	case Rating::PG_13:
		return "PG_13";
	case Rating::R:
		return "R";
	default:
		return "Unknow";
	}
}

class Movie
{
private:
	string name;
	Rating rating;
	int watched;
public:
	Movie(string movName, Rating movRating, int movWatch = 0) :name{ movName }, rating{ movRating }, watched{ movWatch } {}
	string getNameMovie() const{ return name; }
	Rating getRating() const { return rating; }
	int getWatched() const { return watched; }
	void incrementWatch() {
		watched++;
	}
};

class Movies
{
private:
	vector<Movie> collection;
public:
	Movies() {}

	void addMovie(const Movie& m) {
		for (Movie& mov : collection)
		{
			if (mov.getNameMovie() == m.getNameMovie())
			{
				cout << "Movie's name have been added already!" << endl;
				return;
			}
		}
		collection.push_back(m);
	}

	void updateWatch(const Movie& m) {
		for (Movie&mov:collection)
		{
			if (mov.getNameMovie() == m.getNameMovie())
			{
				mov.incrementWatch();
				return;
			}
		}
		cout << "Eror! Movie is not found" << endl;
	}

	void displayRoPhim() {
		for (auto n : collection) {
			cout << n.getNameMovie() << "       |      " << convertRating(n.getRating()) << "      |      " << n.getWatched() << endl;
		}
		cout << endl;
	}
};

int main() {

	Movies RoPhim;
	RoPhim.addMovie(Movie("See you again 1", Rating::G, 10));
	RoPhim.addMovie(Movie("See you again 2", Rating::PG_13, 34));
	RoPhim.addMovie(Movie("See you again 3", Rating::R, 5));
	RoPhim.addMovie(Movie("See you again 4", Rating::PG, 7));
	RoPhim.displayRoPhim();

	RoPhim.updateWatch(Movie("See you again 3", Rating::G, 10));
	RoPhim.displayRoPhim();

	return 0;
}