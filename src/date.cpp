#include "date.h"

Date::Date(int day_, int month_, int year_) {
  day = day_;
  month = month_;
  year = year_;
}

bool operator<(const Date &init, const Date &finish) {
  if (finish.year > init.year) return true;
  else if (finish.month > init.month && finish.year == init.year) return true;
  else if (finish.day > init.day && finish.month == init.month && finish.year == init.year) return true;
  else return false;
}

bool operator>(const Date &init, const Date &finish) {
  if (finish.year < init.year) return true;
  else if (finish.month < init.month && finish.year == init.year) return true;
  else if (finish.day < init.day && finish.month == init.month && finish.year == init.year) return true;
  else return false;
}
