

#include "Dispatcher.hpp"

pandemic::Player &pandemic::Dispatcher::fly_direct(pandemic::City city) {
    if (board.getStation(currentCity) && city != currentCity) {// A case where there is a research station and just make sure he is not flying from a city to himself
        currentCity = city;
        return *this;
    }
    return Player::fly_direct(city);

}

string pandemic::Dispatcher::role() {
    return "Dispatcher";
}
