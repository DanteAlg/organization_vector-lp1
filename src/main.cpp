#include <iostream>

#include "date.h"
#include "employer.h"
#include "organization.h"

#define CPF_1 "42469544203"
#define CPF_2 "47845974250"
#define CPF_3 "56621654677"

int main() {
  Organization empresa("Nome fantasia LTDA", "86570828000109");

  empresa.addEmployer(new Employer("Fulaninho da silva", CPF_1, new Date(15, 3, 2018)));
  empresa.addEmployer(new Employer("Lorem ipsun dollor", CPF_2, new Date(1, 3, 2018)));
  empresa.addEmployer(new Employer("Foo bar", CPF_3, new Date(29, 3, 2018)));

  // Deve dar erro neste funcionario, já existe funcionario com CPF_3
  empresa.addEmployer(new Employer("Funcionário com erro", CPF_3, new Date(29, 3, 2018)));

  // Lista funcionários da empresa
  std::cout << empresa;

  // Funcionario Foo bar deve receber um aumento de 50% e ficar com R$1500
  empresa.increaseSalaryFor(CPF_3, 50);

  // Imprime funcionarios: Fulaninho da silva e Foo bar
  empresa.hiredAfter(new Date(10, 3, 2018));

  return 0;
}
