#include <bits/stdc++.h>
using namespace std;
template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            return first;
        }
    }
    return last;
}
int main(){
 int n1 = 3;
    int n2 = 5;
 
    std::vector<int> v{0, 1, 2, 3, 4};
  std::vector<int>::iterator i = std::find_if(v.begin(),
    v.end(), 
    [&](const auto& val){ return val.m_id ==m_id; } );
}
