#include "registration.h"

void Registration::run() {
  int choice;
  bool on_prog = true;

  while (on_prog) {
    choice = mainMenu();

    if (choice == 1)
      createOrganization();
    else if (choice == 2)
      listEmployees();
    else if (choice == 3)
      increaseSalary();
    else if (choice == 4)
      listOrganizations();
    else if (choice == 5)
      employeesMedia();
    else if (choice == 6)
      employeesHiredAfter();
    else
      on_prog = false;
  }
}

// Private methods

int Registration::mainMenu() {
  int choice = -1;

  while (choice < 0) {
    cout << "Registro de empresas" << endl;
    cout << "1 - Criar nova empresa" << endl;
    cout << "2 - Listar funcionários de uma empresa" << endl;
    cout << "3 - Dar aumento a um funcionário" << endl;
    cout << "4 - Listar empresas" << endl;
    cout << "5 - Média de funcionários por empresa" << endl;
    cout << "6 - Listar funcionários apos data" << endl;
    cout << "7 - Sair" << endl;
    cout << "Digite sua opção: ";

    cin >> choice;

    if (choice < 8 && choice > 0) {
    }
    else {
      cout << "INVALIDO" << endl;
      choice = -1;
    }
  }

  return choice;
}

int Registration::organizationMenu(Organization &organization) {
  int choice = -1;

  while (choice < 0) {
    cout << "Configuração da empresa - " << organization.getName() << endl;
    cout << "1 - Adicionar funcionário" << endl;
    cout << "2 - Listar funcionários" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite sua opção: ";

    cin >> choice;

    if (choice < 4 && choice > 0) {
    }
    else {
      cout << "INVALIDO" << endl;
      choice = -1;
    }
  }

  return choice;
}

void Registration::createOrganization() {
  int choice;
  bool on_creating = true;
  string name, cnpj;

  int day, month, year;
  string cpf, employee_name;

  cout << "Digite o cnpj: ";
  cin >> cnpj;
  cout << "\nDigite o nome da empresa: ";
  cin >> name;
  cout << endl;

  Organization organization(name, cnpj);

  while(on_creating) {
    choice = organizationMenu(organization);

    if (choice == 1) {
      cout << "Digite o nome do funcionario: ";
      cin >> employee_name;
      cout << "\nDigite o cpf do funcionario: ";
      cin >> cpf;
      cout << "\nDigite o dia que o funcionario foi contratado: ";
      cin >> day;
      cout << "\nDigite o mes que o funcionario foi contratado: ";
      cin >> month;
      cout << "\nDigite o ano que o funcionario foi contratado: ";
      cin >> year;

      organization.addEmployer(new Employer(employee_name, cpf, new Date(day, month, year)));
    }
    else if (choice == 2) {
      cout << organization;
    }
    else {
      on_creating = false;
    }
  }

  organizations.push_back(organization);
}

void Registration::listEmployees() {
  for(int i = 0; i < organizations.size(); i++) {
    std::cout << "Empresa: " << organizations[i].getName() << endl;
    std::cout << organizations[i];
  }
}

void Registration::increaseSalary() {
  int perc;
  string cnpj, cpf;

  cout << "Digite o cnpj da empresa: ";
  cin >> cnpj;
  cout << "\nDigite o cpf: ";
  cin >> cpf;
  cout << "\nDigite o percentual de aumento (0 - 100): ";
  cin >> perc;
  cout << endl;

  for(int i = 0; i < organizations.size(); i++) {
    if (organizations[i].matchCNPJ(cnpj))
      organizations[i].increaseSalaryFor(cpf, perc);
  }
}

void Registration::listOrganizations() {
  cout << "Empresas ----------------------- >" << endl;

  for(int i = 0; i < organizations.size(); i++) {
    cout << organizations[i].getName() << " - "<< organizations[i].getCNPJ() << endl;
  }
}

void Registration::employeesMedia() {
  int organization_count = organizations.size();
  int employees_count = 0;

  for(int i = 0; i < organizations.size(); i++) {
    employees_count += organizations[i].employeesCount();
  }

  cout << "Média de funcionários por empresa: " << employees_count/organization_count << " Funcionários por empresa" << endl;
}

void Registration::employeesHiredAfter() {
  string cnpj;
  int day, month, year;

  cout << "Digite o cnpj da empresa que quer listar os funcionários: ";
  cin >> cnpj;
  cout << "\nDigite o dia: ";
  cin >> day;
  cout << "\nDigite o mes: ";
  cin >> month;
  cout << "\nDigite o ano: ";
  cin >> year;
  cout << endl;

  for(int i = 0; i < organizations.size(); i++) {
    if (organizations[i].matchCNPJ(cnpj))
      organizations[i].hiredAfter(new Date(day, month, year));
  }
}
