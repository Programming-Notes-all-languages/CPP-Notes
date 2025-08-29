#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
using namespace std;

//enum declarations for passenger's meal type
enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

//class definition for a Passenger
class Passenger 
{
    //private attributes
    string name;
    MealType mealPref;
    bool isFreqFlyer;
    int freqFlyerNo;

    public:
        //default constructor
        Passenger();
        //constructor initializing name, meal preference, and setting frequent flyer to default if not provided at time of constructor's call
        Passenger(const string& nm, MealType mp, const int ffn = 0);
        //copy constructor
        Passenger(const Passenger& pass);
        //method for returning if passenger is a frequent flyer
        bool isFrequentFlyer() const;
        //method for making passenger a frequent flyer
        void makeFrequentFlyer(const int *newFreqFlyerNo);
        //printing passenger's information
        void print() const;
};

#endif