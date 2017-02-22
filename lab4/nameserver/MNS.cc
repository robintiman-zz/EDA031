#include "nameserverinterface.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
using IPAddress = unsigned int;

MNS::MNS(){
map<pair<string, IPAddress>> m;
}

void insert(const HostName&, const IPAddress&) {
  m.insert(HostName&, IPAddress&)
}

bool remove(const HostName&, const IPAddress&)  {
  m::iterator rem = find(HostName&);
  if (rem != m.end()) {
    v.erase(rem);
    return true;
    }
return false;
}


IPAddress lookup(const HostName&) {
  auto lo = find(HostName&);
  [&h] HostName& p ) {return p == h;});
		if (lo != m.end())  {
			return lo->p;
		}
		return NON_EXISTING_ADDRESS;
}

int main()  {

}
