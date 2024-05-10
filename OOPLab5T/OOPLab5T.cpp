#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string m_first_name;
    string m_last_name;
    string m_patronymic;
    int m_year;
    int m_pin;
public:
    Student() {
        m_first_name = "Invalid name";
        m_last_name = "Invalid last name";
        m_patronymic = "Invalid patronymic";
        m_year = 0;
        m_pin = 000000;
    }
    Student(string name, string last_name, string patronymic, int year, int pin) {
        m_first_name = name;
        m_last_name = last_name;
        m_patronymic = patronymic;
        m_year = year;
        m_pin = pin;
    }

    ~Student() {
        cout << "Deleting Student." << endl;
    }

    auto set_first_name(string name) {
        m_first_name = name;
    }

    auto set_last_name(string name) {
        m_last_name = name;
    }

    auto set_patronymic(string name) {
        m_patronymic = name;
    }

    auto set_year(int year) {
        m_year = year;
    }

    auto set_pin(int pin) {
        m_pin = pin;
    }

    void get_inf() {
        cout << "First Name:" << m_first_name << endl;
        cout << "Last Name:" << m_last_name << endl;
        cout << "Patronymic:" << m_patronymic << endl;
        cout << "Year of study:" << m_year << endl;
        cout << "Personal identify number:" << m_pin << endl;
    }
};
class Dyplom :public Student {
    string m_theme;
public:
    Dyplom() :
        Student() {
        m_theme = "No theme";
    }
    Dyplom(string name, string last_name, string patronymic, int year, int pin, string theme) :
        Student(name, last_name, patronymic, year, pin) {
        m_theme = theme;
    }
    ~Dyplom() {
        cout << "Deleting Dyploma" << endl;
    }

    void set_theme(string theme) {
        m_theme = theme;
    }
    void get_inf() {
        cout << "First Name:" << m_first_name << endl;
        cout << "Last Name:" << m_last_name << endl;
        cout << "Patronymic:" << m_patronymic << endl;
        cout << "Year of study:" << m_year << endl;
        cout << "Personal identify number:" << m_pin << endl;
        cout << "Dyploma theme:" << m_theme << endl;
    }
};

auto task1() {
    Student thomas("Thomas", "Shelby", "Michael", 3, 64664);
    thomas.get_inf();
    Dyplom tayler("Tyler", "Derden", " ", 5, 14, "Chemistry");
    tayler.get_inf();
}

class Room {
protected:
    float m_area;
public:
    Room() {
        m_area = 0;
    }
    Room(float area) {
        m_area = area;
    }
    ~Room() {
        cout << "Deleting room" << endl;
    }
    void set_area(float area) {
        m_area = area;
    }
    void get_area() {
        cout << "Square:" << m_area << endl;
    }
};

class Apartment : public Room {
protected:
    float m_kit_area;
    int m_floor;
public:
    Apartment() :Room() {
        m_kit_area = 0;
        m_floor = 1;
    }
    Apartment(float area, float kit_area, int floor) :Room(area) {
        m_kit_area = kit_area;
        m_floor = floor;
    }
    ~Apartment() {
        cout << "Deleting Apartment" << endl;
    }
    void set_floor(int floor) {
        m_floor = floor;
    }
    void set_kit_area(float kit_area) {
        m_kit_area = kit_area;
    }
    void get_inf() {
        cout << "Room area:" << m_area << endl;
        cout << "Kitchen area:" << m_kit_area << endl;
        cout << "Floor:" << m_floor << endl;
    }
};

class CityApartment : public Apartment {
protected:
    string m_city;
public:
    CityApartment() :Apartment() {
        m_city = "NoNe";
    }
    CityApartment(float area, float kit_area, int floor, string city) : Apartment(area, kit_area, floor) {
        m_city = city;
    }
    ~CityApartment() {
        cout << "Deleting CityApartment" << endl;
    }
    void set_city(string city) {
        m_city = city;
    }
    void get_inf() {
        cout << "Room area:" << m_area << endl;
        cout << "Kitchen area:" << m_kit_area << endl;
        cout << "Floor:" << m_floor << endl;
        cout << "City:" << m_city << endl;
    }
};

auto task2() {
    Room sam;
    sam.get_area();
    sam.set_area(500);
    sam.get_area();
    Apartment simple(50, 30, 3);
    simple.get_inf();
    CityApartment Vin(50, 30, 4, "Vinnica");
    Vin.get_inf();
}


class Game {
protected:
    int m_players;
    int m_score;
    float m_timer;
    string m_rules;

public:

    Game() {
        m_players = 2;
        m_score = 3;
        m_timer = 15.0;
        m_rules = "Not Found";
    }

    Game(int players, int score, float timer, string rules) {
        m_players = players;
        m_score = score;
        m_timer = timer;
        m_rules = rules;
    }

    ~Game() {
        cout << "Deleting Game:" << endl;
    }

    void set_players(int players) {
        m_players = players;
    }

    void set_score(int score) {
        m_score = score;
    }

    void set_timer(float timer) {
        m_timer = timer;
    }

    void set_rules(string rules) {
        m_rules = rules;
    }

    void get_inf() {
        cout << "Numbers of players: " << m_players << endl;
        cout << "Max score: " << m_score << endl;
        cout << "Time for play: " << m_timer << " minutes" << endl;
        cout << "Rules: " << m_rules << endl;
    }
};

class Football : public Game {
private:
    string m_team1;
    string m_team2;

public:

    Football() {
        m_players = 11;
        m_score = 0;
        m_timer = 90.0;
        m_rules = "Standard FIFA rules";
        m_team1 = "Team1";
        m_team2 = "Team2";
    }
    Football(int players, int score, float timer, string rules, string team1, string team2) : Game(players, score, timer, rules) {
        m_team1 = team1;
        m_team2 = team2;
    }


    ~Football() {
        cout << "Deleting Football:" << endl;
    }

    void set_teams(string team1, string team2) {
        m_team1 = team1;
        m_team2 = team2;
    }

    void get_teams() {
        cout << "Team 1: " << m_team1 << endl;
        cout << "Team 2: " << m_team2 << endl;
    }
};

void task3() {
    cout << "Testing default Game class:" << endl;
    Game game;
    game.get_inf();

    cout << "\nTesting parameterized Game class:" << endl;
    Game game1(4, 5, 20.5, "Basic rules");
    game1.get_inf();

    cout << "\nTesting default Football class:" << endl;
    Football football;
    football.get_inf();
    football.get_teams();

    cout << "\nTesting parameterized Football class:" << endl;
    Football Football1(22, 5, 90, "Custom rules", "Real Madrid", "Barcelona");
    Football1.get_inf();
    Football1.get_teams();
}


int main()
{
    int choice;
    cout << "Choose task" << endl;
    cout << "1.Task 1 (Student)" << endl;
    cout << "2.Task 2 (Room)" << endl;
    cout << "3.Task 3(Games)" << endl;
    cout << "4.Exit" << endl;

    cin >> choice;

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: task3(); break;
    case 4: return 0;
    default: cout << "Error" << endl;
    }
}
