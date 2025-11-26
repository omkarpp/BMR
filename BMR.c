#include <stdio.h>

// Function prototypes
float calculateBMR(float weight, float height, int age, char gender);
void rateBMR(float bmr);
void suggestNutrition(float bmr);
void suggestDiet(float bmr);

int main() {
    float weight, height, bmr;
    int age;
    char gender;

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Enter your height in cm: ");
    scanf("%f", &height);

    printf("Enter your age in years: ");
    scanf("%d", &age);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    bmr = calculateBMR(weight, height, age, gender);

    printf("\nYour BMR is: %.2f calories/day\n", bmr);

    rateBMR(bmr);

    suggestNutrition(bmr);

    suggestDiet(bmr);

    return 0;
}

// Calculate BMR using Mifflin-St Jeor Equation
float calculateBMR(float weight, float height, int age, char gender) {
    if (gender == 'M' || gender == 'm') {
        return 10 * weight + 6.25 * height - 5 * age + 5;
    } else if (gender == 'F' || gender == 'f') {
        return 10 * weight + 6.25 * height - 5 * age - 161;
    } else {
        printf("Invalid gender input.\n");
        return 0;
    }
}

// Rate BMR based on general thresholds
void rateBMR(float bmr) {
    printf("BMR Rating: ");
    if (bmr < 1200) {
        printf("Low - You may need to increase your metabolic rate.\n");
    } else if (bmr <= 1800) {
        printf("Normal - Your metabolism is within the average range.\n");
    } else {
        printf("High - You have a high metabolic rate.\n");
    }
}

// Suggest daily protein and calorie intake based on BMR
void suggestNutrition(float bmr) {
    float protein, calories;
    // Protein intake recommendation based on weight (approximate)
    // Assuming user weight approx from BMR, or just use BMR for calories
    calories = bmr * 1.2;  // light activity factor
    protein = 0.8 * (calories / 4) / 4; // approximate grams protein/day assuming 1g protein = 4 cal

    printf("\nRecommended daily calories intake: %.0f cal\n", calories);

    // Typical protein recommendations: 0.8 to 1g per kg of bodyweight,
    // but since no weight here passed, just give generic guidance
    printf("Recommended daily protein intake: %.0f grams (approximate)\n", protein);
}

// Suggest diet tips to improve BMR
void suggestDiet(float bmr) {
    printf("\nDiet suggestions to optimize BMR:\n");
    if (bmr < 1200) {
        printf("- Increase protein intake to build muscle which boosts metabolism.\n");
        printf("- Include nutrient-dense, whole foods like lean meats, legumes, and vegetables.\n");
        printf("- Stay hydrated and get regular exercise.\n");
    } else if (bmr <= 1800) {
        printf("- Maintain balanced diet with adequate protein, carbs, and healthy fats.\n");
        printf("- Include fiber-rich foods to aid digestion.\n");
        printf("- Regular physical activity helps sustain metabolic rate.\n");
    } else {
        printf("- Keep a balanced diet to support your high metabolism.\n");
        printf("- Monitor calorie intake to maintain healthy weight.\n");
        printf("- Avoid excessive fasting or skipping meals.\n");
    }
}
