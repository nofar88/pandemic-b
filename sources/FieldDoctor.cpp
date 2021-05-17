

#include "FieldDoctor.hpp"

pandemic::Player& pandemic::FieldDoctor::treat(pandemic::City city) {
    if(!board.neighboringCities(city,currentCity)){
        throw std::invalid_argument("not neighbors");
    }
    City temp = currentCity;
    currentCity = city;
    Player::treat(city);
    currentCity = temp;
    // We made him go back to the same city because in Trit he checks that they are where they want to be treated.
    return *this;
}

string pandemic::FieldDoctor::role() {
    return "FieldDoctor";
}
