#pragma once

#include <gas\test\Logger.hpp>
#include <gas\test\TestCase.hpp>

namespace gas{
    namespace test{
        class ArrayTestCase: public TestCase{
        public:
            ArrayTestCase(Logger* logger);
            ~ArrayTestCase();
            void execute() override;
        public:
            void creatingArrayStaticaly();
            void appendingElementsToArray();
            void appendingRangeElements();
            
            /* @todo: #1 future tests - add new tests to testcase */
            // void creatingArrayInHeap();
            // void appendingElementsToArray();
            // void retriveElementsFromArray();
        };
    }
}