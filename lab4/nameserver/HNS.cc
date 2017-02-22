#include "nameserverinterface.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <hash>


using namespace std;
using IPAddress = unsigned int;
int size;

MNS::MNS(int size){
this.size = size;
vector<vector<pair<HostName&, const IPAddress>>> h;
}

void insert(const HostName&, const IPAddress&) {
  h.insert(HostName&, IPAddress&)

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
