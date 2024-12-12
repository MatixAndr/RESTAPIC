//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#include "test_framework.h"
#include "../src/user.h"
#include "../src/server.h"
#include <iostream>

void test_http_request_parsing() {
    const char* raw_request =
        "GET /users HTTP/1.1\r\n"
        "Host: localhost\r\n"
        "\r\n";

    HttpRequest request;
    int result = parse_http_request(raw_request, &request);

    ASSERT_EQ(result, 1);
    ASSERT_EQ(std::string(request.method), "GET");
    ASSERT_EQ(std::string(request.path), "/users");
    ASSERT_EQ(std::string(request.protocol), "HTTP/1.1");
}

void test_http_response_generation() {
    HttpResponse response;
    const char* test_body = "{\"test\": \"data\"}";

    prepare_http_response(&response, 200, "application/json", test_body);

    ASSERT_EQ(response.status_code, 200);
    ASSERT_EQ(std::string(response.status_message), "OK");
    ASSERT_EQ(std::string(response.content_type), "application/json");
    ASSERT_EQ(std::string(response.body), test_body);
}

int run_integration_tests() {
    TestSuite suite;
    suite.add_test("test_http_request_parsing", test_http_request_parsing);
    suite.add_test("test_http_response_generation", test_http_response_generation);
    suite.run();
    return 0;
}