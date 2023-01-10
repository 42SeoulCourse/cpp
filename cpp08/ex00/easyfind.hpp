#ifndef EASYFINE_HPP
# define EASYFINE_HPP

#include <algorithm>

template< typename T >
typename T::iterator    easyfind( T &container, int &value)
{
    return ( std::find( container.begin(), container.end(), value ) );
}

#endif