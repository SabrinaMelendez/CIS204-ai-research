#include "helpers.h"

// Function to add a new meal to the meals array
int addMeal(Meal *meals, int *meal_count, const char *meal_name) {
    // Check if the maximum number of meals has been reached
    if (isMealFull(*meal_count)) {
        return -1; // Return error status
    }

    // If not, copy the meal name to the next available meal slot
    strcpy(meals[*meal_count].name, meal_name);
    // Initialize the ingredient count for the new meal to 0
    meals[*meal_count].ingredient_count = 0;
    // Increment the meal count
    (*meal_count)++;
    // Return success status
    return 0;
}

// Function to add an ingredient to a specific meal
int addIngredient(Meal *meal, const char *ingredient) {
    // Check if the meal's ingredient count is less than MAX_INGREDIENTS
    if (meal->ingredient_count >= MAX_INGREDIENTS) {
        return -1; // Return error status
    }
    // Copy the ingredient name to the next available ingredient slot in the meal
    strcpy(meal->ingredients[meal->ingredient_count], ingredient);
    // Increment the meal's ingredient count
    meal->ingredient_count++;
    // Return success status
    return 0;
}

// Function to display all meals
int viewMeals(Meal *meals, int meal_count) {
    // Loop through each meal in the meals array up to meal_count
    for (int i = 0; i < meal_count; i++) {
        printf("Meal: %s\n", meals[i].name);
        printf("Ingredients:\n");
        for (int j = 0; j < meals[i].ingredient_count; j++) {
            printf(" - %s\n", meals[i].ingredients[j]);
        }
        printf("\n");
    }
    // Print the meal name and its ingredients
    printf("Total meals: %d\n", meal_count);

    // Return success status
    return 0;
}

// Function to display ingredients for a specific meal
int viewIngredients(Meal *meal) {
    // Loop through each ingredient in the meal's ingredients array up to ingredient_count
    for (int i = 0; i < meal->ingredient_count; i++) {
        printf(" - %s\n", meal->ingredients[i]);
    }
    // Print each ingredient
    printf("Total ingredients: %d\n", meal->ingredient_count);
    // Return success status
    return 0;
}

// Function to save meals to a file
void saveMealsToFile(Meal *meals, int meal_count, const char *filename) {
    // Open the file for writing
    FILE *file = fopen(filename, "w");
    // Check if the file was opened successfully
    if (!file) {
        fprintf(stderr, "Error: Could not open file for writing.\n");
        return;
    }
    // Write the meal count to the file
    fprintf(file, "%d\n", meal_count);
    // Loop through each meal and write the meal name and ingredients to the file
    for (int i = 0; i < meal_count; i++) {
        fprintf(file, "%s\n", meals[i].name);
        fprintf(file, "%d\n", meals[i].ingredient_count);
        for (int j = 0; j < meals[i].ingredient_count; j++) {
            fprintf(file, "%s\n", meals[i].ingredients[j]);
        }
    }
    // Close the file
    fclose(file);
}

// Function to load meals from a file
Meal* loadMealsFromFile(const char *filename, int *meal_count) {
    // Allocate memory for meals array
    Meal *meals = malloc(sizeof(Meal) * MAX_MEALS);
    // Check if memory allocation was successful
    if (!meals) {
        fprintf(stderr, "Error: Could not allocate memory for meals.\n");
        return NULL;
    }
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    // Check if the file was opened successfully
    if (!file) {
        fprintf(stderr, "Error: Could not open file for reading.\n");
        free(meals);
        return NULL;
    }
    // Read the meal count from the file
    fscanf(file, "%d", meal_count);
    // Read meals and ingredients from the file into the meals array
    for (int i = 0; i < *meal_count; i++) {
        fscanf(file, "%s", meals[i].name);
        fscanf(file, "%d", &meals[i].ingredient_count);
        for (int j = 0; j < meals[i].ingredient_count; j++) {
            fscanf(file, "%s", meals[i].ingredients[j]);
        }
    }
    // Close the file
    fclose(file);

    // Return the meals array
    return meals;
}

// Function to initialize the meals array
void initializeMeals(Meal *meals, int size) {
    // Loop through each meal in the array
    for (int i = 0; i < size; i++) {
        // Set the name to empty string
        strcpy(meals[i].name, "");
        // Set ingredient_count to 0
        meals[i].ingredient_count = 0;
    }
}

// Function to find the index of a meal by name
int findMealIndex(Meal *meals, int meal_count, const char *meal_name) {
    // Loop through each meal in the meals array
    for (int i = 0; i < meal_count; i++) {
        // Compare the meal name with the provided name
        if (strcmp(meals[i].name, meal_name) == 0) {
            // If match found, return the index
            return i;
        }
    }
    // If no match, return -1
    return -1;
}

// Function to display the menu options
void displayMenu(void) {
    // Print the menu options for the user
    printf("\n=== Meal Management Menu ===\n");
    printf("1. Add a meal\n");
    printf("2. Add an ingredient to a meal\n");
    printf("3. View all meals\n");
    printf("4. Save meals to a file\n");
    printf("5. Load meals from a file\n");
    printf("6. Exit\n");
    printf("===========================\n");
}

// Function to check if meals array is full
int isMealFull(int meal_count) {
    // Compare meal_count with MAX_MEALS
    // Return 1 if full, 0 otherwise
    return 0;
}

// Function to check if a meal's ingredients are at maximum
int isMealIngredientsMaxed(Meal *meal) {
    // Compare meal's ingredient_count with MAX_INGREDIENTS
    if (meal->ingredient_count >= MAX_INGREDIENTS) {
        return 1; // Maxed
    }
    // Return 1 if maxed, 0 otherwise
    if (meal->ingredient_count >= MAX_INGREDIENTS) {
        return 1; // Maxed
    }
    return 0;
}