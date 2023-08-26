#include <iostream>
#include <vector>

//Перечисление построек
enum BildingType
{
    house,
    bath,
    garage,
    barn,
    paddock,
    veranda,
    toilet    
};

//Перечисление комнат
enum RoomType
{
    bedroom,
    kitchen,
    bathroom,
    childrens,
    livingRoom
};

//Структура комнаты
struct Room
{
    RoomType room;
    int roomSquare;
};

//Структура этажа
struct Floor
{
    int roomCount;
    int ceilingHeight;
    std::vector <Room> room();
};

//Структура строения
struct Bilding
{
    int bildingType;
    int floorCount;
    int bildingSquare;
    bool stove;
    std::vector <Floor> floor();
};

//Структура участка
struct Plot
{
int bildingCount=0;
int plotNumber=1;
int plotSquare=1;
std::vector <Bilding> bilding();
};

int main()
{
    std::cout << "------ Village model ------" << std::endl;
    return 1;
}