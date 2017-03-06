#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "nameserverinterface.h"
#include "UMNS.h"

using namespace std;


	UMNS::UMNS() {

	}

	UMNS::~UMNS() {
		server.clear();
	}

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void UMNS::insert(const HostName& hn, const IPAddress& adress)  {
		
		server[hn] = adress;
	}
	
	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool UMNS::remove(const HostName& hn)  {
	
		auto it = server.find(hn);
		if (it != server.end()) {
			server.erase(it);
			return true;
		}
		return false;
	}
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress UMNS::lookup(const HostName& hn) const {
		auto it = server.find(hn);
		if(it != server.end()) return it->second;
		return NON_EXISTING_ADDRESS;
	}



  


// int main(int argc, char const *argv[] ){
//         UMNS v = UMNS();
//         v.insert("123",1234);
//         v.insert("122",1224);
//         v.insert("10", 1000);
//         v.remove("10");
//        cout << v.lookup("123") << endl;
// };



