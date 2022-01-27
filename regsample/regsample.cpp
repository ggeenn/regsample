#include <iostream>
#include <string>

#include "common/common.h"

int main(int argc, char** argv)
{
    auto v = cmn::GetBinaryKey(L"SOFTWARE\\7-Zip\\Extraction", L"PathHistory");
    std::cout << "bin size" << v.size() << "\n";

    return 0;
}
