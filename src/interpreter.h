#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include "Log.h"

namespace Interpreter
{
    static void InterpretCode(const std::string& code)
    {
        std::vector<int> data(1, 0);
        std::vector<int>::iterator dataPtr = data.begin();

        std::string::const_iterator instructionPtr = code.begin();
        std::stack<std::string::const_iterator> instructionStack;

        while (instructionPtr != code.end())
        {
            switch (*instructionPtr)
            {
            case '<':
            {
                dataPtr--;
                break;
            }
            case '>':
            {
                dataPtr++;
                if (dataPtr == data.end()) {
                    data.push_back(0);
                    dataPtr = data.end()-1;
                }
                break;
            }
            case '+':
            {
                (*dataPtr) += 1;
                break;
            }
            case '-':
            {
                (*dataPtr) -= 1;
                break;
            }
            case '.':
            {
                Log::Info << char(*dataPtr);
                break;
            }
            case ',':
            {
                char input;
                std::cin >> input;
                *dataPtr = input;
            }
            case '[':
            {
                instructionStack.push(instructionPtr);

                if (*dataPtr == 0)
                {
                    auto startInstructionPtr = instructionPtr;
                    while (++instructionPtr != code.end())
                    {
                        if (*instructionPtr == '[')
                            instructionStack.push(instructionPtr);
                        else if (*instructionPtr == ']')
                        {
                            if (instructionStack.empty())
                                throw std::runtime_error("Found a ']' that did not have a matching '['!");

                            auto tempInstructionPtr = instructionStack.top();
                            instructionStack.pop();

                            if (startInstructionPtr == tempInstructionPtr)
                                break;
                        }
                    }
                }
                break;
            }
            case ']':
            {
                if (instructionStack.empty())
                    throw std::runtime_error("Found a ']' that did not have a matching '['!");

                if (*dataPtr != 0)
                    instructionPtr = instructionStack.top();
                else
                    instructionStack.pop();

                break;
            }
            default:
                break;
            }

            instructionPtr++;
        }

        if (!instructionStack.empty())
            throw std::runtime_error("Found a '[' that did not have a matching ']'!");

        Log::Info << Log::Endl;
    }
}
