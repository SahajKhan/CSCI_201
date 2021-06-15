/*
*  Program name: Player
*  Author: Sahaj Khan
*/
#pragma once
#include<string>
#include <iostream>

using namespace std;

/*Main Abstract Player Class*/
class Player{
    protected:
        string name;
        int playerID;
    
    public:
        string getName() { return name; }
        int getPlayerID() {return playerID;}


        //abstract methods
        virtual string getPlayerPosition() = 0;
        virtual void play() = 0;
        virtual void toString() = 0;
};

/*Abstract Class for Offensive Players*/
class Offence:public Player{
    string playerPosition = "Offence";
    public:
        virtual void play() = 0;

        string getPlayerPosition() override { return playerPosition; }
        void setName(string name) { this->name = name; }
        void setPlayerID(int playerID) { this->playerID = playerID; }

        void toString() {
            cout << "Name: " << getName() << endl;
            cout << "PlayerID: " << getPlayerID() << endl;
            cout << "Player Position: " << playerPosition << endl;
        }
};

/*Abstract Class for Defensive Players*/
class Defense:public Player{
    string playerPosition = "Defence";
    public:
        virtual void play() = 0;
        void setPlayerID(int playerID) { this->playerID = playerID; }
        string getPlayerPosition() override { return playerPosition; }

        void toString() {
            cout << "Name: " << getName() << endl;
            cout << "PlayerID: " << getPlayerID() << endl;
            cout << "Player Position: " << playerPosition << endl;
        }
};

/*Abstract Class for Special Players*/
class specialTeams:public Player{
    string playerPosition = "Special";
    public:
        virtual void play() = 0;
        void setPlayerID(int playerID) { this->playerID = playerID; }
        string getPlayerPosition() override { return playerPosition; }
        
        void toString() {
            cout << "Name: " << getName() << endl;
            cout << "PlayerID: " << getPlayerID() << endl;
            cout << "Player Position: " << playerPosition << endl;
        }
        
};


/*Parent Class to form Teams of all types of Players*/
class Team {
    //All player types will extend this class.
};

/*Offence*/
class QuarterBack:public Offence, public Team {
public:
    QuarterBack(string name, int playerID) {
        this->name = name;
        this->playerID = playerID;
    }
    void play() {
        cout << "Recieve" << endl;
    }
};
class WideReceiver :public Offence, public Team {
    public:
        WideReceiver (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Wide Recieve" << endl;
        }
};
class TightEnd :public Offence, public Team {
    public:
        TightEnd (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Tight End" << endl;
        }
};
class RunningBack :public Offence, public Team{
    public:
        RunningBack (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Running Back" << endl;
        }
};
class OffensiveLineman :public Offence, public Team {
    public:
        OffensiveLineman (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Offensive Lineman" << endl;
        }
};

/*Defence*/
class DefensiveLineman :public Defense, public Team{
    public:
        DefensiveLineman (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Defensive Lineman" << endl;
        }
};
class LineBacker :public Defense, public Team{
    public:
        LineBacker (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Linebacker" << endl;
        }
};
class DefensiveBack :public Defense, public Team{
    public:
        DefensiveBack (string name, int playerID) {
            this->name = name;
            this->playerID = playerID;
        }
        void play() {
            cout << "Defensive Back" << endl;
        }
};

/*Special*/
class Kicker :public specialTeams, public Team {
public:
    Kicker (string name, int playerID) {
        this->name = name;
        this->playerID = playerID;
    }
    void play() {
        cout << "Kicker" << endl;
    }
};
class Holder :public specialTeams, public Team {
public:
    Holder (string name, int playerID) {
        this->name = name;
        this->playerID = playerID;
    }
    void play() {
        cout << "Holder" << endl;
    }
};
class Punter :public specialTeams, public Team {
public:
    Punter (string name, int playerID) {
        this->name = name;
        this->playerID = playerID;
    }
    void play() {
        cout << "Punt" << endl;
    }
};
class Returner :public specialTeams, public Team {
public:
    Returner (string name, int playerID) {
    this->name = name;
    this->playerID = playerID;
}
    void play() {
        cout << "Kick, Punt" << endl;
    }
};