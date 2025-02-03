#include <stdio.h>
#include <stdbool.h>

// Evaluates non-negative prefix sum of an integer array
bool non_neg_prefix_sum(const int* arr, size_t len) {
    int sum = 0;
    while (len--) {
        sum += *arr++;
        if (sum < 0) {
            return false;
        }
    }
    return true;
}

// Evaluates non-positive prefix sum of an integer array
bool non_pos_prefix_sum(const int* arr, size_t len) {
    int sum = 0;
    while (len--) {
        sum += *arr++;
        if (sum > 0) {
            return false;
        }
    }
    return true;
}

// Prints the result of the prefix sum checks
void print_result(bool result, const char* list_name, const char* function_name) {
    printf("%s: %s returns %s.\n", list_name, function_name, result ? "true" : "false");
}

int main(void) {
    int lst1[] = { 1, -1, 1, -1 };
    int lst2[] = { 1, -1, -1, 1 };
    int lst3[] = { -1, 1, -1, 1 };
    int lst4[] = { -1, 1, 1, -1 };
    size_t len1 = sizeof(lst1) / sizeof(lst1[0]);
    size_t len2 = sizeof(lst2) / sizeof(lst2[0]);
    size_t len3 = sizeof(lst3) / sizeof(lst3[0]);
    size_t len4 = sizeof(lst4) / sizeof(lst4[0]);

    // Check and print results for each list
    print_result(non_neg_prefix_sum(lst1, len1), "lst1", "non_neg_prefix_sum");
    print_result(non_neg_prefix_sum(lst2, len2), "lst2", "non_neg_prefix_sum");
    print_result(non_pos_prefix_sum(lst3, len3), "lst3", "non_pos_prefix_sum");
    print_result(non_pos_prefix_sum(lst4, len4), "lst4", "non_pos_prefix_sum");

    return 0;
}

