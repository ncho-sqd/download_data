#include "gtest/gtest.h"
#include "person.h"
#include "community.h"

// this class is used for testing public methods in class Community
class test_community: public ::testing::Test {
protected:
	Community community;

	/* The following are added by yours truly */
	Person tp1;
	Person tp2;
	Person tp3;
	Person tp1COPY;
	Person tp2COPY;
};

// you should complete the following test cases
// you should add more if you see fit

// test constructor
TEST_F(test_community, test_constructor){
	tp1.set_info("em","e","u",20,"hi");
	tp2.set_info("neil","n","c",20,"hello");
	map<string, Person> people_db;
	map<string, Person> people_db2;
	people_db.insert(pair<string,Person>(tp1.get_username(),tp1));
	people_db.insert(pair<string,Person>(tp2.get_username(),tp1));

	EXPECT_FALSE(community.constructor_test("ab%",people_db));
	EXPECT_FALSE(community.constructor_test("abc",people_db2));
	EXPECT_FALSE(community.constructor_test("1abc",people_db));
	EXPECT_FALSE(community.constructor_test("ab$ ",people_db));
	EXPECT_FALSE(community.constructor_test("aabdkeirufhdteyrjgkhfkvngjtugjfkj",people_db));

	/* if valid input */
	EXPECT_TRUE(community.constructor_test("abcd",people_db));
	EXPECT_TRUE(community.constructor_test("abc123d",people_db));
}
// test get_name and set_name
TEST_F(test_community, test_name) {
	EXPECT_FALSE(community.set_name("zyxwvutabcdefghijklmnopqrstuvwxyz"));
	EXPECT_TRUE(community.set_name("yxwvutabcdefghijklmnopqrstuvwxyz"));
    EXPECT_STREQ(community.get_name().c_str(), "yxwvutabcdefghijklmnopqrstuvwxyz");
	EXPECT_FALSE(community.set_name("yxwvutabcdef321%"));
	EXPECT_TRUE(community.set_name("adbdyxwvutabcdef321"));
	EXPECT_STREQ(community.get_name().c_str(), "adbdyxwvutabcdef321");
	EXPECT_FALSE(community.set_name("12345yxwvutabcdef321%"));
	EXPECT_TRUE(community.set_name("abcdedf1234dvase987"));
	EXPECT_STREQ(community.get_name().c_str(), "abcdedf1234dvase987");
	EXPECT_FALSE(community.set_name("abcdedf1234%%#&%vase987"));
	EXPECT_FALSE(community.set_name(""));
	EXPECT_FALSE(community.set_name(" "));
	EXPECT_FALSE(community.set_name("abc "));
}


// test add_person
TEST_F(test_community, add_person) {
	/* setup people */
	tp1.set_info("em","e","u",20,"hi");
	tp2.set_info("neil","n","c",20,"hello");
	tp1COPY.set_username("em");

	/* add person tests */
	EXPECT_TRUE(community.add_person(tp1));
	EXPECT_FALSE(community.add_person(tp1));
	EXPECT_STREQ(community.get_member(tp1.get_username()).get_info().c_str(), "em,e,u,20,hi");
	EXPECT_FALSE(community.add_person(tp1COPY));
	EXPECT_STREQ(community.get_member(tp1.get_username()).get_info().c_str(), "em,e,u,20,hi");
	EXPECT_STREQ(community.get_member(tp2.get_username()).get_info().c_str(), ",,,0,");
	EXPECT_TRUE(community.add_person(tp2));
	EXPECT_STREQ(community.get_member(tp2.get_username()).get_info().c_str(), "neil,n,c,20,hello");
	EXPECT_TRUE(community.add_person(tp3)); //going to allow addition of null person
}


// test get_all_usernames
//   there's no EXPERT functions for comparing non-built-in types, you need to
//   do some parsing by yourself
TEST_F(test_community, get_all_usernames) {
	/* setup people */
	tp1.set_info("em","e","u",20,"hi");
	tp2.set_info("neil","n","c",20,"hello");
	tp3.set_info("ugh","stuff","here",0,"blah");
	/* setup community */
	community.add_person(tp1);
	community.add_person(tp2);

	/* test */
	EXPECT_STREQ(community.parse_list(community.get_all_usernames()).c_str(),"em,neil,");
	EXPECT_STRNE(community.parse_list(community.get_all_usernames()).c_str(),"em,neil,ugh,");

	community.add_person(tp3);

	EXPECT_STREQ(community.parse_list(community.get_all_usernames()).c_str(),"em,neil,ugh,");
}


// test get_member
TEST_F(test_community, get_member) {
	/* setup people */
	EXPECT_TRUE(tp1.set_info("em","e","u",20,"hi"));
	EXPECT_TRUE(tp2.set_info("neil","n","c",20,"hello"));
	/* setup community */
	EXPECT_TRUE(community.add_person(tp1));
	EXPECT_TRUE(community.add_person(tp2));

	/* get_member tests */
	EXPECT_STREQ(community.get_member(tp1.get_username()).get_info().c_str(), "em,e,u,20,hi");
	EXPECT_STREQ(community.get_member(tp2.get_username()).get_info().c_str(), "neil,n,c,20,hello");
	EXPECT_STREQ(community.get_member(tp3.get_username()).get_info().c_str(), ",,,0,");
	EXPECT_STREQ(community.get_member(tp3.get_username()).get_info().c_str(), ",,,0,");
}

// test find_member
TEST_F(test_community, find_member) {
	/* Setup people */
	tp1.set_info("em","e","u",20,"hi");
	tp2.set_info("neil","n","c",20,"hello");
	tp1COPY.set_info("em2","e","u",20,"hi2");
	tp2COPY.set_info("neil2","n","c",20,"hello2");
	community.add_person(tp1);
	community.add_person(tp2);
	community.add_person(tp1COPY);
	community.add_person(tp2COPY);


	EXPECT_STREQ(community.parse_person_list(community.find_member("e")).c_str(),"em,em2,");
	EXPECT_STREQ(community.parse_person_list(community.find_member("n")).c_str(),"neil,neil2,");
	EXPECT_STREQ(community.parse_person_list(community.find_member("more")).c_str(),"");

	tp3.set_info("more","stuff","here",9,"blah");
	community.add_person(tp3);

	EXPECT_STREQ(community.parse_person_list(community.find_member("stuff")).c_str(),"more,");
}


TEST_F(test_community, send_msg) {
	tp1.set_info("em","e","u",20,"hi");
	tp2.set_info("neil","n","c",20,"hello");
	community.add_person(tp1);
	community.add_person(tp2);
    list<string> block;
    block.push_back("em");
    block.push_back("neil");

    EXPECT_TRUE(community.send_msg(block,"ATTENTION!"));

    /* change tp1 and tp2 to copies of the new copies */
    tp1 = community.get_member("em");
    tp2 = community.get_member("neil");

    EXPECT_STREQ(tp1.get_msg().c_str(),"ATTENTION!");
    EXPECT_STREQ(tp2.get_msg().c_str(),"ATTENTION!");

    block.pop_back();
    block.push_back("haha");
    EXPECT_FALSE(community.send_msg(block,"hello"));

    /* change tp1 and tp2 to copies of the new copies */
    tp1 = community.get_member("em");
    tp2 = community.get_member("neil");

    EXPECT_STREQ(tp1.get_msg().c_str(),"ATTENTION!"); //not read because it was a different copy
    EXPECT_STREQ(tp1.get_msg().c_str(),"hello");
    EXPECT_STREQ(tp2.get_msg().c_str(),"ATTENTION!");

}

