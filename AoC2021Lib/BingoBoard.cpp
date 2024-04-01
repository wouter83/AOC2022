#include "pch.h"
#include "BingoBoard.h"
#include "Generic.h"

void processBingoCard(std::vector<BingoNumber*>& board, uint32_t number)
{
	for (auto bn : board)
	{
		if (bn->number == number)
		{
			bn->drawn = true;
		}
	}
}

bool bingo_five(std::vector<BingoNumber*>& numbers)
{
	bool ret = true;
	for (auto bn : numbers)
	{
		ret &= bn->drawn;
	}
	return ret;
}

bool bingo_board(std::vector<BingoNumber*>& board)
{
	uint32_t start = 0;
	uint32_t end = 0;
	uint32_t winning_number = 0;
	bool result = false;

	// rows
	do {
		end = board.size() / 5 + start;

		std::vector<BingoNumber*> b(board.begin() + start, board.begin() + end);
		result = bingo_five(b);
		if (result)
			break;
		start = end;

	} while (end != board.size());

	if (result)
	{
		return true;
	}

	// find the columns
	start = 0;
	end = 0;
	result = false;
	std::vector<BingoNumber*> b;

	for (int i = 0; i < board.size() / 5 && !result; ++i)
	{
		b.clear();
		// i is our base
		for (int j = i; j < board.size(); j += 5)
		{
			b.push_back(board[j]);
		}
		result = bingo_five(b);
	}

	return result;
}

void BingoBoard::input(std::vector<std::string>& input)
{
	if (input.size() >= 1)
	{
		std::vector<std::string> inputnumbers = Generic::splitString(input[0], ",");
		for (auto num : inputnumbers)
		{
			mNumbersDrawn.push_back(std::strtol(num.c_str(), nullptr, 0));
		}
	}
	std::vector<BingoNumber*> board;

	for (int i = 1; i < input.size(); ++i)
	{
		// parse the rest
		std::vector<std::string> boardNumbers = Generic::splitString(input[i], " ");

		for (auto num : boardNumbers)
		{
			board.push_back(new BingoNumber(std::strtol(num.c_str(), nullptr, 0)));
		}

	}
	size_t boardCount = board.size() / 25;

	for (auto n : mNumbersDrawn)
	{
		for (int i = 0; i < boardCount; ++i)
		{
			bool stop = false;
			for (auto a : mAnswers) 
			{
				stop = i == a.second;
				if (stop)
					break;
			}
			if (stop)
				continue;
			std::vector<BingoNumber*> b(board.begin() + i * 25, board.begin() + (i + 1) * 25);
			processBingoCard(b, n);
		}

		for (int i = 0; i < boardCount; ++i)
		{
			bool stop = false;
			for (auto a : mAnswers)
			{
				stop = i == a.second;
				if (stop)
					break;
			}
			if (stop)
				continue;
			std::vector<BingoNumber*> b(board.begin() + i * 25, board.begin() + (i + 1) * 25);
			bool isBingo = bingo_board(b);
			if (isBingo)
			{
				uint32_t bingo_number = 0;
				for (auto bn : b)
				{
					if (!bn->drawn)
						bingo_number += bn->number;
				}
				AnswerBoard answer;
				answer.first = bingo_number * n;
				answer.second = i;
				mAnswers.push_back(answer);
			}
		}
	}
	for (auto b : board)
	{
		delete b;
	}
}
