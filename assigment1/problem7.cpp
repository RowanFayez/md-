#include <iostream>
using namespace std;
const double lgallon=0.264179;
// function to calculate numbers of miles per gallon
double milePerGallon(double gasoline , double miles){
    double gallon =lgallon * gasoline;
    return miles/gallon;
}

int main(){
    double liters,miles;
    char character;
    do{
        cout <<"Enter the number of liters of gasoline :";
        cin >> liters;
        cout << "Enter the number of miles traveled by the car :";
        cin >> miles;
        double litergallon=milePerGallon(liters, miles);
        cout << "The number of miles per gallon the car delivered is : "<<litergallon << endl;
        cout << "Do you want to repeat again (Y/N) :";
        cin >> character;

    }while(character =='y' ||  character == 'Y');
    cout << "Program is terminated ";

    return 0;

}