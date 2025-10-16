#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    :target("default")
{

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm ("ShrubberyCreationForm", 145, 137), target(target)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& old_obj)
    :AForm (old_obj), target(old_obj.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
    if (&ref == this)
        return *this;
    this->target = ref.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execution() const
{
    std::ofstream targetfile((target + "_shrubbery").c_str());
    if (!targetfile.is_open())
    {
        throw std::runtime_error("failed to open file");
    }
    targetfile << "  .-'- -.\n" << " (       )\n" <<
        "(  ,      )\n" << " ( \'./  .)'\n" << "  '-| |-'\n" << "  '-| |-'\n"
        << "  '-| |-'\n" << "    | |\n" << ",,,,|.|,,,\n";
    targetfile.close();
}