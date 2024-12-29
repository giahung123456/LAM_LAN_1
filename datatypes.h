#include<stdbool.h>


// Cau truc du lieu danh muc
typedef struct {
    int id;
    char name[100];
} Category;
 Category categories[100];  // So luong danh muc khong co dinh ma co the thay doi
  int categoryCount = 0;