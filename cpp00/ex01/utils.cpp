#include <string>

std::string truncate(std::string input)
{
    if (input.length() > 10) {
        return (input.substr(0, 9) + ".");
    } else {
        return (input);
    }
}