#pragma once
#include <vector>
#include <string>

struct BingoNumber {
	BingoNumber(uint32_t val) { number = val; }
	uint32_t number;
	bool drawn = false;
};

typedef std::pair<uint32_t, uint32_t> AnswerBoard;

class BingoBoard
{
public:
	void input(std::vector<std::string>& input);
	uint32_t getBingoAnswerBest() { return mAnswers[0].first; }
	uint32_t getBingoAnswerWorst(){ return mAnswers[mAnswers.size() -1].first; }

private:
	std::vector<uint32_t> mNumbersDrawn;
	std::vector<AnswerBoard> mAnswers;
	
};

