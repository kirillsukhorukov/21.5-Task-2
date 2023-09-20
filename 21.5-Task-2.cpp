#include <iostream>
#include <string>
#include <vector>

int MAX_FLOORS = 3;
int MIN_ROOMS = 2;
int MAX_ROOMS = 4;

//Перечисление построек
enum BildingType
{
    house,
    bath,
    garage,
    barn,
    paddock,
    veranda  
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
    RoomType roomType;
    int roomSquare=0;
};

//Структура этажа
struct Floor
{
    Floor():rooms(roomCount){};
    int roomCount=1;
    int ceilingHeight=250;
    std::vector <Room> rooms{};
};

//Структура строения
struct Bilding
{
    Bilding():floors(floorCount){};
    BildingType bildingType;
    int floorCount=1;
    int bildingSquare=0;
    bool stove = false;
    std::vector <Floor> floors{};
};

//Структура участка
struct Plot
{
    Plot():bildings(bildingCount){}
    int bildingCount=0;
    int plotNumber=0;
    int plotSquare=0;
    std::vector <Bilding> bildings;
};

//Функция проверки строки с целым числом
bool check_int(std::string &num)
{
    //Проверка длины строки с числом
    if (num.length() > 9)
    {
        std::cerr << std::endl << "Error! The number is not a positive integer!" << std::endl;
        return false;
    }
    else 
    {
        //Проверка что все символы являются числами
        for (int i = 0; i < num.length(); i++)
        {
            if (!isdigit(num[i]))
                {
                    std::cerr << std::endl << "Error! The number is not a positive integer!" << std::endl;
                    return false;
                }
        }
    }
    return true;
}

int input_int (const std::string &str)
{
    std::string temp;
    
    do
    {
        std::cout << str;
        std::getline(std::cin, temp);
    } while (!check_int(temp));

    int num = stoi (temp);
    return num;
}

//Функция ввода типа здания
BildingType input_bilding_type ()
{
    bool error = false;
    std::string str;
    do
    {
        error = false;
        std::cout << "Enter the type of bilding (house, bath, garage, barn, paddock, veranda): ";
        std::getline(std::cin,str);
        if (str == "house") return BildingType::house;
        else if (str == "bath") return BildingType:: bath;
        else if (str == "garage") return BildingType::garage;
        else if (str == "barn") return BildingType::barn;
        else if (str == "paddock") return BildingType::paddock;
        else if (str == "veranda") return BildingType::veranda;
        else 
        {
            std::cerr <<"Error! Repeat input." << std::endl;
            error = true;
        }
    } while (error);
}

//Функция ввода типа комнаты
RoomType input_room_type ()
{
    bool error = false;
    std::string str;
    do
    {
        error = false;
        std::cout << "Enter the type of room (bedroom, kitchen, bathroom, childrens, living room): ";
        std::getline(std::cin,str);
        if (str == "bedroom") return RoomType::bedroom;
        else if (str == "kitchen") return RoomType::kitchen;
        else if (str == "bathroom") return RoomType::bathroom;
        else if (str == "childrens") return RoomType::childrens;
        else if (str == "living room") return RoomType::livingRoom;
        else 
        {
            std::cerr <<"Error! Repeat input." << std::endl;
            error = true;
        }
    } while (error);
}

//Функция ввода данных о наличии печи с трубой
bool presence_stove()
{
    bool error = false;
    std::string str;
    do
    {
        error = false;
        std::cout << "Does the building have a stove with a chimney? (Yes/No): ";
        std::getline(std::cin,str);
        if (str == "Yes") return true;
        else if (str == "No") return false;
        else 
        {
            std::cerr <<"Error! Repeat input." << std::endl;
            error = true;
        }
    } while (error);
}

//Функция ввода данных о поселке
void input_village_info(std::vector <Plot> &village)
{
    for (int v=0; v<village.size(); v++)
    {
        //Ввод данных об участке
        std::cout << std::endl << "--- Entering plot number " << v+1 << " information ---" << std::endl;
        village[v].bildingCount = input_int("Enter the number of bildings: ");
        village[v].plotNumber = v+1;
        village[v].plotSquare = input_int("Enter the square of plot (m^2): ");

        //Расширение вектора до размера, соответствующего количеству зданий на участке
        village[v].bildings.resize(village[v].bildingCount);

        //Ввод данных о зданиях
        for (int b=0; b<village[v].bildingCount; b++)
        {
            std::cout << std::endl << "--- Entering bilding number " << b+1 << " information ---" << std::endl;
            village[v].bildings[b].bildingSquare = input_int("Enter the square of bilding (m^2): ");
            village[v].bildings[b].bildingType = input_bilding_type();
            //Ввод данных о наличии трубы в бане
            if (village[v].bildings[b].bildingType == BildingType::bath) village[v].bildings[b].stove = presence_stove();
            //Ввод данных о доме
            if (village[v].bildings[b].bildingType == BildingType::house)
            {
                village[v].bildings[b].stove = presence_stove();
                do
                {
                    village[v].bildings[b].floorCount = input_int("Enter the number of floors (from 1 to 3): ");
                } while (village[v].bildings[b].floorCount>MAX_FLOORS);

                //Расширение вектора до размера, соответствующего количеству этажей в доме
                village[v].bildings[b].floors.resize(village[v].bildings[b].floorCount);

                //Ввод данных о этаже
                for (int f=0; f<village[v].bildings[b].floorCount; f++)
                {
                    std::cout << std::endl << "--- Entering floor number " << f+1 << " information ---" << std::endl;
                    village[v].bildings[b].floors[f].ceilingHeight = input_int("Enter the height of the ceilings on the floor (cm): ");
                    do
                    {
                        village[v].bildings[b].floors[f].roomCount = input_int("Enter the number of rooms (from 2 to 4): ");
                    } while (village[v].bildings[b].floorCount<MIN_ROOMS || village[v].bildings[b].floorCount>MAX_ROOMS);

                    //Расширение вектора до размера, соответствующего количеству комнат на этаже
                    village[v].bildings[b].floors[f].rooms.resize(village[v].bildings[b].floors[f].roomCount);

                    //Ввод данных о комнате
                    for (int r=0; r<village[v].bildings[b].floors[f].roomCount; r++)
                    {
                        std::cout << std::endl << "--- Entering room number " << r+1 << " information ---" << std::endl;
                        village[v].bildings[b].floors[f].rooms[r].roomSquare = input_int("Enter the square of room (m^2): ");
                        village[v].bildings[b].floors[f].rooms[r].roomType = input_room_type();
                    }
                }
            }
        }
    }
}

//Функция подсчета количества зданий в поселке
void count_buildings(std::vector <Plot> &village)
{
    int count = 0;
    for (int v=0; v<village.size(); v++)
    {
        count += village[v].bildingCount;
    }

    std::cout << std::endl << "Number of buildings in the village: " << count << std::endl;
}

int main()
{
    std::cout << "------ Village model ------" << std::endl << std::endl;
    
    //Ввод количества участков
    int plotCount = input_int("Enter the number of plots: ");
    std::cout <<std::endl;

    //Инициализация вектора поселка
    std::vector <Plot> village(plotCount);
    
    //Ввод данных о поселке
    input_village_info(village);

    //Функция подсчета количества зданий в поселке
    count_buildings(village);
    
    std::cout << std::endl << "Program completed. Press any key...";
    std::cin.get();
    return 1;
}