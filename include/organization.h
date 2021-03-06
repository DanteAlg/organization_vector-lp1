#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "employer.h"

#include <vector>
#include <iostream>

using namespace std;

class Organization {
  private:
    string name;
    string cnpj;
    vector <Employer> employees;

    bool invalidEmployer(Employer &f);

  public:
    Organization(string name_, string cnpj_);
    ~Organization();

    string getName();
    string getCNPJ();
    int employeesCount();

    void addEmployer(Employer *f);
    void increaseSalaryFor(string cpf, float perc);
    void hiredAfter(Date *init_);
    bool matchCNPJ(string cnpj_);

    friend ostream& operator<<(ostream &o, Organization const empresa);
};
#endif
