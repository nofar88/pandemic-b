

#include "Medic.hpp"

pandemic::Player& pandemic::Medic::drive(pandemic::City city) {
    Player::drive(city);
    tryTreatTheCity();
    return *this;
}

pandemic::Player& pandemic::Medic::fly_direct(pandemic::City city) {
    Player::fly_direct(city);
    tryTreatTheCity();
    return *this;
}

pandemic::Player& pandemic::Medic::fly_charter(pandemic::City city) {
    Player::fly_charter(city);
    tryTreatTheCity();
    return *this;
}

pandemic::Player& pandemic::Medic::fly_shuttle(pandemic::City city) {
    Player::fly_shuttle(city);
    tryTreatTheCity();
    return *this;
}

pandemic::Player& pandemic::Medic::treat(pandemic::City city) {
    // If he has come this far it means that he has traveled some way and already checked if there is a cure
    if(board[currentCity] <= 0){
        throw std::invalid_argument("no more cubes remain in this city ");
    }
    board[currentCity] = 0;
    return *this;
}

void pandemic::Medic::tryTreatTheCity() {
    if(board.getCure(currentCity)){
        board[currentCity]=0;
    }
}

string pandemic::Medic::role() {
    return "Medic";
}
