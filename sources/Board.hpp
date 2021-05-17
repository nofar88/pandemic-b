

#ifndef DEMO1_CPP_BOARD_HPP
#define DEMO1_CPP_BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include <list>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic {
    class Board {
    private:
        map<City, list<City>> neighbors;
        map<City, Color> colors;
        map<City, int> cubes;
        map<Color, bool> cures;
        map<City, bool> researchStations;

    public:
        static map<City, string> strings;
        Board();
        int& operator[](City city);//If there was no & we could not both accept and change
        bool neighboringCities(City city1, City city2);
        bool getStation(City city);
        Color getColor(City city);
        void setStation(City city, bool station);
        void setCure(Color color);
        bool getCure(City city);
        bool getCure(Color color);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        friend ostream &operator<<(ostream &os, Board &board);
    };
}


#endif //DEMO1_CPP_BOARD_HPP
