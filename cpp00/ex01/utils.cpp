#include <string>

std::string truncate(std::string input)
{
	if (input.length() > 10) {
		return (input.substr(0, 9) + ".");
	} else {
		return (input);
	}
}

bool is_digits_only(std::string str)
{
	if (str.empty())
		return (false);
	for (std::size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}
