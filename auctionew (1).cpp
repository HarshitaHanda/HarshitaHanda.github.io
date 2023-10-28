#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Participant {
    private:
        string name;
        int age;
        char gender;
        int id;
    public:
        Participant(string name, int age, char gender, int id) {
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->id = id;
        }

        string get_name() {
            return name;
        }

        int get_id() {
            return id;
        }
};

class Painting {
    private:
        string name;
        int minimum_bid;
        Participant* highest_bidder;
        int highest_bid;
    public:
        Painting(string name, int minimum_bid) {
            this->name = name;
            this->minimum_bid = minimum_bid;
            this->highest_bidder = NULL;
            this->highest_bid = 0;
        }

        string get_name() {
            return name;
        }

        int get_minimum_bid() {
            return minimum_bid;
        }

        Participant* get_highest_bidder() {
            return highest_bidder;
        }

        int get_highest_bid() {
            return highest_bid;
        }

        void place_bid(Participant* bidder, int bid_amount) {
            if (bid_amount > highest_bid && bid_amount >= minimum_bid) {
                highest_bidder = bidder;
                highest_bid = bid_amount;
            }
        }
};

class Auction {
    private:
        vector<Participant*> participants;
        vector<Painting*> paintings;
    public:
        Auction() {}

        void add_participant(Participant* participant) {
            participants.push_back(participant);
        }

        void add_painting(Painting* painting) {
            paintings.push_back(painting);
        }

        void conduct_auction() {
            for (Painting* painting : paintings) {
                cout << "Auction for " << painting->get_name() << ":\n";
                cout << "Minimum bid: " << painting->get_minimum_bid() << "\n";
                cout << "Enter bids:\n";

                while (true) {
                    bool all_bids_in = true;

                    for (Participant* participant : participants) {
                        int bid_amount;

                        cout << participant->get_name() << ": ";
                        cin >> bid_amount;

                        painting->place_bid(participant, bid_amount);

                        if (bid_amount > painting->get_highest_bid()) {
                            all_bids_in = false;
                        }
                    }

                    if (all_bids_in) {
                        break;
                    }
                }

                cout << "Sold to " << painting->get_highest_bidder()->get_name() << " for " << painting->get_highest_bid() << "\n";
            }
        }
};

int main() {
    Auction auction;

    // Add participants
    Participant* participant1 = new Participant("John", 25, 'M', 1);
    Participant* participant2 = new Participant("Jane", 30, 'F', 2);
    Participant* participant3 = new Participant("Bob", 40, 'M', 3);

    auction.add_participant(participant1);
    auction.add_participant(participant2);
    auction.add_participant(participant3);

    // Add paintings
    Painting* painting1 = new Painting("Mona Lisa", 1000);
    Painting* painting2 = new Painting("The Starry Night", 800);
    Painting* painting3 = new Painting("The Persistence of Memory", 500);

    auction.add_painting(painting1);
    auction.add_painting(painting2);
    auction.add_painting(painting3);

// Conduct auction
auction.conduct_auction();

return 0;
}
