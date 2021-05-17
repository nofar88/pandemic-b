
#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;
using namespace pandemic;

map <City, string> Board::strings;

vector <string> split(const string &s, char delim) {
    vector <string> elems;
    stringstream ss(s);//go over the string
    string unit;
    while (getline(ss, unit, delim)) {
        elems.push_back(unit);
    }
    return elems;
}

namespace pandemic {
    const unsigned int SIX= 6;
    const unsigned int FORTYEIGHT = 48;

    ostream &operator<<(ostream &os, Board &board) {
        cout << "| City\t\t | Cubes\t | Cure\t\t | Stations |" << endl;
        cout << "========================================================" << endl;
        for (int i = 0; i < FORTYEIGHT; i++) {
            City city = (City) i;
            cout << "| " << Board::strings[city] << "\t";
            if (Board::strings[city].size() < SIX) {
                cout << "\t";
            }
            cout << " | " << board.cubes[city] << "\t\t | ";
            if (board.cures[board.getColor(city)]) {
                cout << "yes";
            } else {
                cout << "no";
            }
            cout << "\t\t | " << board.researchStations[city] << "\t | " << endl;
        }
        return os;
    }
}




bool Board::is_clean() {
    for (auto it1: cubes) {
        if (it1.second != 0) {
            return false;
        }
    }
    return true;
}

int &Board::operator[](pandemic::City city) {
    return cubes[city];
}

//Boot the whole game board.
Board::Board() {
    strings[City::Algiers] = "Algiers";
    strings[City::Atlanta] = "Atlanta";
    strings[City::Baghdad] = "Baghdad";
    strings[City::Bangkok] = "Bangkok";
    strings[City::Beijing] = "Beijing";
    strings[City::Bogota] = "Bogota";
    strings[City::BuenosAires] = "BuenosAires";
    strings[City::Cairo] = "Cairo";
    strings[City::Chennai] = "Chennai";
    strings[City::Chicago] = "Chicago";
    strings[City::Delhi] = "Delhi";
    strings[City::Essen] = "Essen";
    strings[City::HoChiMinhCity] = "HoChiMinhCity";
    strings[City::HongKong] = "HongKong";
    strings[City::Istanbul] = "Istanbul";
    strings[City::Jakarta] = "Jakarta";
    strings[City::Johannesburg] = "Johannesburg";
    strings[City::Karachi] = "Karachi";
    strings[City::Khartoum] = "Khartoum";
    strings[City::Kinshasa] = "Kinshasa";
    strings[City::Kolkata] = "Kolkata";
    strings[City::Lagos] = "Lagos";
    strings[City::Lima] = "Lima";
    strings[City::London] = "London";
    strings[City::LosAngeles] = "LosAngeles";
    strings[City::Madrid] = "Madrid";
    strings[City::Manila] = "Manila";
    strings[City::MexicoCity] = "MexicoCity";
    strings[City::Miami] = "Miami";
    strings[City::Milan] = "Milan";
    strings[City::Montreal] = "Montreal";
    strings[City::Moscow] = "Moscow";
    strings[City::Mumbai] = "Mumbai";
    strings[City::NewYork] = "NewYork";
    strings[City::Osaka] = "Osaka";
    strings[City::Paris] = "Paris";
    strings[City::Riyadh] = "Riyadh";
    strings[City::SanFrancisco] = "SanFrancisco";
    strings[City::Santiago] = "Santiago";
    strings[City::SaoPaulo] = "SaoPaulo";
    strings[City::Seoul] = "Seoul";
    strings[City::Shanghai] = "Shanghai";
    strings[City::StPetersburg] = "StPetersburg";
    strings[City::Sydney] = "Sydney";
    strings[City::Taipei] = "Taipei";
    strings[City::Tehran] = "Tehran";
    strings[City::Tokyo] = "Tokyo";
    strings[City::Washington] = "Washington";

    map <string, Color> colorMap;
    colorMap["Black"] = Color::Black;
    colorMap["Red"] = Color::Red;
    colorMap["Yellow"] = Color::Yellow;
    colorMap["Blue"] = Color::Blue;

    map <string, City> reversed;
    for (auto const &it : strings) {
        reversed[it.second] = it.first;
    }

    string line;
    ifstream path{"cities_map.txt"};
    while (getline(path, line)) {
        vector <string> neighbor = split(line, ' ');
        City city = reversed[neighbor[0]];

        colors[city] = colorMap[neighbor[1]];

        list <City> cities;
        for (unsigned int i = 2; i < neighbor.size(); ++i) {
            cities.push_back(reversed[neighbor[i]]);
        }
        neighbors[city] = cities;

        cubes[city] = 0;
        researchStations[city] = false;
    }

    remove_cures();
}

bool Board::neighboringCities(pandemic::City city1, pandemic::City city2) {
    return find(neighbors[city1].begin(), neighbors[city1].end(), city2) != neighbors[city1].end() ||
           city1 == city2;
    // Checking a city that is a neighbor of its own because there is a field doctor player that he can cure in any neighboring city so I also referred to the case of a city that is a neighbor to itself
}

bool Board::getStation(pandemic::City city) {
    return researchStations[city];
}

void Board::setStation(pandemic::City city, bool station) {
    researchStations[city] = station;
}

pandemic::Color Board::getColor(pandemic::City city) {
    return colors[city];
}

void Board::setCure(pandemic::Color color) {
    cures[color] = true;
}

bool Board::getCure(pandemic::City city) {
    return cures[colors[city]];
}
bool Board::getCure(pandemic::Color color) {
    return cures[color];
}

void Board::remove_cures() {
    for (auto it : cures) {
        cures[it.first] = false;
    }
}

void Board::remove_stations() {
    for (auto it : researchStations) {
        researchStations[it.first] = false;
    }
}

