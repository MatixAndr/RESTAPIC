//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include "test_framework.h"
#include "../src/user.h"
#include <iostream>

void test_add_user_1() { int id = add_user("Jan", "Kowalski"); ASSERT_EQ(id, 1); }
void test_add_user_2() { int id = add_user("Anna", "Nowak"); ASSERT_EQ(id, 2); }
void test_add_user_3() { int id = add_user("Piotr", "Zieliński"); ASSERT_EQ(id, 3); }
void test_add_user_4() { int id = add_user("Marek", "Kowalczyk"); ASSERT_EQ(id, 4); }
void test_add_user_5() { int id = add_user("Ewa", "Wiśniewska"); ASSERT_EQ(id, 5); }
void test_get_user_by_id_1() { User* user = get_user_by_id(1); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Jan"); ASSERT_EQ(std::string(user->lastname), "Kowalski"); }
void test_get_user_by_id_2() { User* user = get_user_by_id(2); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Anna"); ASSERT_EQ(std::string(user->lastname), "Nowak"); }
void test_get_user_by_id_3() { User* user = get_user_by_id(3); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Piotr"); ASSERT_EQ(std::string(user->lastname), "Zieliński"); }
void test_get_user_by_id_4() { User* user = get_user_by_id(4); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Marek"); ASSERT_EQ(std::string(user->lastname), "Kowalczyk"); }
void test_get_user_by_id_5() { User* user = get_user_by_id(5); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Ewa"); ASSERT_EQ(std::string(user->lastname), "Wiśniewska"); }
void test_update_user_partial_1() { int result = update_user_partial(1, "Jan2", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(1); ASSERT_EQ(std::string(user->name), "Jan2"); ASSERT_EQ(std::string(user->lastname), "Kowalski"); }
void test_update_user_partial_2() { int result = update_user_partial(2, nullptr, "Nowak2"); ASSERT_EQ(result, 1); User* user = get_user_by_id(2); ASSERT_EQ(std::string(user->name), "Anna"); ASSERT_EQ(std::string(user->lastname), "Nowak2"); }
void test_update_user_partial_3() { int result = update_user_partial(3, "Piotr2", "Zieliński2"); ASSERT_EQ(result, 1); User* user = get_user_by_id(3); ASSERT_EQ(std::string(user->name), "Piotr2"); ASSERT_EQ(std::string(user->lastname), "Zieliński2"); }
void test_update_user_partial_4() { int result = update_user_partial(4, "Marek2", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(4); ASSERT_EQ(std::string(user->name), "Marek2"); ASSERT_EQ(std::string(user->lastname), "Kowalczyk"); }
void test_update_user_partial_5() { int result = update_user_partial(5, nullptr, "Wiśniewska2"); ASSERT_EQ(result, 1); User* user = get_user_by_id(5); ASSERT_EQ(std::string(user->name), "Ewa"); ASSERT_EQ(std::string(user->lastname), "Wiśniewska2"); }
void test_delete_user_1() { int result = delete_user(1); ASSERT_EQ(result, 1); User* user = get_user_by_id(1); ASSERT_TRUE(user == nullptr); }
void test_delete_user_2() { int result = delete_user(2); ASSERT_EQ(result, 1); User* user = get_user_by_id(2); ASSERT_TRUE(user == nullptr); }
void test_delete_user_3() { int result = delete_user(3); ASSERT_EQ(result, 1); User* user = get_user_by_id(3); ASSERT_TRUE(user == nullptr); }
void test_delete_user_4() { int result = delete_user(4); ASSERT_EQ(result, 1); User* user = get_user_by_id(4); ASSERT_TRUE(user == nullptr); }
void test_delete_user_5() { int result = delete_user(5); ASSERT_EQ(result, 1); User* user = get_user_by_id(5); ASSERT_TRUE(user == nullptr); }
void test_add_user_6() { int id = add_user("Test", "User"); ASSERT_EQ(id, 6); }
void test_add_user_7() { int id = add_user("John", "Doe"); ASSERT_EQ(id, 7); }
void test_add_user_8() { int id = add_user("Jane", "Smith"); ASSERT_EQ(id, 8); }
void test_add_user_9() { int id = add_user("Alice", "Johnson"); ASSERT_EQ(id, 9); }
void test_add_user_10() { int id = add_user("Bob", "Brown"); ASSERT_EQ(id, 10); }
void test_get_user_by_id_6() { User* user = get_user_by_id(6); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Test"); ASSERT_EQ(std::string(user->lastname), "User"); }
void test_get_user_by_id_7() { User* user = get_user_by_id(7); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "John"); ASSERT_EQ(std::string(user->lastname), "Doe"); }
void test_get_user_by_id_8() { User* user = get_user_by_id(8); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Jane"); ASSERT_EQ(std::string(user->lastname), "Smith"); }
void test_get_user_by_id_9() { User* user = get_user_by_id(9); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Alice"); ASSERT_EQ(std::string(user->lastname), "Johnson"); }
void test_get_user_by_id_10() { User* user = get_user_by_id(10); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Bob"); ASSERT_EQ(std::string(user->lastname), "Brown"); }
void test_update_user_partial_6() { int result = update_user_partial(6, "TestUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(6); ASSERT_EQ(std::string(user->name), "TestUpdated"); ASSERT_EQ(std::string(user->lastname), "User"); }
void test_update_user_partial_7() { int result = update_user_partial(7, nullptr, "DoeUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(7); ASSERT_EQ(std::string(user->name), "John"); ASSERT_EQ(std::string(user->lastname), "DoeUpdated"); }
void test_update_user_partial_8() { int result = update_user_partial(8, "JaneUpdated", "SmithUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(8); ASSERT_EQ(std::string(user->name), "JaneUpdated"); ASSERT_EQ(std::string(user->lastname), "SmithUpdated"); }
void test_update_user_partial_9() { int result = update_user_partial(9, "AliceUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(9); ASSERT_EQ(std::string(user->name), "AliceUpdated"); ASSERT_EQ(std::string(user->lastname), "Johnson"); }
void test_update_user_partial_10() { int result = update_user_partial(10, nullptr, "BrownUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(10); ASSERT_EQ(std::string(user->name), "Bob"); ASSERT_EQ(std::string(user->lastname), "BrownUpdated"); }
void test_delete_user_6() { int result = delete_user(6); ASSERT_EQ(result, 1); User* user = get_user_by_id(6); ASSERT_TRUE(user == nullptr); }
void test_delete_user_7() { int result = delete_user(7); ASSERT_EQ(result, 1); User* user = get_user_by_id(7); ASSERT_TRUE(user == nullptr); }
void test_delete_user_8() { int result = delete_user(8); ASSERT_EQ(result, 1); User* user = get_user_by_id(8); ASSERT_TRUE(user == nullptr); }
void test_delete_user_9() { int result = delete_user(9); ASSERT_EQ(result, 1); User* user = get_user_by_id(9); ASSERT_TRUE(user == nullptr); }
void test_delete_user_10() { int result = delete_user(10); ASSERT_EQ(result, 1); User* user = get_user_by_id(10); ASSERT_TRUE(user == nullptr); }
void test_add_user_11() { int id = add_user("Emma", "Wilson"); ASSERT_EQ(id, 11); }
void test_add_user_12() { int id = add_user("Oliver", "Taylor"); ASSERT_EQ(id, 12); }
void test_add_user_13() { int id = add_user("Sophia", "Anderson"); ASSERT_EQ(id, 13); }
void test_add_user_14() { int id = add_user("Liam", "Thomas"); ASSERT_EQ(id, 14); }
void test_add_user_15() { int id = add_user("Ava", "Roberts"); ASSERT_EQ(id, 15); }
void test_get_user_by_id_11() { User* user = get_user_by_id(11); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Emma"); ASSERT_EQ(std::string(user->lastname), "Wilson"); }
void test_get_user_by_id_12() { User* user = get_user_by_id(12); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Oliver"); ASSERT_EQ(std::string(user->lastname), "Taylor"); }
void test_get_user_by_id_13() { User* user = get_user_by_id(13); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Sophia"); ASSERT_EQ(std::string(user->lastname), "Anderson"); }
void test_get_user_by_id_14() { User* user = get_user_by_id(14); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Liam"); ASSERT_EQ(std::string(user->lastname), "Thomas"); }
void test_get_user_by_id_15() { User* user = get_user_by_id(15); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Ava"); ASSERT_EQ(std::string(user->lastname), "Roberts"); }
void test_update_user_partial_11() { int result = update_user_partial(11, "EmmaUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(11); ASSERT_EQ(std::string(user->name), "EmmaUpdated"); ASSERT_EQ(std::string(user->lastname), "Wilson"); }
void test_update_user_partial_12() { int result = update_user_partial(12, nullptr, "TaylorUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(12); ASSERT_EQ(std::string(user->name), "Oliver"); ASSERT_EQ(std::string(user->lastname), "TaylorUpdated"); }
void test_update_user_partial_13() { int result = update_user_partial(13, "SophiaUpdated", "AndersonUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(13); ASSERT_EQ(std::string(user->name), "SophiaUpdated"); ASSERT_EQ(std::string(user->lastname), "AndersonUpdated"); }
void test_update_user_partial_14() { int result = update_user_partial(14, "LiamUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(14); ASSERT_EQ(std::string(user->name), "LiamUpdated"); ASSERT_EQ(std::string(user->lastname), "Thomas"); }
void test_update_user_partial_15() { int result = update_user_partial(15, nullptr, "RobertsUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(15); ASSERT_EQ(std::string(user->name), "Ava"); ASSERT_EQ(std::string(user->lastname), "RobertsUpdated"); }
void test_delete_user_11() { int result = delete_user(11); ASSERT_EQ(result, 1); User* user = get_user_by_id(11); ASSERT_TRUE(user == nullptr); }
void test_delete_user_12() { int result = delete_user(12); ASSERT_EQ(result, 1); User* user = get_user_by_id(12); ASSERT_TRUE(user == nullptr); }
void test_delete_user_13() { int result = delete_user(13); ASSERT_EQ(result, 1); User* user = get_user_by_id(13); ASSERT_TRUE(user == nullptr); }
void test_delete_user_14() { int result = delete_user(14); ASSERT_EQ(result, 1); User* user = get_user_by_id(14); ASSERT_TRUE(user == nullptr); }
void test_delete_user_15() { int result = delete_user(15); ASSERT_EQ(result, 1); User* user = get_user_by_id(15); ASSERT_TRUE(user == nullptr); }
void test_add_user_16() { int id = add_user("Noah", "Clark"); ASSERT_EQ(id, 16); }
void test_add_user_17() { int id = add_user("Mia", "Walker"); ASSERT_EQ(id, 17); }
void test_add_user_18() { int id = add_user("Ethan", "Hall"); ASSERT_EQ(id, 18); }
void test_add_user_19() { int id = add_user("Isabella", "Young"); ASSERT_EQ(id, 19); }
void test_add_user_20() { int id = add_user("James", "Allen"); ASSERT_EQ(id, 20); }
void test_get_user_by_id_16() { User* user = get_user_by_id(16); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Noah"); ASSERT_EQ(std::string(user->lastname), "Clark"); }
void test_get_user_by_id_17() { User* user = get_user_by_id(17); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Mia"); ASSERT_EQ(std::string(user->lastname), "Walker"); }
void test_get_user_by_id_18() { User* user = get_user_by_id(18); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Ethan"); ASSERT_EQ(std::string(user->lastname), "Hall"); }
void test_get_user_by_id_19() { User* user = get_user_by_id(19); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Isabella"); ASSERT_EQ(std::string(user->lastname), "Young"); }
void test_get_user_by_id_20() { User* user = get_user_by_id(20); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "James"); ASSERT_EQ(std::string(user->lastname), "Allen"); }
void test_update_user_partial_16() { int result = update_user_partial(16, "NoahUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(16); ASSERT_EQ(std::string(user->name), "NoahUpdated"); ASSERT_EQ(std::string(user->lastname), "Clark"); }
void test_update_user_partial_17() { int result = update_user_partial(17, nullptr, "WalkerUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(17); ASSERT_EQ(std::string(user->name), "Mia"); ASSERT_EQ(std::string(user->lastname), "WalkerUpdated"); }
void test_update_user_partial_18() { int result = update_user_partial(18, "EthanUpdated", "HallUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(18); ASSERT_EQ(std::string(user->name), "EthanUpdated"); ASSERT_EQ(std::string(user->lastname), "HallUpdated"); }
void test_update_user_partial_19() { int result = update_user_partial(19, "IsabellaUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(19); ASSERT_EQ(std::string(user->name), "IsabellaUpdated"); ASSERT_EQ(std::string(user->lastname), "Young"); }
void test_update_user_partial_20() { int result = update_user_partial(20, nullptr, "AllenUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(20); ASSERT_EQ(std::string(user->name), "James"); ASSERT_EQ(std::string(user->lastname), "AllenUpdated"); }
void test_delete_user_16() { int result = delete_user(16); ASSERT_EQ(result, 1); User* user = get_user_by_id(16); ASSERT_TRUE(user == nullptr); }
void test_delete_user_17() { int result = delete_user(17); ASSERT_EQ(result, 1); User* user = get_user_by_id(17); ASSERT_TRUE(user == nullptr); }
void test_delete_user_18() { int result = delete_user(18); ASSERT_EQ(result, 1); User* user = get_user_by_id(18); ASSERT_TRUE(user == nullptr); }
void test_delete_user_19() { int result = delete_user(19); ASSERT_EQ(result, 1); User* user = get_user_by_id(19); ASSERT_TRUE(user == nullptr); }
void test_delete_user_20() { int result = delete_user(20); ASSERT_EQ(result, 1); User* user = get_user_by_id(20); ASSERT_TRUE(user == nullptr); }
void test_add_user_21() { int id = add_user("Charlotte", "Scott"); ASSERT_EQ(id, 21); }
void test_add_user_22() { int id = add_user("Benjamin", "Green"); ASSERT_EQ(id, 22); }
void test_add_user_23() { int id = add_user("Amelia", "Baker"); ASSERT_EQ(id, 23); }
void test_add_user_24() { int id = add_user("Lucas", "Adams"); ASSERT_EQ(id, 24); }
void test_add_user_25() { int id = add_user("Harper", "Nelson"); ASSERT_EQ(id, 25); }
void test_get_user_by_id_21() { User* user = get_user_by_id(21); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Charlotte"); ASSERT_EQ(std::string(user->lastname), "Scott"); }
void test_get_user_by_id_22() { User* user = get_user_by_id(22); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Benjamin"); ASSERT_EQ(std::string(user->lastname), "Green"); }
void test_get_user_by_id_23() { User* user = get_user_by_id(23); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Amelia"); ASSERT_EQ(std::string(user->lastname), "Baker"); }
void test_get_user_by_id_24() { User* user = get_user_by_id(24); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Lucas"); ASSERT_EQ(std::string(user->lastname), "Adams"); }
void test_get_user_by_id_25() { User* user = get_user_by_id(25); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Harper"); ASSERT_EQ(std::string(user->lastname), "Nelson"); }
void test_update_user_partial_21() { int result = update_user_partial(21, "CharlotteUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(21); ASSERT_EQ(std::string(user->name), "CharlotteUpdated"); ASSERT_EQ(std::string(user->lastname), "Scott"); }
void test_update_user_partial_22() { int result = update_user_partial(22, nullptr, "GreenUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(22); ASSERT_EQ(std::string(user->name), "Benjamin"); ASSERT_EQ(std::string(user->lastname), "GreenUpdated"); }
void test_update_user_partial_23() { int result = update_user_partial(23, "AmeliaUpdated", "BakerUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(23); ASSERT_EQ(std::string(user->name), "AmeliaUpdated"); ASSERT_EQ(std::string(user->lastname), "BakerUpdated"); }
void test_update_user_partial_24() { int result = update_user_partial(24, "LucasUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(24); ASSERT_EQ(std::string(user->name), "LucasUpdated"); ASSERT_EQ(std::string(user->lastname), "Adams"); }
void test_update_user_partial_25() { int result = update_user_partial(25, nullptr, "NelsonUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(25); ASSERT_EQ(std::string(user->name), "Harper"); ASSERT_EQ(std::string(user->lastname), "NelsonUpdated"); }
void test_delete_user_21() { int result = delete_user(21); ASSERT_EQ(result, 1); User* user = get_user_by_id(21); ASSERT_TRUE(user == nullptr); }
void test_delete_user_22() { int result = delete_user(22); ASSERT_EQ(result, 1); User* user = get_user_by_id(22); ASSERT_TRUE(user == nullptr); }
void test_delete_user_23() { int result = delete_user(23); ASSERT_EQ(result, 1); User* user = get_user_by_id(23); ASSERT_TRUE(user == nullptr); }
void test_delete_user_24() { int result = delete_user(24); ASSERT_EQ(result, 1); User* user = get_user_by_id(24); ASSERT_TRUE(user == nullptr); }
void test_delete_user_25() { int result = delete_user(25); ASSERT_EQ(result, 1); User* user = get_user_by_id(25); ASSERT_TRUE(user == nullptr); }
void test_add_user_26() { int id = add_user("Henry", "Carter"); ASSERT_EQ(id, 26); }
void test_add_user_27() { int id = add_user("Evelyn", "Mitchell"); ASSERT_EQ(id, 27); }
void test_add_user_28() { int id = add_user("Alexander", "Perez"); ASSERT_EQ(id, 28); }
void test_add_user_29() { int id = add_user("Abigail", "Roberts"); ASSERT_EQ(id, 29); }
void test_add_user_30() { int id = add_user("Daniel", "Turner"); ASSERT_EQ(id, 30); }
void test_get_user_by_id_26() { User* user = get_user_by_id(26); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Henry"); ASSERT_EQ(std::string(user->lastname), "Carter"); }
void test_get_user_by_id_27() { User* user = get_user_by_id(27); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Evelyn"); ASSERT_EQ(std::string(user->lastname), "Mitchell"); }
void test_get_user_by_id_28() { User* user = get_user_by_id(28); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Alexander"); ASSERT_EQ(std::string(user->lastname), "Perez"); }
void test_get_user_by_id_29() { User* user = get_user_by_id(29); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Abigail"); ASSERT_EQ(std::string(user->lastname), "Roberts"); }
void test_get_user_by_id_30() { User* user = get_user_by_id(30); ASSERT_TRUE(user != nullptr); ASSERT_EQ(std::string(user->name), "Daniel"); ASSERT_EQ(std::string(user->lastname), "Turner"); }
void test_update_user_partial_26() { int result = update_user_partial(26, "HenryUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(26); ASSERT_EQ(std::string(user->name), "HenryUpdated"); ASSERT_EQ(std::string(user->lastname), "Carter"); }
void test_update_user_partial_27() { int result = update_user_partial(27, nullptr, "MitchellUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(27); ASSERT_EQ(std::string(user->name), "Evelyn"); ASSERT_EQ(std::string(user->lastname), "MitchellUpdated"); }
void test_update_user_partial_28() { int result = update_user_partial(28, "AlexanderUpdated", "PerezUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(28); ASSERT_EQ(std::string(user->name), "AlexanderUpdated"); ASSERT_EQ(std::string(user->lastname), "PerezUpdated"); }
void test_update_user_partial_29() { int result = update_user_partial(29, "AbigailUpdated", nullptr); ASSERT_EQ(result, 1); User* user = get_user_by_id(29); ASSERT_EQ(std::string(user->name), "AbigailUpdated"); ASSERT_EQ(std::string(user->lastname), "Roberts"); }
void test_update_user_partial_30() { int result = update_user_partial(30, nullptr, "TurnerUpdated"); ASSERT_EQ(result, 1); User* user = get_user_by_id(30); ASSERT_EQ(std::string(user->name), "Daniel"); ASSERT_EQ(std::string(user->lastname), "TurnerUpdated"); }

int run_unit_tests() {
    TestSuite suite;
    suite.add_test("test_add_user_1", test_add_user_1);
    suite.add_test("test_add_user_2", test_add_user_2);
    suite.add_test("test_add_user_3", test_add_user_3);
    suite.add_test("test_add_user_4", test_add_user_4);
    suite.add_test("test_add_user_5", test_add_user_5);
    suite.add_test("test_get_user_by_id_1", test_get_user_by_id_1);
    suite.add_test("test_get_user_by_id_2", test_get_user_by_id_2);
    suite.add_test("test_get_user_by_id_3", test_get_user_by_id_3);
    suite.add_test("test_get_user_by_id_4", test_get_user_by_id_4);
    suite.add_test("test_get_user_by_id_5", test_get_user_by_id_5);
    suite.add_test("test_update_user_partial_1", test_update_user_partial_1);
    suite.add_test("test_update_user_partial_2", test_update_user_partial_2);
    suite.add_test("test_update_user_partial_3", test_update_user_partial_3);
    suite.add_test("test_update_user_partial_4", test_update_user_partial_4);
    suite.add_test("test_update_user_partial_5", test_update_user_partial_5);
    suite.add_test("test_delete_user_1", test_delete_user_1);
    suite.add_test("test_delete_user_2", test_delete_user_2);
    suite.add_test("test_delete_user_3", test_delete_user_3);
    suite.add_test("test_delete_user_4", test_delete_user_4);
    suite.add_test("test_delete_user_5", test_delete_user_5);
    suite.add_test("test_add_user_6", test_add_user_6);
    suite.add_test("test_add_user_7", test_add_user_7);
    suite.add_test("test_add_user_8", test_add_user_8);
    suite.add_test("test_add_user_9", test_add_user_9);
    suite.add_test("test_add_user_10", test_add_user_10);
    suite.add_test("test_get_user_by_id_6", test_get_user_by_id_6);
    suite.add_test("test_get_user_by_id_7", test_get_user_by_id_7);
    suite.add_test("test_get_user_by_id_8", test_get_user_by_id_8);
    suite.add_test("test_get_user_by_id_9", test_get_user_by_id_9);
    suite.add_test("test_get_user_by_id_10", test_get_user_by_id_10);
    suite.add_test("test_update_user_partial_6", test_update_user_partial_6);
    suite.add_test("test_update_user_partial_7", test_update_user_partial_7);
    suite.add_test("test_update_user_partial_8", test_update_user_partial_8);
    suite.add_test("test_update_user_partial_9", test_update_user_partial_9);
    suite.add_test("test_update_user_partial_10", test_update_user_partial_10);
    suite.add_test("test_delete_user_6", test_delete_user_6);
    suite.add_test("test_delete_user_7", test_delete_user_7);
    suite.add_test("test_delete_user_8", test_delete_user_8);
    suite.add_test("test_delete_user_9", test_delete_user_9);
    suite.add_test("test_delete_user_10", test_delete_user_10);
    suite.add_test("test_add_user_11", test_add_user_11);
    suite.add_test("test_add_user_12", test_add_user_12);
    suite.add_test("test_add_user_13", test_add_user_13);
    suite.add_test("test_add_user_14", test_add_user_14);
    suite.add_test("test_add_user_15", test_add_user_15);
    suite.add_test("test_get_user_by_id_11", test_get_user_by_id_11);
    suite.add_test("test_get_user_by_id_12", test_get_user_by_id_12);
    suite.add_test("test_get_user_by_id_13", test_get_user_by_id_13);
    suite.add_test("test_get_user_by_id_14", test_get_user_by_id_14);
    suite.add_test("test_get_user_by_id_15", test_get_user_by_id_15);
    suite.add_test("test_update_user_partial_11", test_update_user_partial_11);
    suite.add_test("test_update_user_partial_12", test_update_user_partial_12);
    suite.add_test("test_update_user_partial_13", test_update_user_partial_13);
    suite.add_test("test_update_user_partial_14", test_update_user_partial_14);
    suite.add_test("test_update_user_partial_15", test_update_user_partial_15);
    suite.add_test("test_delete_user_11", test_delete_user_11);
    suite.add_test("test_delete_user_12", test_delete_user_12);
    suite.add_test("test_delete_user_13", test_delete_user_13);
    suite.add_test("test_delete_user_14", test_delete_user_14);
    suite.add_test("test_delete_user_15", test_delete_user_15);
    suite.add_test("test_add_user_16", test_add_user_16);
    suite.add_test("test_add_user_17", test_add_user_17);
    suite.add_test("test_add_user_18", test_add_user_18);
    suite.add_test("test_add_user_19", test_add_user_19);
    suite.add_test("test_add_user_20", test_add_user_20);
    suite.add_test("test_get_user_by_id_16", test_get_user_by_id_16);
    suite.add_test("test_get_user_by_id_17", test_get_user_by_id_17);
    suite.add_test("test_get_user_by_id_18", test_get_user_by_id_18);
    suite.add_test("test_get_user_by_id_19", test_get_user_by_id_19);
    suite.add_test("test_get_user_by_id_20", test_get_user_by_id_20);
    suite.add_test("test_update_user_partial_16", test_update_user_partial_16);
    suite.add_test("test_update_user_partial_17", test_update_user_partial_17);
    suite.add_test("test_update_user_partial_18", test_update_user_partial_18);
    suite.add_test("test_update_user_partial_19", test_update_user_partial_19);
    suite.add_test("test_update_user_partial_20", test_update_user_partial_20);
    suite.add_test("test_delete_user_16", test_delete_user_16);
    suite.add_test("test_delete_user_17", test_delete_user_17);
    suite.add_test("test_delete_user_18", test_delete_user_18);
    suite.add_test("test_delete_user_19", test_delete_user_19);
    suite.add_test("test_delete_user_20", test_delete_user_20);
    suite.add_test("test_add_user_21", test_add_user_21);
    suite.add_test("test_add_user_22", test_add_user_22);
    suite.add_test("test_add_user_23", test_add_user_23);
    suite.add_test("test_add_user_24", test_add_user_24);
    suite.add_test("test_add_user_25", test_add_user_25);
    suite.add_test("test_get_user_by_id_21", test_get_user_by_id_21);
    suite.add_test("test_get_user_by_id_22", test_get_user_by_id_22);
    suite.add_test("test_get_user_by_id_23", test_get_user_by_id_23);
    suite.add_test("test_get_user_by_id_24", test_get_user_by_id_24);
    suite.add_test("test_get_user_by_id_25", test_get_user_by_id_25);
    suite.add_test("test_update_user_partial_21", test_update_user_partial_21);
    suite.add_test("test_update_user_partial_22", test_update_user_partial_22);
    suite.add_test("test_update_user_partial_23", test_update_user_partial_23);
    suite.add_test("test_update_user_partial_24", test_update_user_partial_24);
    suite.add_test("test_update_user_partial_25", test_update_user_partial_25);
    suite.add_test("test_delete_user_21", test_delete_user_21);
    suite.add_test("test_delete_user_22", test_delete_user_22);
    suite.add_test("test_delete_user_23", test_delete_user_23);
    suite.add_test("test_delete_user_24", test_delete_user_24);
    suite.add_test("test_delete_user_25", test_delete_user_25);
    suite.add_test("test_add_user_26", test_add_user_26);
    suite.add_test("test_add_user_27", test_add_user_27);
    suite.add_test("test_add_user_28", test_add_user_28);
    suite.add_test("test_add_user_29", test_add_user_29);
    suite.add_test("test_add_user_30", test_add_user_30);
    suite.add_test("test_get_user_by_id_26", test_get_user_by_id_26);
    suite.add_test("test_get_user_by_id_27", test_get_user_by_id_27);
    suite.add_test("test_get_user_by_id_28", test_get_user_by_id_28);
    suite.add_test("test_get_user_by_id_29", test_get_user_by_id_29);
    suite.add_test("test_get_user_by_id_30", test_get_user_by_id_30);
    suite.add_test("test_update_user_partial_26", test_update_user_partial_26);
    suite.add_test("test_update_user_partial_27", test_update_user_partial_27);
    suite.add_test("test_update_user_partial_28", test_update_user_partial_28);
    suite.add_test("test_update_user_partial_29", test_update_user_partial_29);
    suite.add_test("test_update_user_partial_30", test_update_user_partial_30);
    suite.run();
    return 0;
}
