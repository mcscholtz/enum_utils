#include "../enum_utils/enum.hpp"
#include <array>

using namespace enum_utils;

enum class TestEnum
{
    Test1,
    Test2,
    Test3
};

constexpr std::array<std::pair<TestEnum, const char *>, 3> map =
{
    {
        {TestEnum::Test1, "Test1"},
        {TestEnum::Test2, "Test2"},
        {TestEnum::Test3, "Test3"},
    }
};

int main()
{
    //conver the enum to the string found in the map
    constexpr const char* a = EnumToString(TestEnum::Test1, map);
    
    //typesafe conversion to string
    constexpr TestEnum b = StringToEnum("Test2", map);

    //compiler error
    //constexpr TestEnum c = StringToEnum("test2", map);
    return 0;
}