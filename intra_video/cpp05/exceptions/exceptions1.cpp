#include <stdexcept>

void    test1(void)
{
    try
    {
        //Do some stuff here
        if (/* there's an error*/)
        {
          throw std::exception();
        }
        else
        {
            //Do some more stuff
        }
    }
    catch(const std::exception e)
    {
        //Handle the error here
    }
}

void    test2(void)
{
    //Do some stuff here
    if (/* there's an error */)
    {
        throw std::exception();
    }
    else
    {
        //Do some more stuff
    }
}

void    test3(void)
{
    try
    {
        test2();
    }
    catch (const std::exception& e)
    {
        //handle error
    }
}

void    test4(void)
{
    class PEBKAException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Problem exists between keyboard and chair");
            }
    };

    try
    {
        test3();
    }
    catch (PEBKAException &e)
    {
        //Handle the fact that the user is an idiot
    }
    catch (std::exception &e)
    {
        //Handle other exceptions that are like std::exception
    }
}