//
//  Action.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "Action.hpp"


//MOVEMENT
//Also we gotta check collision. But let's just get the basics done.
void MoveUpCommand::execute(ParentObject& actor) {
    actor.SetPosition(0, -1);
}

void MoveDownCommand::execute(ParentObject& actor) {
    actor.SetPosition(0, 1);
}

void MoveLeftCommand::execute(ParentObject& actor) {
    actor.SetPosition(-1, 0);
}

void MoveRightCommand::execute(ParentObject& actor) {
    actor.SetPosition(1, 0);
}
