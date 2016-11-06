#include "gtest/gtest.h"
#include "person.h"

// this class is used for testing public methods in class Person
class test_person: public ::testing::Test {
protected:
	Person person;
	Person recipient;
};

// test constructor
TEST_F(test_person, test_constructor){
	/* if invalid input */

	EXPECT_FALSE(person.constructor_test("","Neil","Cho",23,"hi"));
	EXPECT_FALSE(person.constructor_test("ab","Neil%","Cho",23,"hi"));
	EXPECT_FALSE(person.constructor_test("ab","Neil","Cho%",23,"hi"));
	EXPECT_FALSE(person.constructor_test("ab","Neil","Cho",200,"hi"));
	EXPECT_FALSE(person.constructor_test("ab","Neil","Cho",23,"Abdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjaaaaaanndkekdiekdksldksleibndisleibndkslwiengkdlskssi+1"));
	EXPECT_FALSE(person.constructor_test("1abc","Neil","Cho",23,"hi"));
	EXPECT_FALSE(person.constructor_test("em","Emilee3","Urbanek3",127,"hey"));

	/* if valid input */
	EXPECT_TRUE(person.constructor_test("em","Emilee","Urbanek",20,"hey"));
	EXPECT_TRUE(person.constructor_test("em","Emilee","Urbanek",20,"hey"));
}

// test get_username and set_username
TEST_F(test_person, test_username) {
	EXPECT_FALSE(person.set_username("zyxwvutabcdefghijklmnopqrstuvwxyz"));
	EXPECT_TRUE(person.set_username("yxwvutabcdefghijklmnopqrstuvwxyz"));
    EXPECT_STREQ(person.get_username().c_str(), "yxwvutabcdefghijklmnopqrstuvwxyz");
	EXPECT_FALSE(person.set_username("yxwvutabcdef321%"));
	EXPECT_TRUE(person.set_username("adbdyxwvutabcdef321"));
	EXPECT_STREQ(person.get_username().c_str(), "adbdyxwvutabcdef321");
	EXPECT_FALSE(person.set_username("12345yxwvutabcdef321%"));
	EXPECT_TRUE(person.set_username("abcdedf1234dvase987"));
	EXPECT_STREQ(person.get_username().c_str(), "abcdedf1234dvase987");
	EXPECT_FALSE(person.set_username("abcdedf1234%%#&%vase987"));
	EXPECT_FALSE(person.set_username(""));
	EXPECT_FALSE(person.set_username(" "));
	EXPECT_FALSE(person.set_username("abc "));
}

