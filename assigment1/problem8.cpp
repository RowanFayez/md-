#include <iostream>
#include <cmath>
using namespace std;
// initialize the univesal gravitational
const double ug = 6.673 * pow(10, -8);
// Declare  gravitational force function
double gravitationalForce(double m1, double m2, double d)
{
    double force = (ug * m1 * m2) / pow(d, 2);
    return force;
}

int main()
{
    double mass1, mass2, distance;
    char character;
    do
    {
        cout << "Enter mass of object 1: ";
        cin >> mass1;
        cout << "Enter mass of object 2: ";
        cin >> mass2;
        cout << "Enter the distance between two objects: ";
        cin >> distance;

        cout << "The gravitational force is: " << gravitationalForce(mass1, mass2, distance) << " dynes." << endl;
        cout << "Do you want to repeat again (Y/N) :";
        cin >> character;

    } while (character == 'y' || character == 'Y');
    cout << "Program is terminated ";
    return 0;
}