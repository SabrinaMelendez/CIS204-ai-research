#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main() {
    // Approach: Declare an array of Meal structs to store multiple meals, with a counter for the number of meals added.
    // This allows dynamic management of meals without fixed sizes beyond the defined maximum.
    Meal meals[MAX_MEALS];
    int meal_count = 0;

    // Approach: Initialize the meals array to ensure all fields are set to default values, preventing undefined behavior.
    initializeMeals(meals, MAX_MEALS);

    int choice;
    char meal_name[MAX_NAME_LEN];
    char ingredient[MAX_INGREDIENT_LEN];
    int meal_index;

    // Approach: Use a do-while loop to repeatedly display the menu and process user choices until the user chooses to exit.
    // This provides a continuous interaction loop for the meal management system.
    do {
        // Approach: Display the menu options to guide the user on available actions.
        displayMenu();

        // Approach: Prompt the user for their choice using scanf to read an integer input.
        // Validate the input to ensure it falls within the expected range.
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                // Approach: For adding a meal, prompt the user for the meal name.
                // Use fgets or scanf with buffer size to safely read the input string.
                // Then call the addMeal function to add it to the array, checking for success.
                printf("Enter meal name: ");
                fgets(meal_name, MAX_NAME_LEN, stdin);
                meal_name[strcspn(meal_name, "\n")] = 0; // Remove newline
                if (addMeal(meals, &meal_count, meal_name) == 0) {
                    printf("Meal added successfully.\n");
                } else {
                    printf("Failed to add meal. Maximum meals reached.\n");
                }
                break;
            case 2:
                // Approach: For adding an ingredient, first prompt for the meal name to identify which meal to modify.
                // Find the meal index using a helper function.
                // Then prompt for the ingredient name and call addIngredient, handling errors if the meal is not found or full.
                printf("Enter meal name: ");
                fgets(meal_name, MAX_NAME_LEN, stdin);
                meal_name[strcspn(meal_name, "\n")] = 0;
                meal_index = findMealIndex(meals, meal_count, meal_name);
                if (meal_index == -1) {
                    printf("Meal not found.\n");
                    break;
                }
                
                // Loop to add multiple ingredients until user enters 'quit'
                while (1) {
                    printf("Enter ingredient (or 'quit' to exit): ");
                    fgets(ingredient, MAX_INGREDIENT_LEN, stdin);
                    ingredient[strcspn(ingredient, "\n")] = 0;
                    
                    if (strcmp(ingredient, "quit") == 0) {
                        break;
                    }
                    
                    if (addIngredient(&meals[meal_index], ingredient) == 0) {
                        printf("Ingredient added successfully.\n");
                    } else {
                        printf("Failed to add ingredient. Maximum ingredients reached.\n");
                    }
                }
                break;
            case 3:
                // Approach: For viewing meals, simply call the viewMeals function which iterates through the array and prints formatted output.
                // This provides a clear display of all meals and their ingredients.
                viewMeals(meals, meal_count);
                break;
            case 4:
                // Approach: For saving meals, prompt for a filename and call saveMealsToFile to write the data to a file.
                // This uses file I/O functions to persist the meal data.
                printf("Enter filename to save: ");
                char filename[100];
                scanf("%s", filename);
                saveMealsToFile(meals, meal_count, filename);
                printf("Meals saved to %s.\n", filename);
                break;
            case 5:
                // Approach: For loading meals, prompt for a filename and call loadMealsFromFile to read data from a file.
                // Update the meal_count and reinitialize if necessary.
                printf("Enter filename to load: ");
                scanf("%s", filename);
                Meal *loaded_meals = loadMealsFromFile(filename, &meal_count);
                if (loaded_meals != NULL) {
                    memcpy(meals, loaded_meals, sizeof(Meal) * meal_count);
                    free(loaded_meals);
                    printf("Meals loaded from %s.\n", filename);
                } else {
                    printf("Failed to load meals.\n");
                }
                break;
            case 6:
                // Approach: Exit the program by breaking out of the loop.
                printf("Exiting...\n");
                break;
            default:
                // Approach: Handle invalid choices by informing the user and continuing the loop.
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Approach: Return 0 to indicate successful program execution.
    return 0;
}