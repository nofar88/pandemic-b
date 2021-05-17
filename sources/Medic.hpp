

#ifndef DEMO1_CPP_MEDIC_HPP
#define DEMO1_CPP_MEDIC_HPP
#include "Player.hpp"
namespace pandemic {

    class Medic : public Player{
    public:
        Medic(Board& board, City city): Player(board, city){tryTreatTheCity();};// Automatically checks in the city he is in if there is a cure

         Player& drive(City) override;

         Player& fly_direct(City) override;

         Player& fly_charter(City) override;

         Player& fly_shuttle(City) override;

         Player& treat(City) override;

         void tryTreatTheCity();

         string role() override;

    };
}


#endif //DEMO1_CPP_MEDIC_HPP
