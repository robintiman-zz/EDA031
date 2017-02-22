#include "nameserverinterface.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
using IPAddress = unsigned int;
const IPAddress NON_EXISTING_ADDRESS = 0;

VNS::VNS(){
vector<tuple<string, IPAddress>> v;
}

void insert(const HostName&, const IPAddress&) {
  v.emblace_back(HostName&, IPAddress&)
}

bool remove(const HostName&, const IPAddress&)  {
  auto v::iterator rem = find(v.begin(), v.end(), tuple<string, IPAddress>)
  if (rem != v.end()) {
    v.erase(rem);
    return true;
    }
return false;
}


IPAddress lookup(const HostName&) {
  auto lo = find_if(v.begin(), v.end(),
  [&h](tuple<HostName, IPAddress> p) {return p[0] == h;});
		if (lo != v.end()){
			return lo->p[1];
		}
		return NON_EXISTING_ADDRESS;
}

int main()  {

}
