

#include "OperationsExpert.hpp"

pandemic::Player& pandemic::OperationsExpert::build() {
    board.setStation(currentCity, true);
    return *this;
}

string pandemic::OperationsExpert::role() {
    return "OperationsExpert";
}
