// Location.h
#ifndef LOCATION_H
#define LOCATION_H

class Location {
public:
    Location(double latitude, double longitude)
        : latitude(latitude), longitude(longitude) {}  // Constructor initializing latitude and longitude

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

private:
    double latitude;   // Latitude coordinate
    double longitude;  // Longitude coordinate
};

#endif // LOCATION_H
