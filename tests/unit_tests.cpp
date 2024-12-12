//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include "test_framework.h"
#include "../src/user.h"
#include <iostream>

void test_add_user() {
    int id = add_user("Jan", "Kowalski");
    ASSERT_EQ(id, 1);

    User* user = get_user_by_id(id);
    ASSERT_TRUE(user != nullptr);
    ASSERT_EQ(std::string(user->name), "Jan");
    ASSERT_EQ(std::string(user->lastname), "Kowalski");
}

void test_get_user_by_id() {
    add_user("Anna", "Nowak");
    User* user = get_user_by_id(2);

    ASSERT_TRUE(user != nullptr);
    ASSERT_EQ(std::string(user->name), "Anna");
    ASSERT_EQ(std::string(user->lastname), "Nowak");
}

void test_update_user_partial() {
    int id = add_user("Piotr", "Zieliński");

    int result = update_user_partial(id, "Paweł", nullptr);
    ASSERT_EQ(result, 1);

    User* user = get_user_by_id(id);
    ASSERT_EQ(std::string(user->name), "Paweł");
    ASSERT_EQ(std::string(user->lastname), "Zieliński");
}

void test_delete_user() {
    int id = add_user("Marek", "Kowalczyk");

    int result = delete_user(id);
    ASSERT_EQ(result, 1);

    User* user = get_user_by_id(id);
    ASSERT_TRUE(user == nullptr);
}

int run_unit_tests() {
    TestSuite suite;
    suite.add_test("test_add_user", test_add_user);
    suite.add_test("test_get_user_by_id", test_get_user_by_id);
    suite.add_test("test_update_user_partial", test_update_user_partial);
    suite.add_test("test_delete_user", test_delete_user);
    suite.run();
    return 0;
}