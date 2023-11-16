#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>


using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;
    double price;
};

int main() {

    srand(time(0));

    int randomInvoiceNum = rand() % 10000000;

    string username;
    string attemptuser;
    string pass;
    string attemptpass;
    bool isLoggedIn;
    double cardBalance;
    string proceedPayment;
    string playAgain;

    const int numCars = 3;
    Car cars[numCars];

    cars[0] = {"S", "Model Super", 2015, 20000};
    cars[1] = {"A", "Model 5", 2008, 15000};
    cars[2] = {"C", "Model Premium", 2016, 45000};

    queue<Car> paymentQueue;

    // list<pair<string, string>> userCredentials;

    cout << "\n\t\tWelcome to Car Rental Service!";

    cout << "\n\nPlease register your details below:" << endl;

    cout << "\nEnter Username: ";

    cin >> username;

    cout << "\nEnter Password: ";

    cin >> pass;

    isLoggedIn = true;

    cout << "Please enter in your credit card balance (Rs): ";

    cin >> cardBalance;

    do {
        if (isLoggedIn == true) {
            cout << "Just to double-check, enter in your details below:" << endl;
            cout << "\nEnter User name: ";
            cin >> attemptuser;
            cout << "\nEnter Password: ";
            cin >> attemptpass;

            // Storing user credentials in a linked list
            userCredentials.push_back({attemptuser, attemptpass});

            if (attemptuser == username && attemptpass == pass) {
                isLoggedIn = true;
            } else {
                cout << "Wrong details!" << endl;
                exit(0);
            }

            if (isLoggedIn == true) {
                cout << "Welcome (back), " << username << "!\n";

                int cchoice;
                cout << "Cars available for rent now:" << endl;

                for (int i = 0; i < numCars; i++) {
                    cout << i + 1 << ". " << cars[i].brand << " " << cars[i].model << endl;
                }

                cout << "Which car do you want? (1-" << numCars << "): ";
                cin >> cchoice;

                if (cchoice >= 1 && cchoice <= numCars) {
                    cchoice--; // Adjust for zero-based array indexing

                    cout << "Your choice: " << cars[cchoice].brand << " " << cars[cchoice].model << endl;

                    cout << "Cost for 1 month: Rs" << cars[cchoice].price << endl;

                    cout << "Would you like to proceed with this payment? (only option for rent is 30 days, type y or Y for yes and N or N for no): ";

                    cin >> proceedPayment;

                    if (proceedPayment == "Y" || proceedPayment == "y") {
                        if (cars[cchoice].price <= cardBalance) {
                            paymentQueue.push(cars[cchoice]);

                            cout << "Payment successful!" << endl;

                            cout << "Here is the invoice:" << endl;

                            cout << "##########" << endl;


                            cout << "Order ID: " << randomInvoiceNum << endl;

                            cout << "Car: " << cars[cchoice].brand << endl;

                            cout << "Model: " << cars[cchoice].model << endl;

                            cout << "Price: Rs " << cars[cchoice].price << endl;

                            cout << "Rent Time: 30 Days" << endl;

                            cout << "##########";

                            cardBalance -= cars[cchoice].price;
                        } else {
                            cout << "Not enough funds! Program exiting.";
                            exit(0);
                        }
                    }
                }

                cout << "Do you want to rent another car? (y/n): ";
                cin >> playAgain;
            }
        }
    } while (playAgain == "y" || playAgain == "Y");

    return 0;
}
