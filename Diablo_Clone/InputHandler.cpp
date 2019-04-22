//
//  InputHandler.cpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#include "InputHandler.hpp"

void SetNewKey(int oldKey) {
    oldKey = GetKeyPressed();
}

void HandlePlayerInput(ParentObject* p1) {
    Vector2 pos = p1->GetPosition();
    if (IsKeyDown(MoveUp)) {
        p1->SetPosition(pos.x + 0, pos.y + -1);
    }
    else if (IsKeyDown(MoveDown)) {
        p1->SetPosition(pos.x + 0, pos.y + 1);
    }
    
    if (IsKeyDown(MoveLeft)) {
        p1->SetPosition(pos.x + -1, pos.y + 0);
    }
    else if (IsKeyDown(MoveRight)) {
        p1->SetPosition(pos.x + 1, pos.y +  0);
    }
}
