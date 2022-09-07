#define MAP_MINIMUM 5

void vMapSize(int row, int col)
{
    /* Check within bounds else end program */
    if((row <= MAP_MINIMUM) || (col <= MAP_MINIMUM))
    {
        prinf("Invalid Map Size! Please ensure both map rows and columns are greater than 5\n");
        /* TODO : End Program */
    }
}

void vStartLocation(int coordx, int coordy, int max)
{
    if((coordx > max) || (coordx < 0))
    {
        prinf("Invalid Location! Please ensure parameters are within the map\n");
        /* TODO : End Program */
    }
}