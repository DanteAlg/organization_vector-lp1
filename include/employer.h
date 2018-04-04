#ifndef EMPLOYER_H
#define EMPLOYER_H

#include "date.h"

#include <iostream>

class Employer {
  private:
    std::string cpf;
    std::string name;
    float salary;
    Date hired_at;

  public:
    Employer(std::string name_, std::string cpf_, Date *hired_at_);
    ~Employer();

    std::string getName();
    std::string getCPF();
    float getSalary();
    Date getHiredAt();

    void salaryIncrease(float perc);
    bool matchCPF(std::string cpf_);

    friend std::ostream& operator<<(std::ostream &o, Employer const f);
};
#endif
