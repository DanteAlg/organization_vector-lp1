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
    Date getHiredAt();

    void salaryIncrease(int perc);
    bool matchCPF(std::string cpf_);

    friend bool operator==(Employer const f, Employer const f_);
    friend std::ostream& operator<<(std::ostream &o, Employer const f);
};
#endif
