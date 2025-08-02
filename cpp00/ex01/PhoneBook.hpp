 #ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        
        void    add();
        void    search(int);

    private:
        Contact contacts[8];
        std::size_t _count;

};

#endif