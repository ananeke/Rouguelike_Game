#include "actor.h"
#include <string>

unsigned int Actor::getLife() { return life; }
unsigned int Actor::getStrength() { return strength; }
string Actor::getActorName() { return actorName; }
int Actor::getActorType() { return actorType; }
int Actor::getPositionX() { return positionX; }
int Actor::getPositionY() { return positionY; }

void Actor::setLife(unsigned int life) { this->life = life; }
void Actor::setStrength(unsigned int strength) { this->strength = strength; }
void Actor::setActorName(string actorName) { this->actorName = actorName; }
void Actor::setActorType(int actorType) { this->actorType = actorType; }
void Actor::setPositionX(int positionX) { this->positionX = positionX; }
void Actor::setPositionY(int positionY) { this->positionY = positionY; }

void Actor::Attack(){}
void Actor::showBackPack(){}

Actor::~Actor() {}