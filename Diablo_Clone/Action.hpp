//
//  Action.hpp
//  Diablo_Clone
//
//  Created by Nicholas A Nelson on 4/21/19.
//  Copyright © 2019 Nick & Wolf. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp
#include "ParentObject.hpp"
class Action
{
public:
    virtual ~Action() {}
    virtual void execute(ParentObject& actor) = 0;
};

//define all actions here
class MoveUpCommand : public Action
{
public:
    virtual void execute(ParentObject& actor);
};
class MoveDownCommand : public Action
{
public:
    virtual void execute(ParentObject& actor);
};
class MoveLeftCommand : public Action
{
public:
    virtual void execute(ParentObject& actor);
};
class MoveRightCommand : public Action
{
public:
    virtual void execute(ParentObject& actor);
};
#endif /* Action_hpp */
