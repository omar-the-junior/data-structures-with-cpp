#ifndef H_dateType
#define H_dateType

class dateType
{
public:
    void setDate(int month, int day, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void printDate() const;
    dateType(int month = 1, int daty = 1, int year = 2024);

private:
    int dMonth;
    int bDay;
    int dYear;
};

#endif