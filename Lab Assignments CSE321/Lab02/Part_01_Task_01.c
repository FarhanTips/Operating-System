

#include <stdio.h>
#include <string.h>

struct Breakfast {
    int quantity;
    float unit_price;
};

int main() {
    struct Breakfast paratha;
    struct Breakfast vegetable;
    struct Breakfast mineral_water;
    
    // paratha specification
    printf("Quantity Of Paratha: ");
    scanf("%d",&paratha.quantity);
    printf("Unit Price: ");
    scanf("%f",&paratha.unit_price);


    // vegetable specification
    printf("Quantity Of Vegetables: ");
    scanf("%d",&vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f",&vegetable.unit_price);
    
    
    // mineral_water specification
    printf("Quantity Of Mineral Water: ");
    scanf("%d",&mineral_water.quantity);
    printf("Unit Price: ");
    scanf("%f",&mineral_water.unit_price);
    
    // number of people input
    int number_people;
    printf("Number of People: ");
    scanf("%d",&number_people);

    // print bill info
    float total_bill = ((paratha.quantity*paratha.unit_price) + (vegetable.quantity*vegetable.unit_price) + (mineral_water.quantity*mineral_water.unit_price));
    
    printf("Total Bill: %.2f tk\n",total_bill);
    printf("Individual people will pay: %.2f tk\n",(total_bill/number_people));

    return 0;
}

