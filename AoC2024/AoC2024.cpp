// AoC2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "inputs.hpp"
#include <crtdbg.h>
#include <Generic.h>

#include <HistorianHysteria.h>
#include <RedNosedReports.h>

int main()
{    
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        std::cout << "--- Day 01 ---" << std::endl;
        
        HistorianHysteria hh;
        hh.ParseInput(day1Input);
        std::cout << "Answer 1: " << hh.TotalDistance() << std::endl;
        std::cout << "Answer 2: " << hh.SimilarityScore() << std::endl;
    }
    {
        std::cout << "--- Day 02 ---" << std::endl;

        RedNosedReports rnr;
        std::vector<std::string> strvect;
        Generic::ReadFile("input\\day2.h", strvect);
        //std::cout << "Answer 1: " << rnr.ReturnSafeCount() << std::endl;
        //std::cout << "Answer 2: " << hh.SimilarityScore() << std::endl;
    }
}
 