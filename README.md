# CIS204-ai-research
## Program Purpose 
- A user will use the program to plan meals for weekdays and keep a list of ingredients to keep on hand.
- The program solves the problem of remembering what to make for meals and provides support when making a grocery list.
- The program stores inputs from the user of meals they want to make and ingredients they'd like to buy and outputs the meals for the user or ingredients. 
## Input, Output, and Memory Management 
- The user will need to provide inputs of the meals they want to make and ingredients they'd like to buy.
- The output will be the same as the input, list of meals or ingredients. 
- The program will need to define an array of meals and an array of ingredients.
- The program will support up to 25 meals and 50 grocery items. 
## Functions Needed  
- void addMeals();
- void addIngredients();
- void viewMeals();
- void viewIngredients();
## Data Structures 
- struct MealsIngredients {
    char meals[25];
    char ingredients[50]; 
};
## File Responsibilities - The following files are required in your project submission. 
Describe the purpose and contents of each file. 
- main.c the main code
- meals.txt text file for meals
- ingredients.txt text file for ingredients. 
## Research Plan - Write a 250 words describing your strategy for using AI to help you to write the code for this project. 
I will use AI to help me write parts of my code, not the entire assignment. First, I can use the following prompt: "Create a menu to ask the user to input either a list of meals or a list of ingredients. " This will help me with the wording I can use to prompt the user for their input. 

Next, I will use AI to help write functions that store user input into arrays and display that data back to the user. Since my program uses arrays with fixed sizes (25 meals and 50 ingredients), I will also ask the AI how to prevent overflow and ensure the program handles input safely. An example of a prompt would be: "Help me write functions for the arrays for meals and ingredients". 

I will also use AI to assist with file handling so that meals and ingredients are saved into separate text files and loaded when the program runs again. I may use functions such as fopen, fprintf, and fscanf. If I encounter errors or bugs, I will provide my code and error messages to AI and ask for help debugging and fixing the issues.

Additionally, I will ask AI to explain any code I do not fully understand so I can learn the concepts behind it. Some of the concepts throughout the class have been difficult to grasp. My goal is to use AI as a learning tool to improve my coding skills while still understanding how the program works. An example: "Please explain how my code uses data structures".