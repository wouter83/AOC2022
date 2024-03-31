#include <iostream>
#include "inputs.hpp"

#include <CounterUpper.h>
#include <IntProc.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    {
        CounterUpper upper(day1Input);
        
        std::cout << "--- Day 01 ---" << std::endl;
        std::cout << "Answer 1: " << upper.GetFuel() << std::endl;
        std::cout << "Answer 2: " << upper.GetTotalFuel() << std::endl;
    }

    {
        IntProc proc(day2Input);
        proc.Run(12,2);
        std::cout << "--- Day 02 ---" << std::endl;
        std::cout << "Answer 1: " << proc.returnPosZero() << std::endl;
        
        uint noun, verb;
        bool found = false;

        for (noun = 0; noun < 100; ++noun)
        {
            for (verb = 0; verb < 100; ++verb)
            {
                IntProc proc_2(day2Input);
                proc_2.Run(noun, verb);
                if (proc_2.returnPosZero() == 19690720)
                {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        std::cout << "Answer 2: " << 100 * noun + verb << std::endl;
    }
}