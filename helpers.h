#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEALS 25
#define MAX_INGREDIENTS 50
#define MAX_NAME_LEN 100
#define MAX_INGREDIENT_LEN 100

// Struct definition: each Meal contains a name and a list of ingredients
typedef struct {
    char name[MAX_NAME_LEN];
    char ingredients[MAX_INGREDIENTS][MAX_INGREDIENT_LEN];
    int ingredient_count;
} Meal;

// Function prototypes - return-value functions
int addMeal(Meal *meals, int *meal_count, const char *meal_name);
int addIngredient(Meal *meal, const char *ingredient);
int viewMeals(Meal *meals, int meal_count);
int viewIngredients(Meal *meal);

// Function prototypes - pointer functions for file I/O
void saveMealsToFile(Meal *meals, int meal_count, const char *filename);
Meal* loadMealsFromFile(const char *filename, int *meal_count);

// Helper functions
void initializeMeals(Meal *meals, int size);
int findMealIndex(Meal *meals, int meal_count, const char *meal_name);
void displayMenu(void);
int isMealFull(int meal_count);
int isMealIngredientsMaxed(Meal *meal);

#endif
