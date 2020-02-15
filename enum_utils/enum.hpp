#pragma once
#include <array>
#include <limits>
#include <string_view>

namespace enum_utils
{

template <class ENUM_TYPE, size_t SIZE>
constexpr ENUM_TYPE StringToEnum(const char * value, 
    std::array<std::pair<ENUM_TYPE, const char *>, SIZE> map, size_t index = std::numeric_limits<std::size_t>::max())
{
	index = (index == std::numeric_limits<std::size_t>::max()) ? map.size() : index;
	return
		(index == 0) ? throw std::out_of_range("Value not in map"):
		(std::string_view(map[index - 1].second) == value) ? map[index- 1].first:
		StringToEnum(value, map, index - 1);
};

template <class ENUM_TYPE, size_t SIZE>
constexpr const char * EnumToString(ENUM_TYPE key, 
    std::array<std::pair<ENUM_TYPE, const char *>, SIZE> map, size_t index = std::numeric_limits<std::size_t>::max())
{
	index = (index == std::numeric_limits<std::size_t>::max()) ? map.size() : index;
	return
		(index == 0) ? throw std::out_of_range("Key not in map"):
		(map[index - 1].first == key) ? map[index- 1].second:
		EnumToString(key, map, index - 1);
};

}