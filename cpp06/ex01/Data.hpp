#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data{
  private:
   std::string _data;

    public:
     Data();
     Data(const Data &rhs);
     Data &operator=(const Data &rhs);
     ~Data();

     void setData(std::string str);
     std::string getData() const;
};

#endif