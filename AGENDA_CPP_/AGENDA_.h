#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class AGENDA_
{
	public:
		AGENDA_() {
			std::cout << "	DEBUG | BP Created" << std::endl;
			AGENDA_::getInitSaveFile_();
		}
		~AGENDA_() {
			std::cout << "	DEBUG | BP Destroyed" << std::endl;
		}
		std::string strEventName_;
		std::vector <std::string> vecStringAgenda_;
		void initProgram_();
		void addEvent();
		void removeEvent(int LV_Event_Index_);
		void generateSaveFile_();
		void getInitSaveFile_();
		void destroyBP_();
	private:
	protected:

};

