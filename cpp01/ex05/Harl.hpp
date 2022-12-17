#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	error( void );
		void	warning( void );
		void	invalidLevel( std::string level );

	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level );
};

#endif