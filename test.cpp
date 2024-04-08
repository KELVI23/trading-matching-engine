/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char seperator)
{
	std::vector<std::string> tokens; 
	
	signed int start, end;
	std::string token;

	start = csvLine.find_first_not_of(seperator, 0);
	do {
		end = csvLine.find_first_of(seperator, start);

		//check if anything is inside token else break
		if (start == csvLine.length() || start == end) break;

		if (end >= 0) token = csvLine.substr(start, end - start);

		else token = csvLine.substr(start, csvLine.length() - start);

		tokens.push_back(token);
		start = end + 1;


	} while (end != std::string::npos); // find_first_not_of returns std::string::npos if it does not find the search term. 
	
	return tokens;
}

int main() 
{
	/*
	std::vector<std::string> tokens;
	std::string s = "thing, thing1, thing2";

	tokens = tokenise(s, ',');

	for (std::string& t : tokens) {
		std::cout << t << std::endl;
	}

	//read from file
	//call ifstream class and create csvFile object
	std::ifstream csvFile{"20200317.csv"};
	std::string line;
	std::vector<std::string> tokens;

	if (csvFile.is_open()) {
		std::cout << "File open" << std::endl;

		while (std::getline(csvFile, line)) {

			std::cout << "Read line" << line << std::endl;
			tokens = tokenise(line, ',');
			if (tokens.size() != 5) {
				std::cout << "Bad line" << std::endl;
				continue;
			}

			//we have 5 tokens
			//catch exception when it tries to convert an invalid string into a double
			try {
				double price = std::stod(tokens[3]);
				double amount = std::stod(tokens[4]);
			}catch (const std::exception& e) {
				std::cout << "Bad float!" << std::endl;
				continue;
			} 
			

			for (std::string& t : tokens) {
				std::cout << t << std::endl;
			}
		}
		
		
		csvFile.close();
	}

	else {
		std::cout << "Could not open file" << std::endl;
	}


	return 0;
}
*/