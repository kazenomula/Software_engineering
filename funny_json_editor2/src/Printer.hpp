#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <memory>
#include "PrintStrategy.hpp"
#include "Iterator.hpp"

class Printer
{
public:
    Printer(std::shared_ptr<PrintStrategy> strategy);
    void BufferConstruct(std::shared_ptr<Iterator> its);
    void PrintBuffer();

private:
    std::shared_ptr<std::ostringstream> buf;
    std::shared_ptr<PrintStrategy> strategy;
};

#endif // PRINTER_HPP
