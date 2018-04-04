#ifndef DATE_H
#define DATE_H
class Date {
  private:
    int day;
    int month;
    int year;

  public:
    Date(int day_, int month_, int year_);

    friend bool operator<(const Date &init, const Date &finish);
    friend bool operator>(const Date &init, const Date &finish);
};
#endif
