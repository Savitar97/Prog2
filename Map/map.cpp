#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

std::vector<std::pair<std::string, int>> sort_map ( std::map <std::string, int> &rank )
{
        std::vector<std::pair<std::string, int>> ordered;

        for ( auto & i : rank ) {
                if ( i.second ) {
                        std::pair<std::string, int> p {i.first, i.second};
                        ordered.push_back ( p );
                }
        }

        std::sort (
                std::begin ( ordered ), std::end ( ordered ),
        [ = ] ( auto && p1, auto && p2 ) {
                return p1.second > p2.second;
        }
        );

        return ordered;
}



 
int main()
{

    std::map<std::string, int> mapOfWords;
    mapOfWords.insert(std::make_pair("earth", 4));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords.insert(std::make_pair("jupiter", 10));
    mapOfWords.insert(std::make_pair("mars", 7));
    mapOfWords.insert(std::make_pair("saturnus", 9));
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
        it++;
    }
      std::vector<std::pair<std::string, int>> rendezett=sort_map(mapOfWords);
      std::cout<<
    for ( auto & i : rendezett )
                std::cout << i.first << " - "  << i.second << std::endl;
    return 0;
}