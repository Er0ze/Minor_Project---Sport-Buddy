#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.h"
#include "User.h"
#include <vector>
#include <unordered_map>

class EventManager {
public:
    void addEvent(const Event& event);
    void registerUserForEvent(int eventId, const User& user);
    std::vector<User> getUsersRegisteredForEvent(int eventId) const;
    std::vector<Event> getEventsForUser(const User& user) const;

private:
    std::unordered_map<int, Event> events;
    std::unordered_map<int, std::vector<User>> eventRegistrations;
};

#endif // EVENTMANAGER_H
