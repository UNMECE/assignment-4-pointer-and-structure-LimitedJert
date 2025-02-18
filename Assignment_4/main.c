// main.c
#include "item.h"

int main(int argc, char *argv[]) {
    // dynamically allocate space for 5 items at the moment
    int size = 5;
    Item *item_list = malloc(size * sizeof(Item));
    
    if (!item_list) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // using an add item function to add 5 different items
    add_item(item_list, 5.0, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 7.50, "10984", "snacks", "chips", 2);
    add_item(item_list, 10.00, "24980", "beverages", "orange juice", 3);
    add_item(item_list, 2.75, "34092", "produce", "apple", 4);

    //  print all the items listed
    print_items(item_list, size);

    //  calculate the average price
    double avg_price = average_price(item_list, size);
    printf("\nAverage price of items = %.6f\n", avg_price);

    // 5. free all allocated memory so it dosent clog up the ram
    free_items(item_list, size);

    // command line argument processing for searching item
    if (argc == 2) {
        char *sku_to_search = argv[1];
        int found = 0;
        
        // Search for the item by SKU
        int ct = 0;
        while (ct < size && strcmp(item_list[ct].sku, sku_to_search) != 0) {
            ct++;
        }

        if (ct < size) {
            // print the found item
            printf("\nItem found:\n");
            printf("Item name: %s\n", item_list[ct].name);
            printf("Item sku: %s\n", item_list[ct].sku);
            printf("Item category: %s\n", item_list[ct].category);
            printf("Item price: %.2f\n", item_list[ct].price);
            found = 1;
        }

        if (!found) {
            printf("\nItem not found.\n");
        }
    }

    return 0;
}
