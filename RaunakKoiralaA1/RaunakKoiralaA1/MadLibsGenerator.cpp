/**************************************************
  Project: The Amazing Mad Lib Story Generator: Assignment 1
  Author: Raunak Koirala
  Student No. 32509987
  Purpose: Writing tool using Mad Libs word game to create a
  fun and interactive story.

 **************************************************/

//The app must load mad libs and mad libs before every generate mad lib function is pressed



#include "MadLibsGenerator.h"

std::string final;
std::vector<std::string>madlibs;
std::vector<std::string>madbits;


void runMenu() { //displays the main menu 

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "    The Amazing Mad Lib Story Generator" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "[0] End Testing the Program" << std::endl
		<< "[1] Display \"About\" Information" << std::endl
		<< "[2] Read and store data from files" << std::endl
		<< "[3] Generate a random Mad Lib" << std::endl
		<< "[4] Save a Mad Lib to file" << std::endl
		<< "[5] Load saved Mad Libs from file" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Which option would you like (0-5): " << std::endl;
}

void displayTextData(std::string filename) { //displays an information screen

	std::cout << std::endl; //go to next line
	std::ifstream file; //stream class to both read and write from/to files.
	file.open(filename);

	if (file.peek() == std::ifstream::traits_type::eof()) {//notifies user if file is not found or null
		std::cout << "Can't find file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {//loop to read lines in text file
		std::cout << line << std::endl;
	}
	file.close();//close file

}


std::vector<std::string> createListOne(std::string firstFilename) { //gets data from madlibs file and stores in vector


	std::ifstream file;
	file.open(firstFilename);

	std::string data;

	if (file.peek() == std::ifstream::traits_type::eof()) {
		return madlibs;
	}

	while (std::getline(file, data)) {
		madlibs.push_back(data);
	}

	file.close();


	return madlibs;

}

std::vector<std::string> createListTwo(std::string secondFilename) { //gets data from madbits file and stores in vector


	std::ifstream secondFile;
	secondFile.open(secondFilename);

	std::string secondData;

	if (secondFile.peek() == std::ifstream::traits_type::eof()) {
		return madbits;
	}

	while (std::getline(secondFile, secondData)) {
		madbits.push_back(secondData);
	}

	secondFile.close();

	return madbits;

}






void saveMadLib(std::string result, std::string filename) { //saves the most recently generated mad lib in the savedMadLiv.txt file

	


	std::string savedLib = result;

	std::ofstream file_out;

	file_out.open(filename, std::ios_base::app);
	file_out << result << std::endl;

}





std::string generateMadLib(std::vector<std::string>madLibs, std::vector<std::string>madBits) { //generates a mad lib sentence from user input

	int random_number = (rand() % 10) + 1;

	std::string selectedMadLib = madBits[random_number];
	std::string temp;

	int index;

	std::string first;
	std::string second;
	std::string third;
	std::string fourth;


	std::string selectedMadBits = madLibs[random_number];

	std::string result;
	std::string p;


	for (int i = 0; i < 3; i++) {

		std::cout << " " << std::endl;
		if (selectedMadLib.find(',') != std::string::npos) { //finds "," to perfrom string slicing
			index = selectedMadLib.find(',');
			temp = selectedMadLib.substr(0, index); // found
			std::cout << "Enter "; 
			std::cout << temp;
			std::cout << ": ";
			std::cin >> first; //user input
		}




		selectedMadLib = selectedMadLib.substr(index + 1, -1);


		if (selectedMadLib.find(',') != std::string::npos) {
			index = selectedMadLib.find(',');
			temp = selectedMadLib.substr(0, index); // found
			std::cout << "Enter ";
			std::cout << temp;
			std::cout << ": ";
			std::cin >> second;
		}

		selectedMadLib = selectedMadLib.substr(index + 1, -1);

		if (selectedMadLib.find(',') != std::string::npos) {
			index = selectedMadLib.find(',');
			temp = selectedMadLib.substr(0, index); // found
			std::cout << "Enter ";
			std::cout << temp;
			std::cout << ": ";
			std::cin >> third;
		}

		selectedMadLib = selectedMadLib.substr(index + 1, -1);

		if (selectedMadLib.find(';') != std::string::npos) {
			index = selectedMadLib.find(';');
			temp = selectedMadLib.substr(0, index); // found
			std::cout << "Enter ";
			std::cout << temp;
			std::cout << ": ";
			std::cin >> fourth;
		}






		index = selectedMadBits.find('W');



		selectedMadBits = selectedMadBits.replace(selectedMadBits.find("WORD"), 4, first);
		p = selectedMadBits;
		p = p.substr(0, index + first.size());

		if (i >= 1) {
			result += " ";
		}

		result += p;
		result += " ";


		selectedMadBits = selectedMadBits.substr(index + first.size() + 1, -1);




		//Find W's in order to format to where WORD is located within the sentence (string slicing and replacing)
		index = selectedMadBits.find('W');



		selectedMadBits = selectedMadBits.replace(selectedMadBits.find("WORD"), 4, second);
		p = selectedMadBits;
		p = p.substr(0, index + second.size());
		result += p;
		result += " ";


		selectedMadBits = selectedMadBits.substr(index + second.size() + 1, -1);




		index = selectedMadBits.find('W');



		selectedMadBits = selectedMadBits.replace(selectedMadBits.find("WORD"), 4, third);
		p = selectedMadBits;
		p = p.substr(0, index + third.size());
		result += p;
		result += " ";


		selectedMadBits = selectedMadBits.substr(index + third.size() + 1, -1);



		index = selectedMadBits.find('W');



		selectedMadBits = selectedMadBits.replace(selectedMadBits.find("WORD"), 4, fourth);
		p = selectedMadBits;
		p = p.substr(0, index + fourth.size());
		result += p;
		result += ".";


		random_number = (rand() % 10) + 1;

		selectedMadLib = madBits[random_number];

		selectedMadBits = madLibs[random_number];



	}

	std::cout << " " << std::endl;
	std::cout << result << std::endl;

	final = result;

	return result;
}


