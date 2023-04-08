#include <filesystem>
const std::string file_path = std::filesystem::current_path();

class SHIP{

    public:

    // ship will need to have an updated x and y location to check if ship is hitting a wall
    int x_location;
    int y_location;
    int width;
    int height;

    // if hit, will be set to false - will display explosion
    bool alive;
    
    // ship image location


    std::string sprite = file_path + "/Images/ship.png";
    std::string dead_sprite = file_path + "/Images/explosion.png";

};

class WALLS{

    public:
    // wall 1 and wall 2 will have width and hight
    int wall_x;
    int wall_y;
    
    // image file path
    std::string sprite = file_path + "/Images/walls.png";


};