// test get_firstname and set_firstname
TEST_F(test_person, test_firstname) {
	EXPECT_FALSE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefaeb"));
	EXPECT_TRUE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdef"));
	EXPECT_STREQ(person.get_firstname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdef");
	EXPECT_FALSE(person.set_firstname("abcdefg0"));
	EXPECT_TRUE(person.set_firstname("emileeneil"));
	EXPECT_STREQ(person.get_firstname().c_str(), "emileeneil");
	EXPECT_FALSE(person.set_firstname("abcdefg;"));
	EXPECT_TRUE(person.set_firstname(""));
	EXPECT_STREQ(person.get_firstname().c_str(), "");
	EXPECT_FALSE(person.set_firstname(" "));
	EXPECT_FALSE(person.set_firstname("%##ab "));
	EXPECT_FALSE(person.set_firstname("1234"));
	EXPECT_FALSE(person.set_firstname("a#$%adb1234  "));
}

// test get_lastname and set_lastname
TEST_F(test_person, test_lastname) {
	EXPECT_FALSE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefg"));
	EXPECT_TRUE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdef"));
	EXPECT_STREQ(person.get_lastname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdef");
	EXPECT_FALSE(person.set_lastname("abcdefg0"));
	EXPECT_TRUE(person.set_lastname("chourbamek"));
	EXPECT_STREQ(person.get_lastname().c_str(), "chourbamek");
	EXPECT_FALSE(person.set_lastname("abcdefg;"));
	EXPECT_TRUE(person.set_lastname(""));
	EXPECT_STREQ(person.get_lastname().c_str(), "");
	EXPECT_FALSE(person.set_lastname(" "));
	EXPECT_FALSE(person.set_lastname("%##ab "));
	EXPECT_FALSE(person.set_lastname("1234"));
	EXPECT_FALSE(person.set_lastname("a#$%adb1234  "));
}

/**you may need to write more test functions.
 *  What we provide here is just for your reference
 */

// test get_age and set_age
//   test_person is the name of class your inherit from the base Test class
//   test_age is the name of this test case, which will show up in the test
//     results
//   make sure you cover every subroutine and branches
//   here we test edge cases of invalid ages
//   also, we test the get_age() method
//   avoid using ASSERT_FALSE here; if there is something wrong in ASSERT,
//   it will abort the whole testing which will hinder the grading process
TEST_F(test_person, test_age) {
	EXPECT_FALSE(person.set_age(-100));
	EXPECT_FALSE(person.set_age(-1));
	EXPECT_TRUE(person.set_age(0));
	EXPECT_EQ(person.get_age(), 0);
	EXPECT_TRUE(person.set_age(127));
	EXPECT_EQ(person.get_age(), 127);
	EXPECT_FALSE(person.set_age(128));
	EXPECT_TRUE(person.set_age(1));
	EXPECT_EQ(person.get_age(), 1);
	EXPECT_TRUE(person.set_age(23));
	EXPECT_EQ(person.get_age(), 23);
	EXPECT_FALSE(person.set_age(129));
	EXPECT_FALSE(person.set_age(200));
}

// test get_tagline and set_tagline
TEST_F(test_person, test_tagline) {
	EXPECT_TRUE(person.set_tagline("abc"));
	EXPECT_STREQ(person.get_tagline().c_str(), "abc");
	EXPECT_TRUE(person.set_tagline("Abdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjaaaaaanndkekdiekdksldksleibndisleibndkslwiengkdlskssie"));
	EXPECT_FALSE(person.set_tagline("Abdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjaaaaaanndkekdiekdksldksleibndisleibndkslwiengkdlskssi+1"));
	EXPECT_TRUE(person.set_tagline("12345")); //no
	EXPECT_STREQ(person.get_tagline().c_str(), "12345");
	EXPECT_TRUE(person.set_tagline("%%%^^^")); //symbol
	EXPECT_STREQ(person.get_tagline().c_str(), "%%%^^^");
	EXPECT_TRUE(person.set_tagline("$500,000/")); //no + symbol
	EXPECT_STREQ(person.get_tagline().c_str(), "$500,000/");
	EXPECT_TRUE(person.set_tagline("abc3445%$")); //no + symbol + character
	EXPECT_STREQ(person.get_tagline().c_str(), "abc3445%$");
	EXPECT_TRUE(person.set_tagline("")); //blank string
	EXPECT_TRUE(person.set_tagline(" ")); //space
	EXPECT_TRUE(person.set_tagline("bacd ")); //string + space
	EXPECT_TRUE(person.set_tagline("ba c d ")); //string + space2
}

// test get_info and set_info
TEST_F(test_person, test_info) {
	EXPECT_TRUE(person.set_info("cjwneil","Neil","Cho",23, "I'm Neil"));
	EXPECT_STREQ(person.get_info().c_str(), "cjwneil,Neil,Cho,23,I'm Neil");
	EXPECT_TRUE(person.set_info("emil","Emilee","Urbanek",20, "I'm Emilee"));
	EXPECT_FALSE(person.set_info("emil","Emilee","Urbanek",1005, "I'm Emilee"));
	EXPECT_STREQ(person.get_info().c_str(), "emil,Emilee,Urbanek,20,I'm Emilee");
	EXPECT_FALSE(person.set_info("emil","Emilee","Urb3anek",20, "I'm Emilee"));
	EXPECT_FALSE(person.set_info("e%mil","Emilee","Urb3anek",20, "I'm Emilee"));
	EXPECT_FALSE(person.set_info("emil","Emilee7","Urbanek",20, "I'm Emilee"));
	EXPECT_FALSE(person.set_info("","Emilee","Urbanek",20, "I'm Emilee"));
	EXPECT_FALSE(person.set_info("","Emilee","Urbanek",20, "Abdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjioq;winboiakl;bnasdfkjljasdkjlfaslkjlksafdadsfAbdadklfjaklsdfjaaaaaanndkekdiekdksldksleibndisleibndkslwiengkdlskssi+1"));
	EXPECT_FALSE(person.set_info("emil","Em ilee","Urbanek",20, "I'm Emilee"));
	EXPECT_STREQ(person.get_info().c_str(), "emil,Emilee,Urbanek,20,I'm Emilee");
	EXPECT_FALSE(person.set_info("emil","Emilee","U rbanek",20, "I'm Emilee"));
	EXPECT_STREQ(person.get_info().c_str(), "emil,Emilee,Urbanek,20,I'm Emilee");
}

// test send_msg and read_msg
//   to make your code shorter, we suggest combining these tests together; you
//   can also separate them into several test cases
TEST_F(test_person, test_msg) {
	EXPECT_STREQ(person.get_msg().c_str(),"empty"); //Neil reads [EMPTY INBOX]
	EXPECT_STREQ(recipient.get_msg().c_str(),"empty"); //Emilee reads [EMPTY INBOX]

	person.send_msg(recipient, "Hi, I'm Neil");
	person.send_msg(recipient, "I was wondering...");
	person.send_msg(recipient, "If you want to work on the mini project1 together?");
	person.send_msg(recipient, ":)");
	person.send_msg(recipient, "");

	EXPECT_STREQ(recipient.get_msg().c_str(), "Hi, I'm Neil");
	EXPECT_STREQ(recipient.get_msg().c_str(), "I was wondering...");
	recipient.send_msg(person, "Sure Neil, I'm Emilee");
	EXPECT_STREQ(recipient.get_msg().c_str(), "If you want to work on the mini project1 together?");
	EXPECT_STREQ(person.get_msg().c_str(), "Sure Neil, I'm Emilee");
	EXPECT_STREQ(recipient.get_msg().c_str(), ":)");
	EXPECT_STREQ(recipient.get_msg().c_str(), "");
	EXPECT_STREQ(recipient.get_msg().c_str(),"empty"); //Emilee reads [EMPTY INBOX]
	EXPECT_STREQ(person.get_msg().c_str(),"empty"); //Neil reads [EMPTY INBOX]

	recipient.send_msg(person, "Let's meet as CSIL at 6pm!");
	recipient.send_msg(person, "We'll work on it and be done by 11pm eh");
	EXPECT_STREQ(person.get_msg().c_str(), "Let's meet as CSIL at 6pm!");
	EXPECT_STREQ(person.get_msg().c_str(), "We'll work on it and be done by 11pm eh");
	EXPECT_STREQ(person.get_msg().c_str(),"empty"); //Neil reads [EMPTY INBOX]
}
