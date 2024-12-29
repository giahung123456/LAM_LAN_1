#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCategories();
                break;
            case 2:
                addCategory();
                break;
            case 3:
                editCategory();
                break;
            case 4:
                deleteCategory();
                break;
            case 5:
                searchCategory();
                break;
            case 6:
                sortCategories();
                break;
            case 7:
                saveData();
                break;
            case 8:
                loadData();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 9);

	return 0;
}