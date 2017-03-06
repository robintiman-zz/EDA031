#include <string>
#include <vector>
#include <iostream>

#include "nameserverinterface.h"
#include "HNS.h"

using namespace std;


	HNS::HNS(int size) {
		table_size = size;
		server = vector< pair<HostName, IPAddress> > (size);
	}


	HNS::~HNS() {
		server.clear();
	}

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void HNS::insert(const HostName& hn, const IPAddress& adress){
		std::hash<string> hasher;
		size_t hash = hasher(hn) % table_size;
		while (server[hash].first != "") hash = (hash + 1) % table_size;
		server[hash] = make_pair(hn, adress);
	}
	
	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool HNS::remove(const HostName& hn){
		
		std::hash<string> hasher;
		size_t hash = hasher(hn) % table_size;
		while (server[hash].first != hn && server[hash].first != "") hash = (hash + 1) % table_size;
		if (server[hash].first == ""){
			return false;
		}
		server[hash].first = "";
		return true;
	}
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress HNS::lookup(const HostName& hn) const{
		std::hash<string> hasher;
		size_t hash = hasher(hn) % table_size;
		while (server[hash].first != hn && server[hash].first != "") hash = (hash + 1) % table_size;
		if (server[hash].first == ""){
			return NON_EXISTING_ADDRESS;
		}
		return server[hash].second;
	}


// int main(int argc, char const *argv[])
// {
// 	HNS v = HNS(10);
// 	v.insert("11", 111);
// 	v.insert("12", 112);
// 	v.insert("13", 113);
// 	v.insert("14", 114);
// 	v.insert("10", 110);
// 	cout << v.lookup("11") << endl;
// 	v.remove("11");
// 	cout << v.lookup("11") << endl;
// 	return 0;
// }



