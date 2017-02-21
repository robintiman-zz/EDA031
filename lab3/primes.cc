#include <string>
#include <iostream>

using namespace std;

class Primes {
public:
  std::string calc_primes(std::size_t max);
};

string Primes::calc_primes(std::size_t max) {
  string primes (max, 'P');
  size_t index = 2;
  size_t factor = index;
  while (index < max) {
    index += factor;
    while (index < max) {
      primes.replace(index, 1, "C");
      index += factor;
    }
    index = primes.find_first_of('P', factor + 1);
    factor = index;
  }
  return primes;
}

int main() {
  Primes pr;
  string primes_200 = pr.calc_primes(200);
  std::cout << primes_200 << std::endl;
  string primes_1000 = pr.calc_primes(100000);
  size_t max_prime = primes_1000.find_last_of("P");
  std::cerr << "Largest prime < 100 000 is: " << max_prime << std::endl;

}
