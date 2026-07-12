#include <iostream>
#include <map> // Sorted: Self balancing binary tree (red-black tree)
#include <unordered_map> // Hash table, can be faster than map.
#include <vector>

struct CityRecord
{
	std::string Name;
	uint32_t Population;
	double Latitude, Longitude;

	bool operator<(const CityRecord& other) // Necessary if we want to use CityRecord as the key in a map, since we need to be able to sort using <.
	{
		return Population;
	}
};

namespace std // If we want to use CityRecord as the key, we need to specialize hash in std.
{
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key)
		{
			return hash<std::string>()(key.Name);
		}
	};
}

int main()
{
	std::vector<CityRecord> cities;
	cities.emplace_back("Melbourne", 500000, 2.4, 9.4);
	cities.emplace_back("Paris", 500000, 2.4, 9.4);
	cities.emplace_back("Berlin", 500000, 2.4, 9.4);
	cities.emplace_back("Madrid", 500000, 2.4, 9.4);


	for (const auto& city : cities)
	{
		if (city.Name == "Berlin")
		{
			city.Population;
			break;
		}
	}

	std::unordered_map<std::string, CityRecord> cityMap; // The string (key) goes through a hash function
	cityMap["Australia"] = CityRecord{"Melbourne", 500000, 2.4, 9.4};
	cityMap["Paris"] = CityRecord{"Paris", 500000, 2.4, 9.4};
	cityMap["Germany"] = CityRecord{"Berlin", 500000, 2.4, 9.4};
	cityMap["Spain"] = CityRecord{"Madrid", 500000, 2.4, 9.4};

	CityRecord& berlinData = cityMap["Germany"];  // if "Germany" does not exist, it will be inserted into the map
	const CityRecord& santaCruzData = cityMap.at("Bolivia"); // this will not insert an object to the map if it doesn't exist. Crashes if not there.
	if (cityMap.find("La Paz") != cityMap.end()); // Use this instead to avoid crash

	std::unordered_map<CityRecord, std::string> foundedMap; // CityRecord as key is only possible because we specalized the hashing.

	// Iterating through a map

	for (auto& [name, city] : cityMap)
	{
		std::cout << city.Name << ", " << "Population: " << city.Population << '\n';
	}

	cityMap.erase("Australia"); // Deleting an element within the map.

}

/*
Useful for retrieving specific elements without (potentially) searching through the whole collection.
*/