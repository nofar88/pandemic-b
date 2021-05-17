
#include "Researcher.hpp"
const unsigned int FIVE = 5;

pandemic::Player& pandemic::Researcher::discover_cure(pandemic::Color color) {
    return Player::discover_cure(color,FIVE, true, false);
}

string pandemic::Researcher::role() {
    return "Researcher";
}
