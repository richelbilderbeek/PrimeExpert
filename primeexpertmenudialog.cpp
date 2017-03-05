#include "primeexpertmenudialog.h"

#include <cassert>
#include <iostream>

int ribi::PrimeExpertMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << this->GetHelp() << '\n';
    return 0;
  }
  std::cout << PrimeExpert().IsPrime(std::stoi(argv[1]) << '\n';
}

ribi::About ribi::PrimeExpertMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "PrimeExpert",
    "prime look-up table",
    "November 21sh of 2015",
    "2008-2015",
    "http://www.richelbilderbeek.nl/ToolPrimeExpert.htm",
    GetVersion(),
    GetVersionHistory()
  );
  return a;
}

ribi::Help ribi::PrimeExpertMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    }
    ,
    {

    }
  );
}

std::string ribi::PrimeExpertMenuDialog::GetVersion() const noexcept
{
  return "3.0";
}

std::vector<std::string> ribi::PrimeExpertMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2008-07-12: Version 1.0: initial version in C++ Builder",
    "2011-02-26: Version 2.0: port to Qt Creator",
    "2013-10-11: Version 2.1: conformized for ProjectRichelBilderbeek",
    "2013-11-04: Version 2.2: conformized for ProjectRichelBilderbeekConsole",
    "2015-11-21: Version 3.0: moved to own GitHub"
  };
}
