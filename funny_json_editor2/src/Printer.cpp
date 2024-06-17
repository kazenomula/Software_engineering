#include "Printer.hpp"

Printer::Printer(std::shared_ptr<PrintStrategy> strategy) : strategy(strategy), buf(std::make_shared<std::ostringstream>()) {}

void Printer::BufferConstruct(std::shared_ptr<Iterator> its)
{
    while (its->hasNext())
    {
        auto node = its->next();
        strategy->print(node, *buf);
    }
}

void Printer::PrintBuffer()
{
    strategy->printbuf(*buf);
}
