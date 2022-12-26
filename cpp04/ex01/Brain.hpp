#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain(void);
        Brain(const Brain &src);
        Brain &operator=(const Brain &rhs);
        virtual ~Brain(void);

        std::string getIdea(const int index) const;
        void setIdea(const int index, const std::string str);
        void printAll(void) const;
};

#endif