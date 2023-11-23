//
// Created by Mikko Ryynänen on 19.11.2023.
//

class IDamageable
{
public:
    void setMaxHealth(int value) { maxHealth = value; health = value; }

private:
    int maxHealth = 100;    // TODO this could be in configurable file
    int health = maxHealth;

protected:
    void reduceHealth(int value) { health -= value; };
    int getHealth() const { return health; }

    virtual bool takeDamage(int damage) = 0;
};
