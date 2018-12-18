//
//  Builder.cpp
//  MorePatterns
//
//  Created by Salim Zayat on 12/16/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#include <stdio.h>
#include "Builder.h"

PlayerBuilder::PlayerBuilder()
{
    m_player = nullptr;
}

PlayerBuilder::~PlayerBuilder()
{
    if (m_player != nullptr)
    {
        delete m_player;
    }
}

PlayerBuilder* PlayerBuilder::Start(const char* pName, Position position)
{
    if (m_player != nullptr)
    {
        delete m_player;
    }
    // keep track of a local player
    m_player = new Player(pName, position);
    // we can give the player some default components, but let's not
    return this;
}

PlayerBuilder* PlayerBuilder::AddShooting(int rating2Point, int rating3Point)
{
    m_player->AddComponent(new Shooting(rating2Point, rating3Point));
    return this;
}

PlayerBuilder* PlayerBuilder::AddPassing(int accuracy)
{
    m_player->AddComponent(new Passing(accuracy));
    return this;
}

PlayerBuilder* PlayerBuilder::AddDefense(int perimeter, int interior)
{
    m_player->AddComponent(new Defense(perimeter, interior));
    return this;
}

PlayerBuilder* PlayerBuilder::AddBlocking(int rating)
{
    m_player->AddComponent(new Blocking(rating));
    return this;
}

Player* PlayerBuilder::Build()
{
    return m_player;
}
