#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <vector>
#include <iostream>

#include "employer.h"
#include "organization.h"

using namespace std;

class Registration {
  private:
    vector <Organization> organizations;

    int mainMenu();
    void createOrganization();
    void listEmployees();
    void listOrganizations();
    void increaseSalary();
    void employeesMedia();
    void employeesHiredAfter();
    int organizationMenu(Organization &organization);

  public:
    void run();
};
#endif
