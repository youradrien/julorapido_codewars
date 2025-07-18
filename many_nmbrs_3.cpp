#include <cstdint>
#include <optional>
#include <tuple>
#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> // For itoa (on some systems)
using out_t = std::tuple<std::uint32_t, std::uint64_t, std::uint64_t>;
static bool comp(uint32_t a, uint32_t b) 
{
    return a > b;
}
std::optional<out_t> find_all(std::uint32_t digit_sum, std::uint32_t digit_count)
{
  out_t T;
  std::vector<std::vector<char>> a;
  std::uint32_t 
      E = std::pow(10, digit_count - 1),
      F = std::pow(10, digit_count);
  for(std::uint32_t j = E; j < F; j ++)
  {
      std::uint32_t
                    sv = (j),
                    o = 0;
      std::ostringstream iss; iss << j;
      // sum digits
      std::string s = iss.str();
      std::vector<char> v;  
      for(uint32_t i = 0; i < s.length(); i++)
      {
        o += (std::uint32_t)(s[i] - '0');
        v.push_back(s[i]);   
      }
      if(s.find('0') != std::string::npos)
        continue;
      sort(v.begin(), v.end(), comp);
      std::vector<std::vector<char>>::iterator it;
      it = find(
          a.begin(), a.end(), (v)
      );
      if(it == a.end() && o == digit_sum)
      {
        std::get<0>(T)++; 
        if (std::get<1>(T) == 0)
         std::get<1>(T) = (sv);
        std::get<2>(T) = (sv);
        a.push_back(v);
      }
  }
  if (std::get<0>(T) == 0)
    return std::nullopt;
  return std::make_optional(T);
}
