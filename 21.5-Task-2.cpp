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
    RoomType roomType;
    int roomSquare;
};

//Структура этажа
struct Floor
{
    int roomCount;
    int ceilingHeight;
    std::vector <Room> rooms;
};

//Структура строения
struct Bilding
{
    BildingType bildingType;
    int floorCount=1;
    int bildingSquare;
    bool stove = false;
    std::vector <Floor> floors;
};

//Структура участка
struct Plot
{
int bildingCount;
int plotNumber;
int plotSquare;
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

int input_int (std::string str)
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
        if (str == "house") return house;
        else if (str == "bath") return bath;
        else if (str == "garage") return garage;
        else if (str == "barn") return barn;
        else if (str == "paddock") return paddock;
        else if (str == "veranda") return veranda;
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
        if (str == "bedroom") return bedroom;
        else if (str == "kitchen") return kitchen;
        else if (str == "bathroom") return bathroom;
        else if (str == "childrens") return childrens;
        else if (str == "living room") return livingRoom;
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

        //Ввод данных о зданиях
        for (int b=0; b<village[v].bildingCount; b++)
        {
            std::cout << "--- Entering bilding number " << b+1 << " information ---" << std::endl;
            village[v].bildings[b].bildingType = input_bilding_type();
            village[v].plotNumber = v+1;
            village[v].plotSquare = input_int("Enter the square of plot: ");
        }
    }
}

int main()
{
    std::cout << "------ Village model ------" << std::endl << std::endl;
    
    //Ввод количества участков
    int plotCount = input_int("Enter the number of plots: ");

    //Инициализация вектора поселка
    std::vector <Plot> village(plotCount);
    
    //Ввод данных о поселке
    input_village_info(village);
    
    std::cout << std::endl << "Program completed. Press any key...";
    std::cin.get();
    return 1;
}