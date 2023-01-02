#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
    private:
        std::string _target;
        static const int RR_GRADE_TO_SIGN = 25;
        static const int RR_GRADE_TO_EXEC = 5;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
        virtual ~PresidentialPardonForm(void);

        const std::string & getTarget() const;

        void execute(Bureaucrat const & executor) const;
};

#endif
