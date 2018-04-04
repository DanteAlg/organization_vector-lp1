#include "organization.h"

Organization::Organization(string name_, string cnpj_) {
  name = name_;
  cnpj = cnpj_;
}

Organization::~Organization() {}

bool Organization::invalidEmployer(Employer &f) {
  for(int i = 0; i <= employees.size(); i++) {
    if (employees[i] == f) return true;
  }

  return false;
}

void Organization::addEmployer(Employer *f) {
  if (invalidEmployer(*f)) {
    cout << "Erro: Funcionário já existe" << endl;
    return;
  }

  employees.push_back(*f);
}

void Organization::increaseSalaryFor(string cpf, float perc) {
  perc = perc/100;

  if (perc > 1 || perc < 0) {
    cout << "Erro: Percentual invalido, deve ser um valor entre 0 e 100" << endl;
    return;
  }

  for(int i = 0; i <= employees.size(); i++) {
    if (employees[i].matchCPF(cpf)) employees[i].salaryIncrease(perc);
  }
}

void Organization::hiredAfter(Date init_) {
  cout << "/* -------------------------------- */" << endl;

  cout << "name dos funcionários depois da data pesquisada: " << endl;

  for(int i = 0; i <= employees.size(); i++) {
    if (employees[i].getHiredAt() > init_)
      cout << "-> " << employees[i] << endl;
  }


  cout << "/* -------------------------------- */" << endl;
}

ostream& operator<<(ostream &o, Organization const empresa) {
  o << "/* -------------------------------- */" << endl;

  o << "name dos funcionários da empresa: " << endl;

  for(int i = 0; i < empresa.employees.size(); i++) {
    o <<  "-> " << empresa.employees[i] << endl;
  }

  o << "/* -------------------------------- */" << endl;

  return o;
}
