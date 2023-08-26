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
    std::vector <Room> room();
};

//Структура строения
struct Bilding
{
    BildingType bildingType;
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

//Функция ввода данных о поселке
void input_data(std::vector <Plot> &village)
{
    
}

int main()
{
    std::cout << "------ Village model ------" << std::endl << std::endl;
    
    //Ввод количества участков
    int plotCount = input_int("Enter the number of plots: ");

    std::cout << plotCount << std::endl;

    //Инициализация вектора поселка
    std::vector <Plot> village(plotCount);
    
    //Ввод данных о поселке
    input_data(village);
    
    std::cout << std::endl << "Program completed. Press any key...";
    std::cin.get();
    return 1;
}