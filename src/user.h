//
// Created by MateuszAndruszkiewic on 3.12.2024.
//

#ifndef USER_H
#define USER_H

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char lastname[MAX_NAME_LENGTH];
} User;

int add_user(const char* name, const char* lastname);
User* get_user_by_id(int id);
int update_user_partial(int id, const char* name, const char* lastname);
int update_user_full(int id, const char* name, const char* lastname);
int delete_user(int id);
User* get_all_users(int* count);

#endif // USER_H