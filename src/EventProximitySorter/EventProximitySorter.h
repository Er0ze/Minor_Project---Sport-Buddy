#ifndef EVENTPROXIMITYSORTER_H
#define EVENTPROXIMITYSORTER_H

#include "Proximity-based Search/LocationManager.h"
#include "EventManager/EventManager.h"
#include <vector>

class EventProximitySorter {
public:
    static std::vector<Event> sortEventsByProximity(const User& user, const std::vector<Event>& events);
};

#endif // EVENTPROXIMITYSORTER_H
