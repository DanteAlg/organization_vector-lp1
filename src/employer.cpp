#include "employer.h"

Employer::Employer(std::string name_, std::string cpf_, Date *hired_at_): salary(1000.0), hired_at(10, 4, 2018) {
  name = name_;
  hired_at = *hired_at_;
  cpf = cpf_;
}

Employer::~Employer() {}

std::string Employer::getName() { return name; }
std::string Employer::getCPF() { return cpf; }
Date Employer::getHiredAt() { return hired_at; }

bool Employer::matchCPF(std::string cpf_) {
  return (cpf.compare(cpf_) == 0);
}

void Employer::salaryIncrease(int perc) {
  salary += salary*perc;
}

bool operator==(Employer &f, Employer &employer) {
  return f.matchCPF(employer.getCPF());
}

std::ostream& operator<<(std::ostream &o, Employer const employer) {
  o << employer.name;

  return o;
}
