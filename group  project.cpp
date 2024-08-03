#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool validate_credit_card(const string& credit_card) {
    
    for (size_t i = 0; i < credit_card.length(); ++i) {
        if (!isdigit(credit_card[i])) {
            return false;
        }
    }
    return true;
}

bool validate_credit_card_number(const string& credit_card, const vector<string>& valid_credit_cards) {
    return find(valid_credit_cards.begin(), valid_credit_cards.end(), credit_card) != valid_credit_cards.end();
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
    vector<string> valid_credit_cards;
    valid_credit_cards.push_back("2001200111");
    valid_credit_cards.push_back("2002200222");
    valid_credit_cards.push_back("2003200333");
    valid_credit_cards.push_back("2004200444");
    valid_credit_cards.push_back("2005200555");
    valid_credit_cards.push_back("2006200666");
    valid_credit_cards.push_back("2007200777");
    valid_credit_cards.push_back("2008200888");
    valid_credit_cards.push_back("2009200999");
    valid_credit_cards.push_back("2010201010");
    valid_credit_cards.push_back("2011201111");
    valid_credit_cards.push_back("2012201212");
    valid_credit_cards.push_back("2013201313");
    valid_credit_cards.push_back("2014201414");
    valid_credit_cards.push_back("2015201515");
    valid_credit_cards.push_back("2016201616");
    valid_credit_cards.push_back("2017201717");
    valid_credit_cards.push_back("2018201818");
    valid_credit_cards.push_back("2019201919");
    valid_credit_cards.push_back("2020202020");

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
                    if (validate_credit_card_number(credit_card, valid_credit_cards)) {
                        cout << "Valid_credit_card_number!" << endl;
                    } else {
                        cout << "Invalid credit_card_number!" << endl;
                    }
                }
                break;
            case 2:
                {
                    string credit_card = enter_credit_card();
                    if (validate_credit_card_number(credit_card, valid_credit_cards)) {
                        cout << "Valid credit card number!" << endl;
                    } else {
                        cout << "Invalid credit card number!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Exits the program." << endl;
                return 0;
            default:
                cout << "SORRY Invalid option." << endl;
                cout<<"Please select a valid option (1 & 2 & 3).\n";
        }
    }

    return 0;
}

