#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Location.h" // Assuming Location is defined in Location.h

class Event {
public:
    // Constructor with location initialization
    Event(int id, const std::string& name, const Location& location);

    int getId() const;
    std::string getName() const;

    // Method to get the event's location
    Location getLocation() const;

private:
    int id;
    std::string name;
    Location location; // Location member variable
};

#endif // EVENT_H
