#include <iostream>
#include <string>
using namespace std;

bool validate_credit_card(const string& credit_card) {
    for (size_t i = 0; i < credit_card.length(); ++i) {
        if (!isdigit(credit_card[i])) {
            return false;
        }
    }
    return true;
}

bool validate_credit_card_number(const string& credit_card, const string valid_credit_cards[], const int num_valid_credit_cards) {
    for (int i = 0; i < num_valid_credit_cards; ++i) {
        if (credit_card == valid_credit_cards[i]) {
            return true;
        }
    }
    return false;
}

string enter_credit_card() {
    string credit_card;
    do {
        cout << "Enter 10-digit credit_card_number:\n ";
        cin >> credit_card;
        if (credit_card.length() != 10 || !validate_credit_card(credit_card)) {
            cout << "SORRY Please enter 10-digit credit_card_number." << endl;
        }
    } while (credit_card.length() != 10 || !validate_credit_card(credit_card));
    return credit_card;
}

int main() {
    const int num_credit_cards = 20;
    string valid_credit_cards[num_credit_cards] = {
        "2001200111", "2002200222", "2003200333", "2004200444", "2005200555",
        "2006200666", "2007200777", "2008200888", "2009200999", "2010201010",
        "2011201111", "2012201212", "2013201313", "2014201414", "2015201515",
        "2016201616", "2017201717", "2018201818", "2019201919", "2020202020"
    };

    int option;

    while (true) {
        cout << "----------INFORMATION IN CREDIT_CARD_NUMBERS----------" << endl;
        cout << "          1: Enter a credit_card_number" << endl;
        cout << "          2: Continue enter another credit_card_number" << endl;
        cout << "          3: Exit" << endl;

        cout << "Enter your choice (1 & 2 & 3): \n";
        cin >> option;

        switch (option) {
            case 1:
                {
                    string credit_card = enter_credit_card();
                    if (validate_credit_card_number(credit_card, valid_credit_cards, num_credit_cards)) {
                        cout << "Valid_credit_card_number!" << endl;
                    } else {
                        cout << "Invalid credit_card_number!" << endl;
                    }
                }
                break;
            case 2:
                {
                    string credit_card = enter_credit_card();
                    if (validate_credit_card_number(credit_card, valid_credit_cards, num_credit_cards)) {
                        cout << "Valid credit_card_number!" << endl;
                    } else {
                        cout << "Invalid credit_card_number!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Exits the program." << endl;
                return 0;
            default:
                cout << "SORRY Invalid option." << endl;
                cout << "Please select a valid option (1 & 2 & 3).\n";
        }
    }
    return 0;
}

