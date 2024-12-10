//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include <check.h>
#include "../src/user.h"

START_TEST(test_add_user)
{
    int id = add_user("Jan", "Kowalski");
    ck_assert_int_eq(id, 1);

    User* user = get_user_by_id(id);
    ck_assert_ptr_ne(user, NULL);
    ck_assert_str_eq(user->name, "Jan");
    ck_assert_str_eq(user->lastname, "Kowalski");
}
END_TEST

START_TEST(test_get_user_by_id)
{
    add_user("Anna", "Nowak");
    User* user = get_user_by_id(2);

    ck_assert_ptr_ne(user, NULL);
    ck_assert_str_eq(user->name, "Anna");
    ck_assert_str_eq(user->lastname, "Nowak");
}
END_TEST

START_TEST(test_update_user_partial)
{
    int id = add_user("Piotr", "Zieliński");

    int result = update_user_partial(id, "Paweł", NULL);
    ck_assert_int_eq(result, 1);

    User* user = get_user_by_id(id);
    ck_assert_str_eq(user->name, "Paweł");
    ck_assert_str_eq(user->lastname, "Zieliński");
}
END_TEST

START_TEST(test_delete_user)
{
    int id = add_user("Marek", "Kowalczyk");

    int result = delete_user(id);
    ck_assert_int_eq(result, 1);

    User* user = get_user_by_id(id);
    ck_assert_ptr_eq(user, NULL);
}
END_TEST

Suite * user_suite(void) {
    Suite *s = suite_create("User Management");

    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add_user);
    tcase_add_test(tc_core, test_get_user_by_id);
    tcase_add_test(tc_core, test_update_user_partial);
    tcase_add_test(tc_core, test_delete_user);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = user_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}