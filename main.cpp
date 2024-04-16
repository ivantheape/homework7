#include <iostream>
#include <vector>

class Observer {
public:
    virtual void onFireDamage(int damage) = 0;
};

class Fire {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void damagePlayer(int damage) {
        for (Observer* observer : observers) {
            observer->onFireDamage(damage);
        }
    }
};

class Player : public Observer {
public:
    void onFireDamage(int damage) override {
        std::cout << "Player received " << damage << " damage from fire!" << std::endl;
    }
};

int main() {
    Fire fire;
    Player player;

    fire.addObserver(&player);

    fire.damagePlayer(10);

    return 0;
}
