//
//  Builder.h
//  MorePatterns
//
//  Created by Salim Zayat on 12/16/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

#include <list>

enum Position
{
    POINT_GUARD,
    SHOOTING_GUARD,
    SMALL_FORWARD,
    POWER_FORWARD,
    CENTER
};

class Component
{
public:
    virtual void Update() = 0;
};

class Shooting : public Component
{
public:
    Shooting(int rating2Point, int rating3Point) {}

    void SetRating2Point(int rating) { m_rating2Point = rating; }
    void SetRating3Point(int rating) { m_rating3Point = rating; }
    
    virtual void Update() override {}
    
private:
    int m_rating2Point;
    int m_rating3Point;
};

class Passing : public Component
{
public:
    Passing(int accuracy) {}
    
    void SetAccuracy(int rating) { m_accuracy = rating; }
    
    virtual void Update() override {}
    
private:
    int m_accuracy;
};


class Defense : public Component
{
public:
    Defense(int ratingPerimeter, int ratingInterior) {}
    
    virtual void Update() override {};
    
private:
    int m_ratingPerimeter;
    int m_ratingInterior;
    
};

class Blocking : public Component
{
public:
    Blocking(int rating) {}
    
    virtual void Update() override {};
    
private:
    int m_rating;
};

class Player
{
public:
    Player(const char* pName, Position position)
    : m_pName(pName)
    , m_position(position)
    {}
    
    void AddComponent(Component* pComponent) { m_components.push_back(pComponent); }
    const char* GetName()   { return m_pName; }
    Position GetPosition()  { return m_position; }
    
private:
    std::list<Component*> m_components;
    const char* m_pName;
    Position m_position;
    
};

class PlayerBuilder
{
public:
    PlayerBuilder();
    ~PlayerBuilder();
    
    PlayerBuilder* Start(const char* pName, Position position);
    PlayerBuilder* AddShooting(int rating2Point, int rating3Point);
    PlayerBuilder* AddPassing(int accuracy);
    PlayerBuilder* AddDefense(int perimeter, int interior);
    PlayerBuilder* AddBlocking(int rating);
    Player* Build();

private:
    Player* m_player;
};


#endif /* Builder_h */
