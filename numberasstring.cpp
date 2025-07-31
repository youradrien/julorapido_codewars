#include <iostream>
#include <string>

using namespace std;

static std::string clear_zeros(std::string s)
{
  std::string new_s;
  uint32_t i = 0;
  while(s[i] == '0')
    i++;
  for(; i < s.length(); i++)
    new_s.push_back(s[i]);
  return new_s;
}
string multiply(string a, string b) 
{
  if(a == "0" || b == "0")
    return ("0");
  std::cout << a << " x " << b << std::endl;
  a = clear_zeros(a), b = clear_zeros(b);
  std::vector<uint32_t> v;
  std::map<int, std::vector<uint32_t>> m;
  //       987
  //  x     43
  //  ________
  //        21
  //       24
  //      27
  for(unsigned long i = 0; i < b.length(); i++)
  {
    uint32_t 
          ix = b.length() - 1 - (i),
          n = b[ix] - '0',
          c = 0;
    for(int j = a.length() - 1; j >= 0; j--)
    {
        uint32_t res = n * (a[j] - '0');
        //std::cout << n << "*" << a[j] - '0' << "= " << res/10 << res % 10 << ", ";
        m[i + c].push_back(res % 10);
        if(res / 10 > 0)
          m[i + c + 1].push_back(res / 10);
        c++;
    }
    //std::cout <<std::endl;
  }
  std:: string sol;
  for(uint32_t i = 0; i < 1000; i++)
  {
    if(m[i].size() == 0) continue;
    uint32_t sum = 0;
    for(unsigned long j = 0; j < m[i].size(); j++){
      sum += m[i][j];
    }
    sol.push_back((sum % 10) + '0');
    if(sum / 10 > 0 )
      m[i + 1].push_back(sum / 10);
  }
  std::reverse(sol.begin(), sol.end());
  std::cout << sol << std::endl;
  return sol;
}
