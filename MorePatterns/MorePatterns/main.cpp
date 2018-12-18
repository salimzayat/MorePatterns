//
//  main.cpp
//  MorePatterns
//
//  Created by Salim Zayat on 12/16/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#include <iostream>
#include "Builder.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    PlayerBuilder* pBuilder = new PlayerBuilder();
    Player* pPlayer = pBuilder->Start("L. James", Position::SMALL_FORWARD)->
        AddShooting(80, 78)->
        AddPassing(90)->
        AddDefense(80, 92)->
        AddBlocking(82)->
        Build();
    
    // now we have our player
    std::cout << "we now have " << pPlayer->GetName() << std::endl;
    return 0;
}
