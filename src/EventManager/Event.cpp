#include "Event.h"

Event::Event(int id, const std::string& name, const Location& location)
    : id(id), name(name), location(location) {}

int Event::getId() const {
    return id;
}

std::string Event::getName() const {
    return name;
}

Location Event::getLocation() const {
    return location;
}
