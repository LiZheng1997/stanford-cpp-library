/*
 * Test file for verifying the Stanford C++ autograder lib functionality.
 * INSTRUCTOR'S SOLUTION, do not distribute!
 */

#include <iostream>
#include <string>
#include "autograder.h"
#include "console.h"
#include "gtest-marty.h"
#include "platform.h"
#include "simpio.h"
#include "private/version.h"
using namespace std;

class TestTest : public ::testing::Test {};

TEST_F(TestTest, test01_ab) {
    autograder::setCurrentCategoryName("first category");
    assertEquals("hi there", string("a"), string("a"));
}

TEST_F(TestTest, test02_abc_oops_real_long_name_gonnaFail) {
    assertEquals("some failed test 1", string("abc"), string("oops"));
    assertEquals("some failed test 2", string("abc2"), string("oops2"));
    assertEquals("some later test that passes 1", string("same1"), string("same1"));
    assertEquals("some later test that passes 2", string("same2"), string("same2"));
}

TEST_F(TestTest, test03_near) {
    sleep(1);
    assertDoubleNear("hi there", 3.14, 3.1415, 0.1);
}

TEST_F(TestTest, test04_def) {
    autograder::setCurrentCategoryName("second category");
    assertEquals("hi there", string("a"), string("a"));
}

TEST_F(TestTest, test05_anotherOne) {
    sleep(2);
    string exp = "expected 1\nexpected 2\nexpected 3";
    string stu = "expected 1\nstudent 2 oops\nexpected 3";
    assertDiff("some diffs", exp, stu);
}

TEST_F(TestTest, test06_also_long_name_gonnaFail) {
    assertEquals("some failed test", string("good1"), string("bad1"));
    assertEquals("some failed test", string("good2"), string("bad2"));
    assertEquals("some failed test", string("good3"), string("good3"));
}


/*
 * Code that autograderMain() runs before it starts the autograding test cases.
 */
void before() {
    cout << "THIS IS BEFORE!" << endl;
    cout << "THIS IS BEFORE!" << endl;
    cout << "THIS IS BEFORE!" << endl;
}

/*
 * Code that autograderMain() runs after it ends the autograding test cases.
 */
void after() {
    cout << "THIS IS AFTER!" << endl;
    cout << "THIS IS AFTER!" << endl;
    cout << "THIS IS AFTER!" << endl;
}

void showMyInputTxt() {
    // empty
    autograder::showStudentTextFile("myinput.txt", /* maxWidth */ 75, /* maxHeight */ 30);
}

// this just needs to be here so that it will become studentMain()
int main() {
    return 0;
}

void autograderMain() {
    // autograder::setShowLateDays(true);    // this is the default
    version::ensureProjectVersion("2014/10/31");
    autograder::setAssignmentName("CS 106B Test");
    autograder::setAboutMessage("TEST 1 2 3 \nHWX assignment auto-grader by Marty Stepp");
    // autograder::setStudentProgramFileName("recursionproblems.cpp");
    autograder::setShowInputPanel(true, "inputpanel-mainfunc.xml");
    autograder::setGraphicalUI(true);
    autograder::setTestNameWidth(std::string("test02_abc_oops_real_long_name_gonnaFail").length());
    autograder::setStartMessage("my start message");
    autograder::styleCheckAddFile("mainfunc.cpp");
    
    autograder::addCallbackButton(showMyInputTxt, "View\nmyinput.txt", "textfile.gif");
    // autograder::setCallbackStart(before);
    // autograder::setCallbackEnd(after);
}