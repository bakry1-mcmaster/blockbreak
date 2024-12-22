#include "defaultobj.hpp"

defaultobj::defaultobj()
{
    objectstats = new stats;

    objectstats->size_x = 0;
    objectstats->size_y = 0;
    objectstats->velocity_x = 0;
    objectstats->velocity_y = 0;

}

defaultobj::~defaultobj()
{
    delete objectstats;
    objectstats = nullptr;
}


stats* defaultobj::getStats() const
{
    return objectstats;
}