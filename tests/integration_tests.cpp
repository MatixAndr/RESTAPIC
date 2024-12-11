//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "../src/user.h"
#include "../src/server.h"

START_TEST(test_http_request_parsing)
{
    const char* raw_request =
        "GET /users HTTP/1.1\r\n"
        "Host: localhost\r\n"
        "\r\n";

    HttpRequest request;
    int result = parse_http_request(raw_request, &request);

    ck_assert_int_eq(result, 1);
    ck_assert_str_eq(request.method, "GET");
    ck_assert_str_eq(request.path, "/users");
    ck_assert_str_eq(request.protocol, "HTTP/1.1");
}
END_TEST

START_TEST(test_http_response_generation)
{
    HttpResponse response;
    const char* test_body = "{\"test\": \"data\"}";

    prepare_http_response(&response, 200, "application/json", test_body);

    ck_assert_int_eq(response.status_code, 200);
    ck_assert_str_eq(response.status_message, "OK");
    ck_assert_str_eq(response.content_type, "application/json");
    ck_assert_str_eq(response.body, test_body);
}
END_TEST

Suite * integration_suite(void) {
    Suite *s = suite_create("Integration Tests");

    TCase *tc_http = tcase_create("HTTP Handling");

    tcase_add_test(tc_http, test_http_request_parsing);
    tcase_add_test(tc_http, test_http_response_generation);

    suite_add_tcase(s, tc_http);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = integration_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}