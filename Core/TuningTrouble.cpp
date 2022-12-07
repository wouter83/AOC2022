#include "pch.h"
#include "TuningTrouble.h"
#include <unordered_set>

int TuningTrouble::StartOf(const std::string& input, int size)
{
    for (int i = 0; i < input.size(); ++i)
    {
        std::string substr = input.substr(i, size);

        std::unordered_set<char> values;
        for (auto c : substr)
            values.insert(c);

        if (values.size() == size)
        {
            return i + size;
        }
    }
    return 0;
}
int TuningTrouble::StartOfPacket(const std::string& input)
{
    return StartOf(input, 4);
}

int TuningTrouble::StartOfMessage(const std::string& input)
{
    return StartOf(input, 14);

}
