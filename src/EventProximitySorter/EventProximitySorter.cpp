#include "EventProximitySorter.h"
#include "LocationManager.h"
#include <algorithm> // for std::sort

std::vector<Event> EventProximitySorter::sortEventsByProximity(const User& user, const std::vector<Event>& events) {
    std::vector<Event> sortedEvents = events;

    // Sorting events by proximity to the user's location
    std::sort(sortedEvents.begin(), sortedEvents.end(), [&user](const Event& a, const Event& b) {
        double distanceA = LocationManager::calculateDistance(
            user.getLocation().getLatitude(), user.getLocation().getLongitude(),
            a.getLocation().getLatitude(), a.getLocation().getLongitude()
        );
        double distanceB = LocationManager::calculateDistance(
            user.getLocation().getLatitude(), user.getLocation().getLongitude(),
            b.getLocation().getLatitude(), b.getLocation().getLongitude()
        );
        return distanceA < distanceB;
    });

    return sortedEvents;
}
