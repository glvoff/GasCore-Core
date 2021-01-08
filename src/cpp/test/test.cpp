#include <gas/str/Text.hpp>
#include <gas/coll/ArrayList.hpp>
#include <gas/coll/Array.hpp>
#include <gas/test/Tester.hpp>
#include <gas/test/TestCase.hpp>
#include <gas/test/Logger.hpp>
#include <gas/test/FileLogger.hpp>

#include "FileLoggerTestCase.hpp"
#include "MockTestCase.hpp"
#include "RefTestCase.hpp"
#include "PtrTestCase.hpp"
#include "ThreadTestCase.hpp"
#include "ArrayTestCase.hpp"
#include "ArrayListTestCase.hpp"

#include <iostream>

namespace test{
    void testText(){
        gas::str::Text s = "hello world";
        std::cout << s.content() << std::endl;
        std::cout << "testText: pass" << std::endl;
    }
}

void runOldTests(){
    using namespace test;
    testText();
}

int main(int argc, char** argv){
    runOldTests();
 
    gas::test::Logger* logger = new gas::test::FileLogger("result.log");
    gas::test::Tester tester(logger);
    tester.add(new gas::test::MockTestCase(logger));
    tester.add(new gas::test::FileLoggerTestCase(logger));
    tester.add(new gas::test::RefTestCase(logger));
    tester.add(new gas::test::PtrTestCase(logger));
    tester.add(new gas::test::ThreadTestCase(logger));
    tester.add(new gas::test::ArrayTestCase(logger));
    tester.add(new gas::test::ArrayListTestCase(logger));

    tester.run();

    return 0;
}