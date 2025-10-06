#ifndef NOTATIONCONVERTERINTERFACE_H
#define NOTATIONCONVERTERINTERFACE_H

#include <string>

//class definition for NotationConverterInterface which is an abstract class defining the interface of its derived class NotationConverter
class NotationConverterInterface
{
    public:
        //six methods that convert a given expression from its current form to a desired form
        virtual std::string postfixToInfix(std::string inStr) = 0;
        virtual std::string postfixToPrefix(std::string inStr) = 0;

        virtual std::string infixToPostfix(std::string inStr) = 0;
        virtual std::string infixToPrefix(std::string inStr) = 0;

        virtual std::string prefixToInfix(std::string inStr) = 0;
        virtual std::string prefixToPostfix(std::string inStr) = 0;
};

#endif /* NOTATIONCONVERTERINTERFACE_H */