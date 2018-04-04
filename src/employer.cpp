#include "employer.h"

Employer::Employer(std::string name_, std::string cpf_, Date *hired_at_): salary(1000.0), hired_at(10, 4, 2018) {
  name = name_;
  hired_at = *hired_at_;
  cpf = cpf_;
}

Employer::~Employer() {}

std::string Employer::getName() { return name; }
std::string Employer::getCPF() { return cpf; }
float Employer::getSalary() { return salary; }
Date Employer::getHiredAt() { return hired_at; }

bool Employer::matchCPF(std::string cpf_) {
  return (cpf.compare(cpf_) == 0);
}

void Employer::salaryIncrease(float perc) {
  salary +=salary*perc;
}

std::ostream& operator<<(std::ostream &o, Employer const employer) {
  o << employer.name;

  return o;
}
