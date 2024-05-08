#include "AGENDA_.h"

void AGENDA_::initProgram_()
{
	int LV_intRaspunsIntrare_{ 0 };

	std::cout << "1.Doriti sa introduceti un eveniment nou ?" << std::endl;
	std::cout << "2.Doriti sa stergeti un eveniment existent ?" << std::endl;
	std::cout << "3.Doriti sa vizualizati evenimentele ?" << std::endl;
	std::cout << "4.Iesire agenda !" << std::endl;

	std::cin >> LV_intRaspunsIntrare_;
	std::cin.ignore();

	std::cout << std::endl;

	switch (LV_intRaspunsIntrare_)
	{
	case 1:
		std::cout << "Introduceti noul eveniment :" << std::endl;

		std::getline(std::cin, strEventName_);

		std::cout << std::endl;

		AGENDA_::addEvent();

		AGENDA_::generateSaveFile_();

		system("CLS");

		AGENDA_::initProgram_();
		break;
	case 2:
		std::cout << "Evenimentele existente :" << std::endl;

		for (int i = 0; i < vecStringAgenda_.size(); i++)
		{
			std::cout << i + 1 << ". " << vecStringAgenda_[i] << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Introduceti numarul evenimentului corespunzator :" << std::endl;
		std::cin >> LV_intRaspunsIntrare_;
		std::cin.ignore();

		std::cout << std::endl;

		if (LV_intRaspunsIntrare_ >= 0 && LV_intRaspunsIntrare_ < vecStringAgenda_.size()) {
			//std::cout << "Indexul este valid. Elementul la indexul " << LV_intRaspunsIntrare_ << " este: " << vecStringAgenda_[LV_intRaspunsIntrare_] << std::endl;
			AGENDA_::removeEvent(LV_intRaspunsIntrare_ - 1);

			AGENDA_::generateSaveFile_();

			system("CLS");

			AGENDA_::initProgram_();
		}
		else {
			std::cout << "Indexul este invalid. Vecotrul are dimensiunea: " << vecStringAgenda_.size() + 1 << std::endl;

			AGENDA_::initProgram_();
		}

		break;
	case 3:

		for (int i = 0; i < vecStringAgenda_.size(); i++)
		{
			std::cout << i + 1 << ". " << vecStringAgenda_[i] << std::endl;
		}
		std::cout << std::endl;

		AGENDA_::initProgram_();
		break;
	default:
		break;
	}
}

void AGENDA_::addEvent()
{
	vecStringAgenda_.push_back(strEventName_);
}

void AGENDA_::removeEvent(int LV_Event_Index_)
{
		for (int i = LV_Event_Index_; i < vecStringAgenda_.size() - 1; i++)
		{
			vecStringAgenda_[i] = vecStringAgenda_[i + 1];
		}
		vecStringAgenda_.pop_back();
}

void AGENDA_::generateSaveFile_()
{
	

	std::ofstream outputFile; // Define an output file stream object

	// Open file
	outputFile.open("AGENDA_.txt");

	if (!outputFile.is_open()) {
		std::cerr << "	Error | Unable to open the file." << std::endl;
		// Return an error code
	}

	// Loop to generate
	for (const auto& linie : vecStringAgenda_) {
		outputFile << linie << std::endl;
	}


	// Close the file
	outputFile.close();
}

void AGENDA_::getInitSaveFile_()
{
	std::ifstream inputFile("AGENDA_.txt");
	std::string linie;
	while (std::getline(inputFile, linie)) {
		vecStringAgenda_.push_back(linie);
	}
	inputFile.close();
}


void AGENDA_::destroyBP_()
{
	delete this;
}