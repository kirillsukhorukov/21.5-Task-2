#include <iostream>
#include <string>
#include <vector>

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
    int ceilingHeight=100;
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

//Функция ввода данных о поселке
void input_village_info(std::vector <Plot> &village)
{
    for (int v=0; v<village.size(); v++)
    {
        //Ввод данных об участке
        std::cout << "--- Entering plot number " << v+1 << " information ---" << std::endl;
        village[v].bildingCount = input_int("Enter the number of bildings: ");
        village[v].plotNumber = v+1;
        village[v].plotSquare = input_int("Enter the square of plot: ");
        std::cout <<std::endl;

        //Расширение вектора до размера, соответствующего количеству зданий на участке
        village[v].bildings.resize(village[v].bildingCount);

        //Ввод данных о зданиях
        for (int b=0; b<village[v].bildingCount; b++)
        {
            std::cout << "--- Entering bilding number " << b+1 << " information ---" << std::endl;
            village[v].bildings[b].bildingSquare = input_int("Enter the square of bilding: ");
            village[v].bildings[b].bildingType = input_bilding_type();
            std::cout <<std::endl;
        }
    }
}

int main()
{
    std::cout << "------ Village model ------" << std::endl << std::endl;
    
    //Ввод количества участков
    int plotCount = input_int("Enter the number of plots: ");
    std::cout <<std::endl;

    //Инициализация вектора поселка
    std::vector <Plot> village(plotCount);
    //village.push_back();
    
    //Ввод данных о поселке
    input_village_info(village);
    
    std::cout << std::endl << "Program completed. Press any key...";
    std::cin.get();
    return 1;
}