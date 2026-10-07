#include <stdio.h>

#define MAX 100

struct Package
{
    int id;
    float value;
    float weight;
    float ratio;
    float fraction;
};

void enterPackages(struct Package p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("\nEnter details for Package %d:\n", i + 1);

        printf("Enter value/profit: ");
        scanf("%f", &p[i].value);

        printf("Enter weight: ");
        scanf("%f", &p[i].weight);

        p[i].ratio = p[i].value / p[i].weight;
        p[i].fraction = 0;
    }

    printf("\nPackage details entered successfully.\n");
}

void displayPackages(struct Package p[], int n)
{
    int i;

    printf("\n---------------------------------------------------------\n");
    printf("Package\tValue\tWeight\tValue/Weight Ratio\n");
    printf("---------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id,
               p[i].value,
               p[i].weight,
               p[i].ratio);
    }

    printf("---------------------------------------------------------\n");
}

void calculateRatio(struct Package p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        p[i].ratio = p[i].value / p[i].weight;
    }

    printf("\nValue/Weight ratios calculated successfully.\n");

    for (i = 0; i < n; i++)
    {
        printf("Package %d: %.2f\n", p[i].id, p[i].ratio);
    }
}

void sortPackages(struct Package p[], int n)
{
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nPackages sorted in decreasing order of Value/Weight ratio.\n");
}

void findMaximumValue(struct Package p[], int n, float capacity)
{
    int i;
    float remaining = capacity;
    float totalValue = 0;
    float totalWeight = 0;

    for (i = 0; i < n; i++)
    {
        p[i].fraction = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (remaining <= 0)
            break;

        if (p[i].weight <= remaining)
        {
            /* Take complete package */
            p[i].fraction = 1.0;

            remaining -= p[i].weight;
            totalWeight += p[i].weight;
            totalValue += p[i].value;
        }
        else
        {
            /* Take required fraction */
            p[i].fraction = remaining / p[i].weight;

            totalWeight += remaining;
            totalValue += p[i].value * p[i].fraction;

            remaining = 0;
        }
    }

    printf("\n========== MAXIMUM VALUE ==========\n");
    printf("Total weight used : %.2f\n", totalWeight);
    printf("Maximum value     : %.2f\n", totalValue);
    printf("===================================\n");
}

void displaySelectedPackages(struct Package p[], int n)
{
    int i;
    float selectedWeight;
    float selectedValue;

    printf("\n-------------------------------------------------------------\n");
    printf("Package\tFraction\tWeight Used\tValue Obtained\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        if (p[i].fraction > 0)
        {
            selectedWeight = p[i].weight * p[i].fraction;
            selectedValue = p[i].value * p[i].fraction;

            printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
                   p[i].id,
                   p[i].fraction,
                   selectedWeight,
                   selectedValue);
        }
    }

    printf("-------------------------------------------------------------\n");
}

int main()
{
    struct Package p[MAX];

    int n;
    int choice;
    float capacity;

    printf("=============================================\n");
    printf(" SMART DELIVERY PLANNING\n");
    printf(" FRACTIONAL KNAPSACK - GREEDY ALGORITHM\n");
    printf("=============================================\n");

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    do
    {
        printf("\n\n========== MENU ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterPackages(p, n);
                break;

            case 2:
                displayPackages(p, n);
                break;

            case 3:
                calculateRatio(p, n);
                break;

            case 4:
                sortPackages(p, n);
                break;

            case 5:
                findMaximumValue(p, n, capacity);
                break;

            case 6:
                displaySelectedPackages(p, n);
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
