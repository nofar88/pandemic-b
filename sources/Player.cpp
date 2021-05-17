


#include "Player.hpp"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace pandemic;

const unsigned int FIVE = 5;


pandemic::Player &pandemic::Player::fly_direct(pandemic::City city) {
    if (city == currentCity) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (find(playingCards.begin(), playingCards.end(), city) == playingCards.end()) {
        throw std::invalid_argument("you do not have the card of the city");
    }
    playingCards.remove(city);
    currentCity = city;

    return *this;
}

pandemic::Player &pandemic::Player::drive(pandemic::City city) {
    if (city == currentCity) {
        throw std::invalid_argument("cannot drive from city to it self");
    }
    if (!board.neighboringCities(city, currentCity)) {
        throw std::invalid_argument("the cards is not connected");
    }
    currentCity = city;
    return *this;
}

pandemic::Player &pandemic::Player::fly_charter(pandemic::City city) {
    if (city == currentCity) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (find(playingCards.begin(), playingCards.end(), currentCity) == playingCards.end()) {
        throw std::invalid_argument("you do not have the card of this city");
    }
    playingCards.remove(currentCity);
    currentCity = city;
    return *this;
}

pandemic::Player &pandemic::Player::fly_shuttle(pandemic::City city) {
    if (city == currentCity) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (!board.getStation(currentCity) || !board.getStation(city)) {
        throw std::invalid_argument("there is no research station");
    }
    currentCity = city;
    return *this;
}

pandemic::Player &pandemic::Player::build() {
    if (find(playingCards.begin(), playingCards.end(), currentCity) == playingCards.end()) {
        throw std::invalid_argument("you dont have the card of of this city");
    }
    playingCards.remove(currentCity);
    board.setStation(currentCity, true);
    return *this;
}

pandemic::Player &Player::discover_cure(Color color, int n, bool ignoreStation, bool ignoreColor) {
    if (!ignoreStation && !board.getStation(currentCity)) {
        throw std::invalid_argument("there is no research ignoreStation in this city ");
    }

    vector <City> cards;
    for (auto card: playingCards) {
        if (ignoreColor || board.getColor(card) == color) {
            cards.push_back(card);
        }
    }
    if (cards.size() < n) {// In case we do not have enough cards, check only if they have already discovered a cure because their age just goes out otherwise throws an error
        if (board.getCure(color)) {
            return *this;
        }
        throw std::invalid_argument(
                "you dont have enough cards, you only have only " + to_string(cards.size()));



    }
    for (unsigned int i = 0; i < n; ++i) {
        playingCards.remove(cards[i]);
    }
    board.setCure(color);

    return *this;
}

pandemic::Player &pandemic::Player::discover_cure(pandemic::Color color) {
    return discover_cure(color, FIVE, false, false);
}

pandemic::Player &pandemic::Player::treat(pandemic::City city) {
    if (city != currentCity) {
        throw std::invalid_argument("you are not in this city ");
    }
    if (board[currentCity] <= 0) {
        throw std::invalid_argument("no more cubes remain in this city ");
    }
    if (board.getCure(currentCity)) {
        board[currentCity] = 0;
    } else {
        board[currentCity]--;
    }
    return *this;
}

pandemic::Player &pandemic::Player::take_card(pandemic::City city) {
    if (find(playingCards.begin(), playingCards.end(), city) == playingCards.end()) {
        playingCards.push_front(city);
    }
    return *this;
}

string Player::role() {
    return "";
}

Player::Player(Board &board, City city) : board(board), currentCity(city) {
}


pandemic::Player &pandemic::Player::remove_cards() {
    playingCards.clear();
    return *this;

}


