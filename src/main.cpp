#include <iostream>
#include <vector>
#include "UserAccountManagement/User.h"
#include "UserAccountManagement/UserAccountManager.h"
#include "EventManager/Event.h"
#include "EventManager/EventManager.h"
#include "Proximity-based Search/LocationManager.h"
#include "EventProximitySorter/EventProximitySorter.h"
#include "GraphManagement/GraphManager.h"
#include "GraphTraversal/GraphTraversal.h"
#include "RecommendationEngine/RecommendationEngine.h"
#include "AlphabeticalSorting/AlphabeticalSorter.h"


int main() {
    // Create instances of necessary managers
    LocationManager locationManager;
    EventManager eventManager;
    UserAccountManager userAccountManager;
    EventProximitySorter eventSorter;
    RecommendationEngine recommendationEngine;

    // User registration
    std::cout << "Welcome to Sports Buddy!\n";
    std::cout << "Please register users.\n";

    while (true) {
        std::string username, name, email;
        double latitude, longitude;

        std::cout << "Enter username (or type 'exit' to finish): ";
        std::getline(std::cin, username);
        if (username == "exit") break;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Enter email: ";
        std::getline(std::cin, email);

        std::cout << "Enter latitude: ";
        std::cin >> latitude;

        std::cout << "Enter longitude: ";
        std::cin >> longitude;
        std::cin.ignore(); // Clear newline from input buffer

        User newUser(username, name, email, latitude, longitude);
        locationManager.addUserLocation(newUser);
        std::cout << "User registered successfully!\n\n";
    }

    // Event creation
    std::cout << "Now let's create some events.\n";
    while (true) {
        int eventId;
        std::string eventName;

        std::cout << "Enter event ID (or type '-1' to finish): ";
        std::cin >> eventId;
        if (eventId == -1) break;

        std::cout << "Enter event name: ";
        std::cin.ignore(); // Clear newline from input buffer
        std::getline(std::cin, eventName);

        Event newEvent(eventId, eventName);
        eventManager.addEvent(newEvent);
        std::cout << "Event created successfully!\n\n";
    }

    // User registration for events
    std::cout << "Register users for events.\n";
    while (true) {
        int eventId;
        std::string username;

        std::cout << "Enter event ID to register (or type '-1' to finish): ";
        std::cin >> eventId;
        if (eventId == -1) break;

        std::cout << "Enter username of the user to register: ";
        std::cin.ignore(); // Clear newline from input buffer
        std::getline(std::cin, username);

        // Assuming User is uniquely identified by username
        User userToRegister(username, "", "", 0, 0); // Dummy user object
        eventManager.registerUserForEvent(eventId, userToRegister);
        std::cout << "User registered for event successfully!\n\n";
    }

    // Example of finding nearby users
    std::cout << "Find nearby users.\n";
    std::string currentUserUsername;
    std::cout << "Enter your username to find nearby users: ";
    std::getline(std::cin, currentUserUsername);

    // Find the current user by username
    User currentUser = locationManager.findUsersNearby(User(currentUserUsername, "", "", 0, 0), 0).at(0); // Get first user with that username (if exists)

    double maxDistance;
    std::cout << "Enter maximum distance to find nearby users (in km): ";
    std::cin >> maxDistance;

    std::cout << "Nearby Users to " << currentUser.getUsername() << ":\n";
    std::vector<User> nearbyUsers = locationManager.findUsersNearby(currentUser, maxDistance);
    for (const auto& user : nearbyUsers) {
        std::cout << user.getUsername() << " - " << user.getName() << "\n";
    }

    // Example of sorting events by proximity
    std::vector<Event> events = eventManager.getEventsForUser(currentUser);
    std::vector<Event> sortedEvents = eventSorter.sortEventsByProximity(currentUser, events);

    std::cout << "Events sorted by proximity to " << currentUser.getUsername() << ":\n";
    for (const auto& event : sortedEvents) {
        std::cout << event.getId() << ": " << event.getName() << "\n";
    }

    // Example of using the recommendation engine (if applicable)
    std::vector<Event> recommendedEvents = recommendationEngine.getRecommendations(currentUser);
    std::cout << "Recommended Events for " << currentUser.getUsername() << ":\n";
    for (const auto& event : recommendedEvents) {
        std::cout << event.getId() << ": " << event.getName() << "\n";
    }

    // You can also implement graph-related functionalities if needed

    return 0;
}
