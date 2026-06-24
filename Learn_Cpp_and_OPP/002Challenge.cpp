#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum class Rating
{
    G,
    PG,
    PG_13,
    R
};

const char* ratingToString(Rating rating)
{
    switch (rating)
    {
    case Rating::G:
        return "G";

    case Rating::PG:
        return "PG";

    case Rating::PG_13:
        return "PG-13";

    case Rating::R:
        return "R";
    }

    return "Unknown";
}

class Movie
{
private:
    std::string name;
    Rating rating;
    int watched;

public:
    Movie(std::string movieName,
        Rating movieRating,
        int watchCount = 0)
        : name{ std::move(movieName) },
        rating{ movieRating },
        watched{ watchCount }
    {
    }

    const std::string& getName() const
    {
        return name;
    }

    Rating getRating() const
    {
        return rating;
    }

    int getWatched() const
    {
        return watched;
    }

    void incrementWatched()
    {
        ++watched;
    }
};

class Movies
{
private:
    std::vector<Movie> collection;

    Movie* findMovie(const std::string& movieName)
    {
        for (Movie& movie : collection)
        {
            if (movie.getName() == movieName)
            {
                return &movie;
            }
        }

        return nullptr;
    }

public:
    bool addMovie(const Movie& movie)
    {
        if (findMovie(movie.getName()) != nullptr)
        {
            std::cout << "Movie already exists: "
                << movie.getName() << '\n';

            return false;
        }

        collection.push_back(movie);
        return true;
    }

    bool incrementWatched(const std::string& movieName)
    {
        Movie* movie = findMovie(movieName);

        if (movie == nullptr)
        {
            std::cout << "Movie not found: "
                << movieName << '\n';

            return false;
        }

        movie->incrementWatched();
        return true;
    }

    void display() const
    {
        if (collection.empty())
        {
            std::cout << "No movies in the collection.\n";
            return;
        }

        for (const Movie& movie : collection)
        {
            std::cout
                << movie.getName()
                << " | "
                << ratingToString(movie.getRating())
                << " | watched: "
                << movie.getWatched()
                << '\n';
        }
    }
};

int main()
{
    Movies movies;

    movies.addMovie(
        Movie{ "See you again 1", Rating::G, 10 }
    );

    movies.addMovie(
        Movie{ "See you again 2", Rating::R }
    );

    movies.addMovie(
        Movie{ "See you again 3", Rating::PG, 5 }
    );

    movies.addMovie(
        Movie{ "See you again 4", Rating::PG_13, 56 }
    );

    movies.addMovie(
        Movie{ "See you again 5", Rating::PG_13, 100 }
    );

    // Thử thêm phim bị trùng tên
    movies.addMovie(
        Movie{ "See you again 3", Rating::R, 999 }
    );

    movies.incrementWatched("See you again 1");

    // Thử cập nhật phim không tồn tại
    movies.incrementWatched("Unknown movie");

    movies.display();

    return 0;
}