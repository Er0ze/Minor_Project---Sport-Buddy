#include "EventManager/EventManager.h"

void EventManager::addEvent(const Event& event) {
    events[event.getId()] = event;
}

void EventManager::registerUserForEvent(int eventId, const User& user) {
    eventRegistrations[eventId].push_back(user);
}

std::vector<User> EventManager::getUsersRegisteredForEvent(int eventId) const {
    auto it = eventRegistrations.find(eventId);
    if (it != eventRegistrations.end()) {
        return it->second;
    }
    return {};
}

std::vector<Event> EventManager::getEventsForUser(const User& user) const {
    std::vector<Event> userEvents;
    for (const auto& [eventId, users] : eventRegistrations) {
        for (const auto& registeredUser : users) {
            if (registeredUser.getId() == user.getId()) {
                userEvents.push_back(events.at(eventId));
                break;
            }
        }
    }
    return userEvents;
}
