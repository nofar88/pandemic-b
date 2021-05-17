
#include "GeneSplicer.hpp"

const unsigned int FIVE = 5;


pandemic::Player& pandemic::GeneSplicer::discover_cure(pandemic::Color color) {
    return Player::discover_cure(color,FIVE, false, true);
}

string pandemic::GeneSplicer::role() {
    return "GeneSplicer";
}
