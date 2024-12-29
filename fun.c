#include <stdio.h>
#include"function.h"
#include <string.h>
//khai bao logic ham

// Ham hien thi menu
void displayMenu() {
    printf("\n=== Menu Quan ly Danh Muc ===\n");
    printf("1. Hien thi danh sach danh muc\n");
    printf("2. Them danh muc\n");
    printf("3. Sua danh muc\n");
    printf("4. Xoa danh muc\n");
    printf("5. Tim kiem danh muc theo ten\n");
    printf("6. Sap xep danh muc theo ten\n");
    printf("7. Luu du lieu\n");
    printf("8. Doc du lieu tu file\n");
    printf("9. Thoat\n");
    printf("Nhap lua chon: ");
}

// Ham hien thi danh sach danh muc

void displayCategories() {
    if (categoryCount == 0) {
        printf("Danh muc hien tai trong.\n");
        return;
    }
    printf("\nDanh sach danh muc:\n");
    printf("ID\tTen danh muc\n");
    printf("------------------------------\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%d\t%s\n", categories[i].id, categories[i].name);
        printf("------------------------------\n");
    }
}

// Ham them danh muc
void addCategory() {
    if (categoryCount >= 100) {
        printf("Khong the them danh muc moi. Dung luong da day.\n");
        return;
    }
    Category newCategory;
    printf("Nhap ID danh muc: ");
    scanf("%d", &newCategory.id);
    getchar();  // Xoa ky tu '\n' con lai sau scanf

    // Kiem tra trung ID
    for (int i = 0; i < categoryCount; i++) {
        if (categories[i].id == newCategory.id) {
            printf("ID danh muc da ton tai.\n");
            return;
        }
    }

    printf("Nhap ten danh muc: ");
    fgets(newCategory.name, 100, stdin);
    newCategory.name[strcspn(newCategory.name, "\n")] = '\0';  // Loai bo ky tu '\n'

    categories[categoryCount++] = newCategory;
    printf("Danh muc da duoc them thanh cong!\n");
}

// Ham sua danh muc
void editCategory() {
    int id;
    printf("Nhap ID danh muc can sua: ");
    scanf("%d", &id);
    getchar();  // Xoa ky tu '\n'

    int found = 0;
    for (int i = 0; i < categoryCount; i++) {
        if (categories[i].id == id) {
            found = 1;
            printf("Nhap ten moi cho danh muc: ");
            fgets(categories[i].name, 100, stdin);
            categories[i].name[strcspn(categories[i].name, "\n")] = '\0';
            printf("Danh muc da duoc sua thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Danh muc voi ID %d khong ton tai.\n", id);
    }
}

// Ham xoa danh muc
void deleteCategory() {
    int id;
    printf("Nhap ID danh muc can xoa: ");
    scanf("%d", &id);
    getchar();  // Xoa ky tu '\n'

    int found = 0;
    for (int i = 0; i < categoryCount; i++) {
        if (categories[i].id == id) {
            found = 1;
            // Xoa danh muc bang cach di chuyen cac muc sau len
            for (int j = i; j < categoryCount - 1; j++) {
                categories[j] = categories[j + 1];
            }
            categoryCount--;
            printf("Danh muc voi ID %d da duoc xoa thanh cong!\n", id);
            break;
        }
    }

    if (!found) {
        printf("Danh muc voi ID %d khong ton tai.\n", id);
    }
}

// Ham tim kiem danh muc theo ten
void searchCategory() {
    char name[100];
    printf("Nhap ten danh muc can tim: ");
    getchar();  // Xoa ky tu '\n' con lai
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';  // Loai bo ky tu '\n'

    int found = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < categoryCount; i++) {
        if (strstr(categories[i].name, name)) {
            printf("ID: %d, Ten: %s\n", categories[i].id, categories[i].name);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay danh muc nao.\n");
    }
}

// Ham sap xep danh muc theo ten
void sortCategories() {
    for (int i = 0; i < categoryCount - 1; i++) {
        for (int j = i + 1; j < categoryCount; j++) {
            if (strcmp(categories[i].name, categories[j].name) > 0) {
                Category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }
    printf("Danh muc da duoc sap xep theo ten.\n");
}

// Ham luu danh muc vao file
void saveData() {
    FILE *file = fopen("categories.dat", "wb");
    if (file == NULL) {
        printf("Khong the mo file de luu du lieu.\n");
        return;
    }

    fwrite(&categoryCount, sizeof(int), 1, file);
    fwrite(categories, sizeof(Category), categoryCount, file);
    fclose(file);
    printf("Du lieu da duoc luu vao file.\n");
}

// Ham doc danh muc tu file
void loadData() {
    FILE *file = fopen("categories.dat", "rb");
    if (file == NULL) {
        printf("Khong the mo file de doc du lieu.\n");
        return;
    }

    fread(&categoryCount, sizeof(int), 1, file);
    fread(categories, sizeof(Category), categoryCount, file);
    fclose(file);
    printf("Du lieu da duoc doc tu file.\n");
}
