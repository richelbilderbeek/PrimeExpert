#ifndef PRIMEEXPERT_H
#define PRIMEEXPERT_H

#include <string>
#include <vector>

namespace ribi {

struct PrimeExpert
{
  PrimeExpert();

  bool IsPrime(const int x);

  static std::string GetVersion() noexcept;
  static std::vector<std::string> GetVersionHistory() noexcept;

  private:
  std::vector<int> mPrimes;

  void CalculateNextPrime();
  int CalculateMax(const int x);
  friend std::ostream& operator<<(std::ostream&, const PrimeExpert&);

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

std::ostream& operator<<(std::ostream& os, const PrimeExpert& primeExpert);

} //~namespace ribi

#endif // PRIMEEXPERT_H
