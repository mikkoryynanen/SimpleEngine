//
// Created by Mikko Ryynänen on 19.11.2023.
//

class IDamageable
{
private:
    int health;
    int maxHealth = 100;    // TODO this could be in configurable file

protected:
    virtual void reduceHealth(int value) { health -= value; };
    int getHealth() const { return health; }

public:
    virtual void takeDamage(int damage) = 0;
};
