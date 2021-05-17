

#include "Virologist.hpp"
#include <algorithm>

pandemic::Player& pandemic::Virologist::treat(pandemic::City city) {
    if (find(playingCards.begin(), playingCards.end(), city) == playingCards.end() && currentCity != city){
        throw std::invalid_argument("you dont have this card");
    }
    City temp = currentCity;
    currentCity = city;
    Player::treat(city);
    currentCity = temp;
    playingCards.remove(city);
    return *this;

}

string pandemic::Virologist::role() {
    return "Virologist";
}
