#include "Test.h"
#include "Failure.h"
#include "TestRegistry.h"
#include "TestResult.h"
#include <cstring>

Test::Test (const std::string& testName,
            std::string fileName,
            long lineNumber)
:
    myFileName (fileName),
    myLineNumber (lineNumber),
    myName (testName)
{
    TestRegistry::addTest (this);
}

Test::~Test()
{
}

const std::string& Test::getFileName() const
{
    return myFileName;
}

const long& Test::getLineNumber() const
{
    return myLineNumber;
}

const std::string& Test::getName() const
{
    return myName;
}

void Test::run (TestResult& result)
{
    runTest (result);
    result.testWasRun();
}

void check_equal_wcompare(const wchar_t* const expected, const wchar_t* const actual, TestResult& result, const char* file, int line)
{
    if (wcscmp((expected), (actual)) != 0) {
        std::ostringstream message;
        message << "expected '" << (expected) << "' but was '" << (actual) << "'";
        result.addFailure (Failure (message.str(), file, line));
        return;
    }
}

void check_equal_compare(const char* const expected, const char* const actual, TestResult& result, const char* file, int line)
{
    if (strcmp((expected), (actual)) != 0) {
        std::ostringstream message;
        message << "expected '" << (expected) << "' but was '" << (actual) << "'";
        result.addFailure (Failure (message.str(), file, line));
        return;
    }
}