std::string loadMadLib(std::string filename) {//gets each line (a mad lib) and displays it individually

	std::string text;
	std::ifstream ifs(filename);

	while(!ifs.eof())
	{
	  getline(ifs,text);
	  std::cout << "" << text << "\n" << "\n"; 
	}

	return text;
}




int getInput() { //gets user input (ensures they pick between 1-5)


	// Initialise user input to be lower than allowed range.
	int input = 0 - 1;
	std::cin >> input;
	// Keep asking for input until it is within range specified.
	while (input < 0 || input > 5 || std::cin.fail()) {
		std::cout << "Error: Input only integers from " << 0 << "-"
			<< 5 << ": ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}
	return input;
}




bool processChoice(int userChoice) {


	if (userChoice == 1) { // Case 1: Displays information about the program.
		displayTextData("C:\\MadAbout.txt");
		system("pause");
	}

	else if (userChoice == 2) { // Case 2: Loads and stores data from a file.

		madlibs = createListOne("C:\\MadLibData.txt"); //file location*******************************************************
		madbits = createListTwo("C:\\MadBitsData.txt"); //file location*****************************************************

		std::cout << "Data loading from MadLibData.txt..." << std::endl;
		std::cout << "Data loading from MadBitsData.txt..." << std::endl;
		system("pause");
	}

	else if (userChoice == 3) {

		if (madbits.size() > 5 || madlibs.size() > 5) {
			generateMadLib(madlibs, madbits);
		}
		else {
			std::cout << "Madbits or Madlibs not yet loaded..." << std::endl;
		}
		system("pause");

	}

	else if (userChoice == 4) {//Case 4: Saves a Mad Lib to a File

		std::string value;
		std::cout << "Do you want to save this Mad Lib? (y/n) ";
		std::cin >> value;

		if (value == "y" && final.size() > 5) {
			saveMadLib(final, "C:\\savedMadLibs.txt"); //file location**********************************************
			std::cout << final << std::endl;
			std::cout << "This Mad Lib is now saved. " << std::endl;
		}

		else {
			std::cout << "Currently no generated Mad Lib! " << std::endl;
		}
		system("pause"); 

	}

	else if (userChoice == 5) {//loads from savedMadLibs file
		std::cout << " " << std::endl;
		loadMadLib("C:\\savedMadLibs.txt");
	}

	return userChoice > 0 ? true : false;//if 0, exit
}



int main() {
	
	std::ofstream ofs;
	ofs.open("C:\\savedMadLibs.txt", std::ofstream::out | std::ofstream::trunc); //deletes all savedMadLib data before starting //file location*************************************
	ofs.close();

	bool runProgram = true;
	while (runProgram) {
		runMenu();
		// Prompt user for input
		int userChoice = getInput();
		runProgram = processChoice(userChoice);//if user input not 0, stays true
	}

	std::cout << "Thank you for testing this application." << std::endl;
	system("pause");

	return 0;

}



