#if false
//modification in monster.h
protected:
float speed;

public:
int direction, // 0,1,2,3 stands for left, right, up, down

void Monster :: Move(int direction, float speed)
{
    //todo move at the current direction at current speed for one brick
}
void Monster :: randomMoving()
// in this function the Monster is Moving randomly on the map and when it meets obstacles it turns back.
{
    if (alarmed = false) // if not alarmed keep randomMoving
    {
        direction = rand()%4;
        if ( getTrav() = false )//if it didn't hit a obstacle
        {
            Move();
        }
        else 
        {
            randomMoving();// if meet obstacle reset direction
        } 

    }
    else return 0; //stop if alarmed
}

void Monster :: towardObject()
// in this function the Monster is alarmed and will move to the object.
{
    if (x > = (player.getX() - atkRadius)) // if out of attacking range at right, move left, etc
    {
        direction = 1;
        Move();
        towardObject();
    }
    else if (x < = (player.getX() - atkRadius))
    {
        direction = 0;
        Move();
        towardObject();
    }
    else if (y > = (player.getY() - atkRadius))
    {
        direction = 3;
        Move();
        towardObject();
    }
    else if (y < = (player.getY() - atkRadius))
    {
        direction = 2;
        Move();
        towardObject();
    }
    else return 0;// stop if reached attack range.
}
#endif