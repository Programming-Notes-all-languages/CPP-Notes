#include "Passenger.hpp"

bool Passenger::isFrequentFlyer() const
{
    return isFreqFlyer;
}

void Passenger::makeFrequentFlyer(const int *newFreqFlyerNo) 
{
    isFreqFlyer = true;
    freqFlyerNo = *newFreqFlyerNo;
}

Passenger::Passenger() 
{
    name = "--NO NAME--";
    mealPref = NO_PREF; 
    isFreqFlyer = false; 
    freqFlyerNo = 0;
}

Passenger::Passenger(const string &nm, MealType mp, const int ffn) 
{
    name = nm; 
    mealPref = mp;
    isFreqFlyer = (ffn != 0); // true only if ffn given
    freqFlyerNo = ffn;
}

Passenger::Passenger(const Passenger& pass) 
{
    name = pass.name; 
    mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer; 
    freqFlyerNo = pass.freqFlyerNo;
}

//print method for Passenger class which prints all of the passenger's information
void Passenger::print() const 
{
    //printing the passenger's name
    cout << "Name: " << this->name << endl;
    //printing the passenger's meal preference
    cout << "Meal Preference: ";

    //switch statement which prints out the meal preference for the passenger
    switch (this->mealPref)
    {
        case 0: cout << "None"; break;
        case 1: cout << "Regular"; break;
        case 2: cout << "Low Fat"; break;
        case 3: cout << "Vegetarian"; break;
    }

    //printing if the passenger is a frequent flyer
    cout << "\nFrequent Flyer: ";
    (this->isFreqFlyer) ? cout << "Yes\n" : cout << "No\n";
    //printing the passenger's frequent flyer number
    cout << "Frequent Flyer Number: " << this->freqFlyerNo << endl;
}